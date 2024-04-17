let className = [%cx
  {|
color: $(Theme.white);
cursor: pointer;
text-decoration-line: underline;
text-decoration-color: $(Theme.blue);
text-decoration-thickness: 2px;

&:hover {
  color: $(Theme.blue);
}
|}
];

[@react.component]
let make = (~children, ~href) => {
  let onClick =
    React.useCallback1(
      event => {
        event |> React.Event.Mouse.preventDefault;
        ReasonReactRouter.push(href);
      },
      [|href|],
    );
  <a className href onClick> children </a>;
};

[@react.component]
let basic = (~href, ~children, ~target=?) => {
  <a className href ?target> children </a>;
};
