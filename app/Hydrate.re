switch (ReactDOM.querySelector("#root")) {
| Some(root) =>
  let _ = ReactDOM.Client.hydrateRoot(root, <Components.App />);
  ();
| None => ()
};
