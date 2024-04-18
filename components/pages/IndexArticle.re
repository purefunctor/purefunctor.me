let articleCss = [%cx {|
margin-top: 1rem;
margin-bottom: 1rem;
|}];

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
    {React.string(", ")}
    <Link href="/profile"> {React.string("profile")} </Link>
    {React.string(", and ")}
    <Link href="/blog"> {React.string("blog")} </Link>
    {React.string(" pages.")}
  </>,
|];

[@react.component]
let make = () => {
  <article className=articleCss>
    {paragraphs
     |> Array.mapi((index, content) =>
          <p key={string_of_int(index)}> content </p>
        )
     |> React.array}
  </article>;
};
