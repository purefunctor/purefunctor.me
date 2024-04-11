switch (ReactDOM.querySelector("#root")) {
| Some(root) =>
  let root = ReactDOM.Client.createRoot(root);
  let _ = ReactDOM.Client.render(root, <Components.App />);
  ();
| None => ()
};
