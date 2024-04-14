let className =
  "hanken-grotesk-regular "
  ++ [%cx
    {|
display: flex;
flex-direction: column;
gap: 4px;

& > span {
  display: flex;
  align-items: center;
  gap: 4px;
}
|}
  ];
let separatorCss = [%cx "color: $(Theme.mint)"];
let heartIconCss = [%cx "color: $(Theme.pink)"];

[@react.component]
let make = () => {
  <footer className>
    <span>
      {React.string([%mel.raw "\"\\u00A9 2024, Justin Garcia\""])}
    </span>
    <span>
      {React.string("built with ")}
      <Icons.HeartLine className=heartIconCss />
      {React.string("in ReasonML")}
    </span>
  </footer>;
};
