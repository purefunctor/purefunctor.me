[@react.component]
let make = (~children) => {
  <>
    <header> {React.string("Header")} </header>
    children
    <footer> {React.string("Footer")} </footer>
  </>;
};
