let indexCss = [%cx
  {|
display: flex;
align-items: center;
justify-content: center;
|}
];

let containerCss = [%cx
  {|
display: grid;
grid-template-columns: auto auto;
align-items: end;
gap: 2rem;
|}
];

let titleCss =
  "hanken-grotesk-bold "
  ++ [%cx
    {|
display: flex;
flex-direction: column;
font-size: 4rem;
text-align: end;

& > h1 {
  font-size: 1em;
  line-height: 1;
  margin: 0;
}
|}
  ];

let subtitleCss =
  "hanken-grotesk-regular " ++ [%cx {|
font-size: 1rem;
margin: 0;
|}];

let articleCss =
  "hanken-grotesk-regular "
  ++ [%cx
    {|
& > p {
  margin: 0;
}
& > p:not(:last-child) {
  margin-bottom: 1rem;
}
|}
  ];

let paragraphs = [|
  "I am a full-stack software developer from the Philippines who's passionate about functional programming.",
  "I am mostly self-taught and I enjoy teaching myself whatever topics that I find interesting.",
  "This is the third revision of my website! It's currently is built with ReasonML + React.js to exercise my skills in both.",
  "I'm also actively applying for OCaml / ReasonML roles!",
|];

[@react.component]
let make = () => {
  <main className=indexCss>
    <div className=containerCss>
      <header className=titleCss>
        <h1> {React.string("Justin Garcia")} </h1>
        <FramerMotion.p
          initial={"opacity": 0.0, "x": 10}
          animate={"opacity": 1.0, "x": 0}
          transition={"ease": "easeOut", "delay": 0.20}
          className=subtitleCss
          role="doc-subtitle">
          {React.string("Full-Stack Software Developer")}
        </FramerMotion.p>
      </header>
      <article className=articleCss>
        {paragraphs
         |> Array.mapi((index, content) =>
              <p key={string_of_int(index)}> {React.string(content)} </p>
            )
         |> React.array}
      </article>
    </div>
  </main>;
};
