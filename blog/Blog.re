[@react.component]
let make = (~slug) => {
  switch (slug) {
  | [] => <BlogIndex />
  | ["hello"] => <BlogPost.Hello />
  | ["ssr-your-code-blocks"] => <BlogPost.SsrYourCodeBlocks />
  | _ => <NotFound />
  };
};
