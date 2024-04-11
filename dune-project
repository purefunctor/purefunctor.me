(lang dune 3.14)
(using melange 0.1)

(name website)

(generate_opam_files true)

(source
 (github purefunctor/purefunctor.me))

(authors "Justin Garcia")

(maintainers "Justin Garcia")

(license BSD-3-Clause)

(package
 (allow_empty)
 (name website)
 (synopsis "My personal website")
 (description "My personal website.")
 (depends 
  ocaml 
  (dune
   (>= "3.14"))
  (ocaml-lsp-server
   (and :with-test
    (>= "1.17.0")))
  (ocamlformat
   (and :with-test
    (>= "0.26.1")))
  (melange
   (>= "3.0.0-51"))
  (reason 
   (>= "3.11.0"))
  (reason-react
   (>= "0.14.0"))
  styled-ppx))
