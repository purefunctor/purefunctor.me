let headerCss = [%cx
  {|
border-bottom: 1px dotted $(Theme.white_60);

& > h1, & > p {
  margin-top: 1rem;
  margin-bottom: 1rem;
}

& > h1 {
  font-size: 3rem;
  line-height: 1;
}
|}
];

[@react.component]
let make = () => {
  <header className=headerCss>
    <h1> {React.string("Justin Garcia")} </h1>
    <p role="doc-subtitle">
      {React.string("Full-Stack Software Developer")}
    </p>
  </header>;
};
