module Items = {
  [@react.component]
  let make = (~items) => {
    <div>
      {items
       |> Array.mapi((key, (title, contents)) => {
            let key = string_of_int(key);
            <React.Fragment key>
              <dt> title </dt>
              {contents
               |> Array.mapi((key, content) => {
                    let key = string_of_int(key);
                    <dd key> content </dd>;
                  })
               |> React.array}
            </React.Fragment>;
          })
       |> React.array}
    </div>;
  };
};

let descriptionListCss = [%cx
  {|
& dt {
  font-weight: 700;
  margin-top: 1rem;
}

& dd {
  margin-top: 0.5rem;
}

& a {
  color: $(Theme.white);
  text-decoration-color: $(Theme.blue);
  text-decoration-thickness: 2px;
  &:hover {
    color: $(Theme.blue);
  }
}

$(Theme.afterSmall) {
  display: grid;
  grid-template-columns: 1fr 1fr;
}
|}
];

[@react.component]
let make = () => {
  let leftItems = [|
    (
      React.string("name"),
      [|React.string("Justin Garcia"), React.string("purefunctor")|],
    ),
    (
      React.string("pronouns"),
      [|
        React.string("he/him"),
        <span lang="fil"> {React.string("siya/kanya")} </span>,
      |],
    ),
    (
      React.string("natural languages"),
      [|
        React.string("Filipino (native tongue)"),
        React.string("English (conversational, technical)"),
      |],
    ),
    (
      React.string("wanting to learn"),
      [|<span lang="ja"> {React.string({js|日本語|js})} </span>|],
    ),
    (
      React.string("music I like"),
      [|
        <a href="https://youtu.be/Nudyk3n7_Ts" target="_blank">
          {React.string("ambient / downtempo")}
        </a>,
        <a href="https://hitnex.bandcamp.com/album/-" target="_blank">
          {React.string("ambient / noisecore")}
        </a>,
        <ProfileIdolMusic />,
      |],
    ),
  |];

  let rightItems = [|
    (
      React.string("things I like"),
      [|
        React.string("rhythm games"),
        React.string("type systems"),
        React.string("reproducible builds"),
        React.string("semantic markup"),
        React.string("physical media"),
      |],
    ),
    (
      React.string("games I like"),
      [|
        React.string("Fire Emblem 4, 7, 8, Engage"),
        React.string("Golden Sun"),
        React.string("Persona 5 Royal"),
        React.string("Shin Megami Tensei V"),
        React.string("Tears of the Kingdom"),
      |],
    ),
    (
      <span lang="ja"> {React.string({js|推し|js})} </span>,
      [|<span lang="ja"> {React.string({js|各務華梨|js})} </span>|],
    ),
  |];

  <dl className=descriptionListCss>
    <Items items=leftItems />
    <Items items=rightItems />
  </dl>;
};
