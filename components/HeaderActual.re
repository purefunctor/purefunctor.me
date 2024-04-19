let headerCss = [%cx
  {|
font-family: "Hanken Grotesk";
display: flex;
font-size: 1.2rem;
align-items: center;
gap: 0.5rem;

& > div {
  position: relative;
  margin-left: auto;
  height: 1.5rem;
  width: 1.5rem;

  & > button {
    height: 100%;
    width: 100%;

    position: absolute;
    z-index: 10000;

    background-color: rgba(0, 0, 0, 0);
    border: 0;
    color: $(Theme.white);
    cursor: pointer;
    padding: 0;
  }
}
|}
];

[@react.component]
let make =
  React.memo((~toggleKind: unit => unit) => {
    <header className=headerCss>
      <Icons.BookLine />
      <Link href="/"> {React.string("Justin Garcia")} </Link>
      <div>
        <button ariaLabel="open navigation screen" onClick={_ => toggleKind()}>
          <Icons.MenuLine size="1.5rem" />
        </button>
      </div>
    </header>
  });
