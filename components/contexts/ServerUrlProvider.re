let context: React.Context.t(Js.Nullable.t(ReasonReactRouter.url)) =
  React.createContext(Js.Nullable.null);

include React.Context;
let make = React.Context.provider(context);

let useUrl = () => {
  let serverUrl = React.useContext(context) |> Js.Nullable.toOption;
  ReasonReactRouter.useUrl(~serverUrl?, ());
};
