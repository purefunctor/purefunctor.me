[@react.component]
let make = () => {
  let (kind, toggleKind) = HeaderState.use();
  <> <HeaderScreen kind toggleKind /> <HeaderActual toggleKind /> </>;
};
