let links = [|
  "https://youtu.be/q99wlpFJlqc",
  "https://youtu.be/XZlDeyBmoPs",
  "https://youtu.be/0_GBo9lEHPM",
  "https://youtu.be/93xTBzw1iKA",
  "https://youtu.be/FxiTjjQ5kqk",
  "https://youtu.be/nKOekzWZH7Y",
  "https://youtu.be/0DYTZaMDS3A",
|];

let getRandomLink = () => {
  let index = Js.Math.random_int(0, Js.Array.length(links));
  Js.Array.unsafe_get(links, index);
};

[@react.component]
let make = () => {
  let (href, setHref) = React.useState(() => Js.Array.unsafe_get(links, 0));
  let onClick = event => {
    React.Event.Mouse.preventDefault(event);
    let _ =
      Webapi.Dom.(
        window
        |> Window.open_(
             ~url=href,
             ~name="_blank",
             ~features="noopener,noreferrer",
           )
      );
    setHref(_ => getRandomLink());
  };
  <a href onClick target="_blank"> {React.string("seiyuu idol music")} </a>;
};
