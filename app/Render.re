let elementFor = (path: array(string)) => {
  let path = path |> Array.to_list;
  let serverUrl: ReasonReactRouter.url = {path, hash: "", search: ""};
  <Components.App serverUrl />;
};
