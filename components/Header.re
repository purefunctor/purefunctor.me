let className =
  "hanken-grotesk-regular "
  ++ [%cx
    {|
display: flex;
align-items: center;
gap: 0.5rem;
font-size: 1.2rem;
|}
  ];

[@react.component]
let make = () => {
  <header className>
    <Icons.BookLine />
    <Link href="/"> {React.string("Justin Garcia")} </Link>
    <HeaderNav />
  </header>;
};
