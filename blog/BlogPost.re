open BlogPostCore;

module AndAllThatCouldHaveBeen =
  MakePost([%mdx {path: "./mdx/and-all-that-could-have-been.mdx"}]);

module SsrYourCodeBlocks =
  MakePost([%mdx {path: "./mdx/ssr-your-code-blocks.mdx"}]);

let all: array(module MdxPost) = [|
  (module AndAllThatCouldHaveBeen),
  (module SsrYourCodeBlocks),
|];
