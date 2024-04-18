let workCss = [%cx
  {|
font-family: "Hanken Grotesk";

display: flex;
align-items: center;
justify-content: center;

margin-top: 6rem;
margin-bottom: 6rem;
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

[@react.component]
let make = () => {
  <main className=workCss>
    <div className=containerCss>
      <WorkArticle
        title="portfolio" subtitle="a summary of my active projects.">
        <WorkPortfolio />
      </WorkArticle>
      <WorkArticle
        title="experience" subtitle="a summary of my work experience.">
        <WorkExperience />
      </WorkArticle>
    </div>
  </main>;
};
