[%styled.global
  {|
  body {
    background-color: $(Theme.black);
    color: $(Theme.white);
    margin: 0;
    padding: 0;
  }

  #root {
    display: flex;
    flex-direction: column;
    box-sizing: border-box;
    padding: 1rem;
    min-height: 100vh;
  }

  #root > :nth-child(2) {
    flex-grow: 1;
  }

  @media screen and $(Theme.medium) {
    #root {
      max-width: $(Theme.maxWidth);
      margin-left: auto;
      margin-right: auto;
    }
  }
|}
];

[@react.component]
let make = (~serverUrl=?) => {
  <ServerUrlProvider value={serverUrl |> Js.Nullable.fromOption}>
    <Layout> <Router /> </Layout>
  </ServerUrlProvider>;
};
