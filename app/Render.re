let forPath = (path: array(string)) => {
  let path = path |> Array.to_list;
  let serverUrl: ReasonReactRouter.url = {path, hash: "", search: ""};
  ReactDOMServer.renderToString(<Components.App serverUrl />);
};
