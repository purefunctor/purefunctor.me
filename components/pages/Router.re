[@react.component]
let make = () => {
  let url = ReasonReactRouter.useUrl();
  switch (url.path) {
  | [] => <Index />
  | ["work"] => <Work />
  | ["profile"] => <Profile />
  | _ => <NotFound />
  };
};
