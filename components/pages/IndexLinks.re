let navCss = [%cx
  {|
display: flex;
justify-content: center;
gap: 0.5rem;

border-top: 1px dotted $(Theme.white_60);
padding-top: 1rem;
padding-bottom: 1rem;
|}
];

[@react.component]
let make = () => {
  <nav className=navCss>
    <Link.basic href="mailto:purefunctor@gmail.com">
      {React.string("Email")}
    </Link.basic>
    <Link.basic href="https://twitter.com/purefunctor">
      {React.string("Twitter")}
    </Link.basic>
    <Link.basic href="https://github.com/purefunctor">
      {React.string("GitHub")}
    </Link.basic>
    <Link.basic href="https://linkedin.com/in/justin-garcia-pf">
      {React.string("LinkedIn")}
    </Link.basic>
  </nav>;
};
