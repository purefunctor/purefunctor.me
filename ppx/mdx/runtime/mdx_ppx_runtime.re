type readingTime = {
  text: string,
  words: int,
};

type components = {
  code:
    React.componentLike(
      {
        .
        "className": option(string),
        "children": option(string),
      },
      React.element,
    ),
  pre: React.componentLike({. "children": React.element}, React.element),
};

module type MdxMeta = {
  let slug: array(string);
  let title: string;
  let description: string;
  let published: Js.Date.t;
  let readingTime: readingTime;
};

module type MdxRaw = {
  include MdxMeta;

  [@react.component]
  let make: (~components: components=?) => React.element;
};
