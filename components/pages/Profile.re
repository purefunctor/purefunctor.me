let profileCss = [%cx
  {|
display: flex;
align-items: center;
justify-content: stretch;
padding-top: 3rem;
padding-bottom: 3rem;
font-family: "Hanken Grotesk";
|}
];

let aboutMeCss = [%cx
  {|
flex-grow: 1;

& > h1 {
  grid-area: title;
  font-size: 3rem;
  border-bottom: 1px dotted $(Theme.white_60);
  margin: 0;
}

& > dl {
  display: grid;
  grid-template-columns: 1fr;
  gap: 1rem;
}

& > dl dt {
  font-weight: 700;
  margin-bottom: 0.5rem;
  &:not(:first-child) {
    margin-top: 1rem;
  }
}

& > dl dd {
  margin-left: 2rem;
  & > a {
    color: $(Theme.white);
    text-decoration-color: $(Theme.blue);
    text-decoration-thickness: 2px;
    &:hover {
      color: $(Theme.blue);
    }
  }
}

$(Theme.afterMedium) {
  & > dl {
    display: grid;
    grid-template-columns: 1fr 1fr;
  }
}
|}
];

let seiyuuIdolMusic = [|
  "https://youtu.be/XZlDeyBmoPs",
  "https://youtu.be/q99wlpFJlqc",
  "https://youtu.be/0_GBo9lEHPM",
  "https://youtu.be/93xTBzw1iKA",
  "https://youtu.be/FxiTjjQ5kqk",
  "https://youtu.be/nKOekzWZH7Y",
  "https://youtu.be/0DYTZaMDS3A",
|];

module RandomLink = {
  [@react.component]
  let make = (~choices, ~children) => {
    let getRandomIndex = () =>
      Js.Math.random_int(0, Js.Array.length(choices));

    let (index, setIndex) = React.useState(() => getRandomIndex());

    let href = Js.Array.unsafe_get(choices, index);
    let onClick = React.useCallback0(_ => {setIndex(_ => getRandomIndex())});

    <a href onClick target="_blank"> children </a>;
  };
};

[@react.component]
let make = () => {
  <main className=profileCss>
    <article className=aboutMeCss>
      <h1> {React.string("about me")} </h1>
      <dl>
        <div>
          <dt> {React.string("name")} </dt>
          <dd> {React.string("Justin Garcia")} </dd>
          <dd> {React.string("purefunctor")} </dd>
          <dt> {React.string("pronouns")} </dt>
          <dd> {React.string("he/him")} </dd>
          <dt> {React.string("natural languages")} </dt>
          <dd> {React.string("Filipino (native)")} </dd>
          <dd> {React.string("English (conversational, technical)")} </dd>
          <dt> {React.string("wanting to learn")} </dt>
          <dd>
            <span lang="ja">
              {React.string([%mel.raw "\"日本語\""])}
            </span>
          </dd>
          <dt> {React.string("music I like")} </dt>
          <dd>
            <a href="https://youtu.be/Nudyk3n7_Ts" target="_blank">
              {React.string("ambient / downtempo")}
            </a>
          </dd>
          <dd>
            <a href="https://hitnex.bandcamp.com/album/-" target="_blank">
              {React.string("ambient / noisecore")}
            </a>
          </dd>
          <dd>
            <RandomLink choices=seiyuuIdolMusic>
              {React.string("seiyuu idol music")}
            </RandomLink>
          </dd>
        </div>
        <div>
          <dt> {React.string("things I like")} </dt>
          <dd> {React.string("rhythm games")} </dd>
          <dd> {React.string("type systems")} </dd>
          <dd> {React.string("reproducible builds")} </dd>
          <dd> {React.string("semantic markup")} </dd>
          <dd> {React.string("physical media")} </dd>
          <dt> {React.string("games I like")} </dt>
          <dd> {React.string("Golden Sun")} </dd>
          <dd> {React.string("Persona 5 Royal")} </dd>
          <dd> {React.string("Tears of the Kingdom")} </dd>
          <dd> {React.string("Shin Megami Tensei V")} </dd>
          <dt>
            <span lang="ja"> {React.string([%mel.raw "\"推し\""])} </span>
          </dt>
          <dd>
            <span lang="ja">
              {React.string([%mel.raw "\"各務華梨\""])}
            </span>
          </dd>
        </div>
      </dl>
    </article>
  </main>;
};
