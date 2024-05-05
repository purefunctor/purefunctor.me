[@react.component]
let make = (~slug) => {
  Meta.useMeta(
    ~title="Justin Garcia - Blog",
    ~description="an index of my blog posts",
  );
  switch (slug) {
  | [] => <BlogIndex />
  | ["ssr-your-code-blocks"] => <BlogPost.SsrYourCodeBlocks />
  | _ => <NotFound />
  };
};
