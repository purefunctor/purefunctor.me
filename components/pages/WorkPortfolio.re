let sectionCss = [%cx
  {|
margin-top: 2rem;
margin-bottom: 2rem;

& > h2, & > p {
  margin: 0;
}

& a {
  color: $(Theme.white);
  text-decoration-color: $(Theme.blue);
  text-decoration-thickness: 2px;
  &:hover {
    color: $(Theme.blue);
  }
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

[@react.component]
let make = () => {
  portfolio
  |> Array.mapi((key, (title, description, href)) => {
       let key = string_of_int(key);
       <section className=sectionCss key>
         <h2> <a href> {React.string(title)} </a> </h2>
         <p> {React.string(description)} </p>
       </section>;
     })
  |> React.array;
};
