module type T = {
  let slug: array(string);
  let title: string;
  let description: string;

  [@react.component]
  let make: unit => React.element;
};

let mainCss = [%cx
  {|
font-family: "Hanken Grotesk";
margin-top: 6rem;
margin-bottom: 6rem;

& > h1 {
  border-bottom: 1px dotted $(Theme.white_60);
  font-size: 3rem;
  margin: 0;
}
|}
];

module Make = (T: T) : T => {
  let slug = T.slug;
  let title = T.title;
  let description = T.description;

  [@react.component]
  let make = () => {
    <main className=mainCss> <T /> </main>;
  };
};

module Hello =
  Make({
    let slug = [|"hello"|];

    [@mel.module "./mdx/hello.mdx"] external title: string = "title";

    [@mel.module "./mdx/hello.mdx"]
    external description: string = "description";

    [@react.component] [@mel.module "./mdx/hello.mdx"]
    external make: unit => React.element = "default";
  });

let all: array(module T) = [|(module Hello)|];
