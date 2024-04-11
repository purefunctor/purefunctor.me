let className = [%cx
  {|
margin-left: auto;
display: flex;
align-items: center;
gap: 1rem;
|}
];

[@react.component]
let make = () => {
  <nav className>
    <Link href="/work"> {React.string("Work")} </Link>
    <Link href="/profile"> {React.string("Profile")} </Link>
  </nav>;
};
