let titleCss = "hanken-grotesk-bold";
let subtitleCss = "hanken-grotesk-regular";
let articleCss = "hanken-grotesk-regular";
let navCss = "hanken-grotesk-regular";

let mainCss = [%cx
  {|
display: flex;
align-items: center;
justify-content: center;

padding-left: 3rem;
padding-right: 3rem;

$(Theme.afterMedium) {
  padding-left: 0;
  padding-right: 0;
}
|}
];

let containerCss = [%cx
  {|
display: flex;
flex-direction: column;

& > header {
  display: flex;
  flex-direction: column;
  font-size: 2rem;
  padding-bottom: 2rem;

  & > h1 {
    font-size: 1em;
    line-height: 1;
    margin: 0;
  }

  & > p {
    font-size: 1rem;
    margin: 0;
  }
}

& > article {
  border-width: 2px 0 2px 0;
  border-style: dotted;
  border-color: $(Theme.white_60);
  padding-top: 2rem;
  padding-bottom: 2rem;

  & > p {
    margin: 0;
  }
  & > p:not(:last-child) {
    margin-bottom: 1rem;
  }
}

& > nav {
  display: flex;
  align-items: end;
  justify-content: center;
  gap: 8px;
  padding-top: 2rem;

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
  display: grid;
  grid-template-rows: 1fr 1fr;
  grid-template-areas: "links article" "header article";
  gap: 2rem;

  & > header {
    grid-area: header;
    justify-content: end;
    font-size: 4rem;
    text-align: end;
    padding-bottom: 0;
  }

  & > article {
    grid-area: article;
    padding-top: 0;
    padding-bottom: 0;
    border-width: 0;

    display: flex;
    flex-direction: column;
    justify-content: end;
  }

  & > nav {
    grid-area: links;
    padding-top: 0;
    justify-content: end;
  }
}
|}
];

let paragraphs = [|
  React.string(
    "I am a full-stack software developer from the Philippines who's passionate about functional programming.",
  ),
  React.string(
    "I am mostly self-taught and I enjoy teaching myself whatever topics that I find interesting.",
  ),
  React.string(
    "This is the third revision of my website! It's currently is built with ReasonML + React.js to exercise my skills in both.",
  ),
  React.string("I'm also actively applying for OCaml / ReasonML roles!"),
  <>
    {React.string("You can read more in my ")}
    <Link href="/work"> {React.string("portfolio")} </Link>
    {React.string(" and ")}
    <Link href="/profile"> {React.string("profile")} </Link>
    {React.string(" pages.")}
  </>,
|];

[@react.component]
let make = () => {
  <main className=mainCss>
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
              <p key={string_of_int(index)}> content </p>
            )
         |> React.array}
      </article>
      <nav className=navCss>
        <a href="mailto:purefunctor@gmail.com"> {React.string("Email")} </a>
        <a href="https://twitter.com/purefunctor">
          {React.string("Twitter")}
        </a>
        <a href="https://github.com/purefunctor">
          {React.string("GitHub")}
        </a>
        <a href="https://linkedin.com/in/justin-garcia-pf">
          {React.string("LinkedIn")}
        </a>
      </nav>
    </div>
  </main>;
};
