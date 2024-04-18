let indexCss = [%cx
  {|
font-family: "Hanken Grotesk";
margin-top: 6rem;
margin-bottom: 6rem;

$(Theme.afterMedium) {
  display: flex;
  align-items: center;
  justify-content: center;
}
|}
];

let containerCss = [%cx
  {|
$(Theme.afterMedium) {
  display: grid;
  grid-template-areas: "links article" "header article";
  grid-template-rows: 1fr 1fr;
  gap: 2rem;

  & > :nth-child(1) {
    grid-area: header;
    align-self: end;
    border-bottom: 0;
    text-align: right;

    & > h1, & > p {
      margin: 0;
    }

    & > h1 {
      font-size: 4rem;
    }
  }

  & > :nth-child(2) {
    grid-area: article;
    margin: 0;

    & > p:first-child {
      margin-top: 0;
    }

    & > p:last-child {
      margin-bottom: 0;
    }
  }

  & > :nth-child(3) {
    grid-area: links;
    border-top: 0;
    align-items: end;
    justify-content: end;
    padding: 0;
  }
}
|}
];

[@react.component]
let make = () => {
  <main className=indexCss>
    <div className=containerCss>
      <IndexHeader />
      <IndexArticle />
      <IndexLinks />
    </div>
  </main>;
};
