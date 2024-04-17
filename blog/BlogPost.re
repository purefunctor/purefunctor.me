open BlogPostCore;

module Hello =
  Make({
    let slug = [|"hello"|];

    [@mel.module "./mdx/hello.mdx"] external title: string = "title";

    [@mel.module "./mdx/hello.mdx"]
    external description: string = "description";

    [@react.component] [@mel.module "./mdx/hello.mdx"]
    external make:
      (~components: customComponents('code, 'pre)) => React.element =
      "default";
  });

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
  (module Hello),
  (module SsrYourCodeBlocks),
|];
