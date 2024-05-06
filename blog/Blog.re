[@react.component]
let make = (~slug) => {
  switch (slug) {
  | [] => <BlogIndex />
  | ["ssr-your-code-blocks"] => <BlogPost.SsrYourCodeBlocks />
  | _ => <NotFound />
  };
};
