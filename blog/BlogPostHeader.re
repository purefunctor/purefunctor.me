open Mdx_ppx_runtime;

let subtitleCss = [%cx
  {|
& > p {
  color: $(Theme.white_20);
  font-size: 1.1rem;
  margin: 0;
}
|}
];

let dlCss = [%cx
  {|
display: grid;
grid-template-columns: auto auto auto;
gap: 1.5rem 1rem;

margin-top: 3rem;
padding-top: 1rem;
padding-bottom: 1rem;
border-top: 1px dotted $(Theme.white_60);
border-bottom: 1px dotted $(Theme.white_60);

& dt {
  font-weight: 700;
  margin-bottom: 0.5rem;
}

& dd {
  margin: 0;
}
|}
];

let printDate: Js.Date.t => string = [%mel.raw
  {|
(date) => {
  return date.toLocaleString("fil",
    { month: "long", day: "numeric", year: "numeric" }
  );
}
|}
];

[@react.component]
let make =
    (
      ~title: string,
      ~description: string,
      ~published: Js.Date.t,
      ~readingTime: readingTime,
    ) => {
  <>
    <h1> {React.string(title)} </h1>
    <div className=subtitleCss> <p> {React.string(description)} </p> </div>
    <dl className=dlCss>
      <div>
        <dt> {React.string("publication date")} </dt>
        <dd>
          <time lang="fil"> {React.string(published |> printDate)} </time>
        </dd>
      </div>
      <div>
        <dt> {React.string("reading time")} </dt>
        <dd> {React.string(readingTime.text)} </dd>
      </div>
      <div>
        <dt> {React.string("word count")} </dt>
        <dd> {React.string(readingTime.words |> string_of_int)} </dd>
      </div>
      <div>
        <dt> {React.string("license")} </dt>
        <dd>
          <Link.basic
            href="https://creativecommons.org/licenses/by-nc-sa/4.0/legalcode">
            {React.string("CC BY-NC-SA 4.0")}
          </Link.basic>
        </dd>
      </div>
    </dl>
  </>;
};
