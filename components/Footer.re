let className = "hanken-grotesk-regular";

[@react.component]
let make = () => {
  <footer className>
    <span className=[%cx "display: flex; align-items: center; gap: 4px;"]>
      {React.string("built with ")}
      <Icons.HeartLine className=[%cx "color: $(Theme.pink)"] />
      {React.string("in ReasonML")}
    </span>
  </footer>;
};
