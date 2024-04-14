let workCss = [%cx
  {|
display: flex;
align-items: center;
justify-content: center;
font-family: "Hanken Grotesk";
padding-top: 3rem;
padding-bottom: 3rem;
|}
];

let containerCss = [%cx
  {|
display: grid;
flex-grow: 1;

$(Theme.afterSmall) {
  gap: 2rem;
  grid-template-columns: 1fr 1fr;
}
|}
];

let portfolioCss = [%cx
  {|
margin-bottom: 3rem;

& p {
  font-weight: 300;
  margin: 0;
}

& > header {
  margin-bottom: 3rem;
  & > h1 {
    border-bottom: 1px dotted $(Theme.white_60);
    font-size: 3rem;
    margin: 0;
  }
  & > p {
    margin-top: 1rem;
  }
}

& > section:not(:last-child) {
  margin-bottom: 1.5rem;
}

& > section {
  & > h2 {
    font-size: 1.5rem;
    margin: 0;
    & > a {
      color: $(Theme.white);
      text-decoration-color: $(Theme.blue);
      text-decoration-thickness: 2px;
      &:hover {
        color: $(Theme.blue);
      }
    }
  }
}

$(Theme.afterSmall) {
  border: none;
  padding: 0;
}
|}
];

let portfolio = [|
  (
    "purefunctor.me",
    "personal website and blog, this website.",
    "https://github.com/purefunctor/purefunctor.me",
  ),
  (
    "sabihin.ph",
    "anonymous and end-to-end encrypted q&a platform.",
    "https://github.com/purefunctor/sabihin",
  ),
  (
    "purescript-analyzer",
    "compiler frontend and editor tooling for PureScript.",
    "https://github.com/purefunctor/purescript-analyzer",
  ),
|];

let experience = [|
  ("Meeshkan Oy", "2022 - 2024", "Freelance Software Developer"),
  ("PureScript", "2022 - Present", "Core Team Member"),
  ("OSSPH", "2023 - Present", "Community Lead"),
|];

[@react.component]
let make = () => {
  <main className=workCss>
    <div className=containerCss>
      <article className=portfolioCss>
        <header>
          <h1> {React.string("portfolio")} </h1>
          <p role="doc-subtitle">
            {React.string("a summary of my active projects.")}
          </p>
        </header>
        {portfolio
         |> Array.mapi((key, (name, content, link)) => {
              let key = string_of_int(key);
              <section key>
                <h2> <a href=link> {React.string(name)} </a> </h2>
                <p role="doc-subtitle"> {React.string(content)} </p>
              </section>;
            })
         |> React.array}
      </article>
      <article className=portfolioCss>
        <header>
          <h1> {React.string("experience")} </h1>
          <p role="doc-subtitle">
            {React.string("a summary of my work experience.")}
          </p>
        </header>
        {experience
         |> Array.mapi((key, (name, period, role)) => {
              let key = string_of_int(key);
              <section key>
                <h2> {React.string(name)} </h2>
                <p role="doc-subtitle"> {React.string(period)} </p>
                <p role="doc-subtitle"> {React.string(role)} </p>
              </section>;
            })
         |> React.array}
      </article>
    </div>
  </main>;
};
