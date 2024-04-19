open Ppxlib

let mdx ~loc path =
  let open Ast_helper in
  let slug_value_binding =
    let slug =
      path |> Filename.basename |> Filename.remove_extension |> Const.string
      |> Exp.constant
    in
    Str.value Nonrecursive
      [ Vb.mk (Pat.var { loc; txt = "slug" }) (Exp.array [ slug ]) ]
  in
  let mel_module_path_attr =
    Attr.mk
      { loc; txt = "mel.module" }
      (PStr [ Str.eval (Exp.constant (Const.string path)) ])
  in
  let make_external n t =
    Str.primitive
      (Val.mk ~attrs:[ mel_module_path_attr ] ~prim:[ n ] { loc; txt = n } t)
  in
  let component =
    Str.primitive
      (Val.mk
         ~attrs:
           [
             mel_module_path_attr;
             Attr.mk { loc; txt = "react.component" } (PStr []);
           ]
         ~prim:[ "default" ] { loc; txt = "make" }
         [%type: ?components:Mdx_ppx_runtime.components -> React.element])
  in
  Mod.structure ~loc
    [
      slug_value_binding;
      make_external "title" [%type: string];
      make_external "description" [%type: string];
      make_external "published" [%type: Js.Date.t];
      make_external "readingTime" [%type: Mdx_ppx_runtime.readingTime];
      component;
    ]

let extension =
  Extension.V3.declare "mdx" Extension.Context.module_expr
    Ast_pattern.(
      single_expr_payload (pexp_record (pair __ (estring __) ^:: nil) none))
  @@ fun ~ctxt path_key path_value ->
  let loc = Expansion_context.Extension.extension_point_loc ctxt in
  match path_key with
  | { txt = Lident "path"; _ } -> mdx ~loc path_value
  | { loc; _ } -> Location.raise_errorf ~loc "mdx_ppx: expected \"path\""

let rule = Context_free.Rule.extension extension
let () = Driver.V2.register_transformation "mdx" ~rules:[ rule ]
