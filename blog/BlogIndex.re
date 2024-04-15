let entryCss = [%cx
  {|
margin-top: 3rem;
margin-bottom: 3rem;

& > h2 {
  font-size: 1.5rem;
  margin: 0;
}
|}
];

module Entry = {
  [@react.component]
  let make = (~post: (module BlogPost.T)) => {
    let (module Post) = post;

    let href =
      [|"/blog"|]
      |> Js.Array.concat(~other=Post.slug)
      |> Js.Array.join(~sep="/");

    <section className=entryCss>
      <h2> <Link href> {React.string(Post.title)} </Link> </h2>
      <p> {React.string(Post.description)} </p>
    </section>;
  };
};

let mainCss = [%cx
  {|
font-family: "Hanken Grotesk";
margin-top: 6rem;
margin-bottom: 6rem;

& > header > h1 {
  border-bottom: 1px dotted $(Theme.white_60);
  font-size: 3rem;
  margin: 0;
}
|}
];

[@react.component]
let make = () => {
  <main className=mainCss>
    <header>
      <h1> {React.string("blog")} </h1>
      <p> {React.string("Thoughts about whatever I find interesting.")} </p>
    </header>
    {BlogPost.all
     |> Array.mapi((key, post) => {
          let key = string_of_int(key);
          <Entry key post />;
        })
     |> React.array}
  </main>;
};
