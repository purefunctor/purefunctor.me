open BlogPostCore;

module SsrYourCodeBlocks =
  MakePost([%mdx {path: "./mdx/ssr-your-code-blocks.mdx"}]);

let all: array(module MdxPost) = [|(module SsrYourCodeBlocks)|];
