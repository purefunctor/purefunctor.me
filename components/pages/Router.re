[@react.component]
let make = () => {
  let url = ServerUrlProvider.useUrl();
  switch (url.path) {
  | [] => <Index />
  | ["work"] => <Work />
  | ["profile"] => <Profile />
  | ["blog", ...slug] => <Blog slug />
  | _ => <NotFound />
  };
};
