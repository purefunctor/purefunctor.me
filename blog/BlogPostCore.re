type customComponents('code, 'pre) = {
  code:
    (
      {
        ..
        "className": option(string),
        "children": option(string),
      } as 'code
    ) =>
    React.element,
  pre: ({.. "children": React.element} as 'pre) => React.element,
};

module type MdxModule = {
  let slug: array(string);
  let title: string;
  let description: string;

  [@react.component]
  let make: (~components: customComponents('code, 'pre)) => React.element;
};

module type MdxPost = {
  include MdxModule;

  [@react.component]
  let make: unit => React.element;
};

[@mel.module "css.escape"] external cssEscape: string => string = "default";

module CustomCode = {
  type kind =
    | HasLanguage(string, string)
    | NoLanguage;

  let inferKind = className => {
    let languageCaptures =
      Option.bind(className, className => {
        [%re "/language-(\\w+)/"]
        |> Js.Re.exec(~str=className)
        |> Option.map(Js.Re.captures)
      });

    let languageName =
      Option.bind(
        languageCaptures,
        languageCaptures => {
          let languageName = Array.unsafe_get(languageCaptures, 1);
          Js.Nullable.toOption(languageName);
        },
      );

    switch (className, languageName) {
    | (Some(className), Some(languageName)) =>
      HasLanguage(className, languageName)
    | _ => NoLanguage
    };
  };

  let divCss = [%cx {| overflow: auto; padding: 1rem; |}];

  let exists = (~id, ~className, ~languageName, ~innerHTML) => {
    <>
      <small> {React.string(languageName)} </small>
      <div className=divCss>
        <code id className dangerouslySetInnerHTML={"__html": innerHTML} />
      </div>
    </>;
  };

  let create = (~id, ~className, ~languageName, ~children) => {
    let innerHTML = Hljs.highlight(children, {language: languageName}).value;
    exists(~id, ~className, ~languageName, ~innerHTML);
  };

  let inline = (~id, ~children) => {
    <code id> {React.string(children)} </code>;
  };

  [@react.component]
  let make = (~className=?, ~children="") => {
    let id = React.useId();
    let kind = inferKind(className);

    switch (kind) {
    | HasLanguage(className, languageName) =>
      let document = [%mel.external document];
      let innerHTML =
        Option.bind(
          document,
          document => {
            let escaped = "#" ++ cssEscape(id);
            document
            |> Webapi.Dom.Document.querySelector(escaped)
            |> Option.map(Webapi.Dom.Element.innerHTML);
          },
        );
      switch (innerHTML) {
      | Some(innerHTML) => exists(~id, ~className, ~languageName, ~innerHTML)
      | None => create(~id, ~className, ~languageName, ~children)
      };
    | NoLanguage => inline(~id, ~children)
    };
  };
};

module CustomPre = {
  let preClass = [%cx
    {|
font-size: 1rem;
position: relative;
border: 2px solid $(Theme.white_60);

& > small {
  background-color: $(Theme.black);
  position: absolute;
  top: 0;
  right: 0;
  padding: 0.5rem;
}
|}
  ];

  [@react.component]
  let make = (~children) => {
    <pre className={"hljs " ++ preClass}> children </pre>;
  };
};

let mainCss = [%cx
  {|
font-family: "Hanken Grotesk";
margin-top: 6rem;
margin-bottom: 6rem;

& > h1, & > h2, & > h3, & > p {
  &:first-child {
    margin-top: 0;
  }
}

& > h1 {
  border-bottom: 1px dotted $(Theme.white_60);
  font-size: 3rem;
  margin: 3rem 0 0 0;
}

& > h2 {
  font-size: 2rem;
  margin: 3rem 0 0 0;
}

& > h3 {
  font-size: 1.5rem;
  margin: 3rem 0 0 0;
}

& p {
  font-size: 1.1rem;
  line-height: 1.6;
  margin: 1rem 0 1rem 0;
}

& a {
  color: $(Theme.white);
  cursor: pointer;
  text-decoration-line: underline;
  text-decoration-color: $(Theme.blue);
  text-decoration-thickness: 2px;

  &:hover {
    color: $(Theme.blue);
  }
}

& li {
  font-size: 1.1rem;
  line-height: 1.6;
}
|}
];

module Make = (MdxModule: MdxModule) : MdxPost => {
  let slug = MdxModule.slug;
  let title = MdxModule.title;
  let description = MdxModule.description;

  [@react.component]
  let make = () => {
    <main className=mainCss>
      <MdxModule components={code: CustomCode.make, pre: CustomPre.make} />
    </main>;
  };
};
