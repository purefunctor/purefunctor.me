let divCss = [%cx
  {|
font-family: "Hanken Grotesk";
font-weight: 700;
background-color: rgb(12, 12, 12);
position: fixed;
z-index: 9999;

top: 0;
left: 0;
right: 0;
bottom: 0;

display: flex;
align-items: center;
justify-content: center;
  |}
];

let divVariants = {
  "open": {
    "backgroundColor": "rgb(12, 12, 12, 0.98)",
    "visibility": "visible",
    "transition": {
      "ease": "easeOut",
      "staggerChildren": 0.08,
      "when": "beforeChildren",
    },
  },
  "close": {
    "backgroundColor": "rgb(12, 12, 12, 0.0)",
    "visibility": "hidden",
    "transition": {
      "ease": "easeOut",
      "backgroundColor": {
        "duration": 0.16,
      },
      "visibility": {
        "delay": 0.16,
      },
      "staggerChildren": 0.08,
      "staggerDirection": (-1),
      "when": "afterChildren",
    },
  },
};

let navCss = [%cx
  {|
text-align: center;
font-size: 4rem;

& > ul {
  line-height: 2;
  padding: 0;
  margin: 0;
  list-style: none;
}
|}
];

let liVariants = {
  "open": {
    "y": 0,
    "opacity": 1.0,
    "transition": {
      "ease": "easeOut",
    },
  },
  "close": {
    "y": 100,
    "opacity": 0.0,
    "transition": {
      "ease": "easeOut",
    },
  },
};

module ScreenLink = {
  let className =
    Link.className ++ " " ++ [%cx {|
text-decoration-thickness: 4px;
|}];

  [@react.component]
  let make = (~href, ~children, ~toggleKind) => {
    let onClick =
      React.useCallback1(
        event => {
          React.Event.Mouse.preventDefault(event);
          ReasonReactRouter.push(href);
          toggleKind();
        },
        [|href|],
      );
    <a className onClick href> children </a>;
  };
};

module ScreenLinks = {
  [@react.component]
  let make =
    React.memo((~toggleKind) => {
      <nav className=navCss>
        <ul>
          <FramerMotion.li variants=liVariants>
            <ScreenLink href="/" toggleKind>
              {React.string("Home")}
            </ScreenLink>
          </FramerMotion.li>
          <FramerMotion.li variants=liVariants>
            <ScreenLink href="/blog" toggleKind>
              {React.string("Blog")}
            </ScreenLink>
          </FramerMotion.li>
          <FramerMotion.li variants=liVariants>
            <ScreenLink href="/work" toggleKind>
              {React.string("Work")}
            </ScreenLink>
          </FramerMotion.li>
          <FramerMotion.li variants=liVariants>
            <ScreenLink href="/profile" toggleKind>
              {React.string("Profile")}
            </ScreenLink>
          </FramerMotion.li>
        </ul>
      </nav>
    });
};

[@react.component]
let make = (~kind: HeaderState.t, ~toggleKind) => {
  let (initial, animate) = HeaderState.useInitialAnimate(kind);

  <FramerMotion.div variants=divVariants initial animate className=divCss>
    <ScreenLinks toggleKind />
  </FramerMotion.div>;
};
