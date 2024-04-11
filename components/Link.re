let className = [%cx
  {|
color: $(Theme.white);
cursor: pointer;
text-decoration: none;

&:hover {
  text-decoration: underline;
  text-decoration-color: $(Theme.mint);
  text-decoration-thickness: 2px;
}
|}
];

[@react.component]
let make = (~children, ~href) => {
  <a className href> children </a>;
};
