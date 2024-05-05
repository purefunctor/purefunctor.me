module Main = [%styled.main
  {|
font-family: "Hanken Grotesk";
margin-top: 6rem;
margin-bottom: 6rem;

& > h1 {
  font-size: 3rem;
  margin: 0;
  border-bottom: 1px dotted $(Theme.white_60);
}
|}
];

[@react.component]
let make = () => {
  Meta.useMeta(
    ~title="Justin Garcia - Not Found",
    ~description="looks like there's nothing here",
  );
  <Main>
    <h1> {React.string("looks like there's nothing here...")} </h1>
    <p>
      {React.string("You can go to ")}
      <Link href="/"> {React.string("home")} </Link>
      {React.string(" page or the ")}
      <Link href="/blog"> {React.string("blog")} </Link>
      {React.string(" index. ")}
    </p>
    <p>
      {React.string("If you think this is a bug, you can report it ")}
      <Link.basic
        href="https://github.com/purefunctor/purefunctor.me/" target="_blank">
        {React.string("here")}
      </Link.basic>
      {React.string(".")}
    </p>
  </Main>;
};
