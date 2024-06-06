[@react.component]
let make = (~slug) => {
  switch (slug) {
  | [] => <BlogIndex />
  | ["and-all-that-could-have-been"] => <BlogPost.AndAllThatCouldHaveBeen />
  | ["ssr-your-code-blocks"] => <BlogPost.SsrYourCodeBlocks />
  | _ => <NotFound />
  };
};
