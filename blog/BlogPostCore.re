type customComponents('code, 'pre) = {
  code:
    (
      {
        ..
        "className": string,
        "children": string,
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
  let extractLanguageName = className => {
    let languageCaptures =
      [%re "/language-(\\w+)/"]
      |> Js.Re.exec(~str=className)
      |> Option.map(Js.Re.captures);

    Option.bind(
      languageCaptures,
      languageCaptures => {
        let languageName = Array.unsafe_get(languageCaptures, 1);
        Js.Nullable.toOption(languageName);
      },
    )
    |> Option.value(~default="text");
  };

  let render = (~id, ~className, ~languageName, ~children) => {
    let innerHTML = Hljs.highlight(children, {language: languageName}).value;
    <>
      <code id className dangerouslySetInnerHTML={"__html": innerHTML} />
      <small> {React.string(languageName)} </small>
    </>;
  };

  [@react.component]
  let make = (~className, ~children) => {
    let languageName = extractLanguageName(className);
    let id = React.useId();

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
    | Some(innerHTML) =>
      <>
        <code id className dangerouslySetInnerHTML={"__html": innerHTML} />
        <small> {React.string(languageName)} </small>
      </>
    | None => render(~id, ~className, ~languageName, ~children)
    };
  };
};

module CustomPre = {
  let preClass = [%cx
    {|
font-size: 1rem;
position: relative;
padding: calc(1rem - 2px);
border: 2px solid $(Theme.white_60);

& > small {
  background-color: $(Theme.black);
  position: absolute;
  top: 0;
  right: 0;
  padding: 1rem;
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
  margin: 2rem 0 0 0;
}

& > h3 {
  font-size: 1.5rem;
  margin: 2rem 0 0 0;
}

& > p {
  margin: 1rem 0 1rem 0;
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
