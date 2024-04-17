open BlogPostCore;

module SsrYourCodeBlocks =
  Make({
    let slug = [|"ssr-your-code-blocks"|];
    [@mel.module "./mdx/ssr-your-code-blocks.mdx"] external title: string = "title";

    [@mel.module "./mdx/ssr-your-code-blocks.mdx"]
    external description: string = "description";

    [@react.component] [@mel.module "./mdx/ssr-your-code-blocks.mdx"]
    external make:
      (~components: customComponents('code, 'pre)) => React.element =
      "default";
  });

let all: array(module MdxPost) = [|
  (module SsrYourCodeBlocks),
|];
