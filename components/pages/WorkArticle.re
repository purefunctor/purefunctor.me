let headerCss = [%cx
  {|
& > p {
  margin: 1rem 0 0 0;
}

& > h1 {
  border-bottom: 1px dotted $(Theme.white_60);
  font-size: 3rem;
  margin: 0;
}
|}
];

[@react.component]
let make = (~title, ~subtitle, ~children) => {
  <article>
    <header className=headerCss>
      <h1> {React.string(title)} </h1>
      <p> {React.string(subtitle)} </p>
    </header>
    children
  </article>;
};
