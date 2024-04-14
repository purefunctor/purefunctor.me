let profileCss = [%cx
  {|
font-family: "Hanken Grotesk";

display: flex;
align-items: center;
justify-content: center;

padding-top: 3rem;
padding-bottom: 3rem;
|}
];

let articleCss = [%cx
  {|
flex-grow: 1;

& > header  {
  border-bottom: 1px dotted $(Theme.white_60);
  & > h1 {
    font-size: 3rem;
    margin: 0;
  }
}
|}
];

[@react.component]
let make = () => {
  <main className=profileCss>
    <article className=articleCss>
      <header> <h1> {React.string("about me")} </h1> </header>
      <ProfileDescriptions />
    </article>
  </main>;
};
