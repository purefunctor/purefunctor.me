[@react.component]
let make = () => {
  let url = ServerUrlProvider.useUrl();
  switch (url.path) {
  | [] => <Index />
  | ["work"] => <Work />
  | ["profile"] => <Profile />
  | ["blog", ...slug] => <Blog slug />
  | ["404"]
  | _ => <NotFound />
  };
};
