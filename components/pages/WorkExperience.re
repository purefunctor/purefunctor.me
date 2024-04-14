let sectionCss = [%cx
  {|
margin-top: 2rem;
margin-bottom: 2rem;

& > p {
  margin: 0;
}

& > h2 {
  margin: 0;
}
|}
];

type period =
  | Inactive(string, string)
  | Active(string);

let experience = [|
  ("Meeshkan Oy", "Freelance Software Developer", Inactive("2022", "2024")),
  ("PureScript", "Core Team Member", Active("2022")),
  ("OSSPH", "Community Lead", Active("2023")),
|];

[@react.component]
let make = () => {
  experience
  |> Array.mapi((key, (name, role, period)) => {
       let key = string_of_int(key);
       <section className=sectionCss key>
         <h2> {React.string(name)} </h2>
         <p> {React.string(role)} </p>
         {switch (period) {
          | Inactive(start, finish) =>
            <p>
              <time dateTime=start> {React.string(start)} </time>
              {React.string("-")}
              <time dateTime=finish> {React.string(finish)} </time>
            </p>
          | Active(start) =>
            <p>
              <time dateTime=start> {React.string(start)} </time>
              {React.string("-Present")}
            </p>
          }}
       </section>;
     })
  |> React.array;
};
