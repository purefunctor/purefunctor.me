let navCss = [%cx {|
margin-left: auto;
position: relative;
|}];

let buttonCss = [%cx
  {|
display: flex;
align-items: center;
color: $(Theme.white);
background: unset;
border: none;
padding: 0;
cursor: pointer;
|}
];

let ulCss = [%cx
  {|
position: absolute;
line-height: 2;
list-style: none;
margin: 0;
padding: 1rem 0 1rem 1rem;
right: 0;
text-align: right;
|}
];

let ulVariants = {
  "open": {
    "visibility": "visible",
    "transition": {
      "staggerChildren": 0.17,
      "when": "beforeChildren",
    },
  },
  "close": {
    "visibility": "hidden",
    "transition": {
      "staggerChildren": 0.17,
      "staggerDirection": (-1),
      "when": "afterChildren",
    },
  },
};

let liVariants = {
  "open": {
    "x": 0.0,
    "opacity": 1.0,
  },
  "close": {
    "x": 10.0,
    "opacity": 0.0,
  },
};

type state =
  | Initial
  | ToggleOn
  | ToggleOff;

[@react.component]
let make = () => {
  let (toggled, setToggled) = React.useState(() => Initial);
  let navRef = React.useRef(Js.Nullable.null);

  let (initial, animate) =
    switch (toggled) {
    | Initial => ("close", Js.Nullable.null)
    | ToggleOn => ("close", Js.Nullable.return("open"))
    | ToggleOff => ("open", Js.Nullable.return("close"))
    };

  let onClick =
    React.useCallback(event => {
      event |> React.Event.Mouse.preventDefault;
      setToggled(toggled =>
        switch (toggled) {
        | Initial => ToggleOn
        | ToggleOn => ToggleOff
        | ToggleOff => ToggleOn
        }
      );
    });

  let onClickOutside =
    React.useCallback0(event => {
      open Webapi.Dom;

      let targetElement =
        event |> MouseEvent.target |> EventTarget.unsafeAsElement;

      let shouldClose =
        switch (navRef.current |> Js.Nullable.toOption) {
        | Some(navElement) =>
          !(navElement |> Element.contains(targetElement))
        | None => false
        };

      if (shouldClose) {
        setToggled(previous => {
          switch (previous) {
          | Initial => Initial
          | ToggleOff => ToggleOff
          | ToggleOn => ToggleOff
          }
        });
      };
    });

  React.useEffect0(() => {
    open Webapi.Dom;

    window |> Window.addMouseDownEventListener(onClickOutside);
    Some(
      () => {window |> Window.removeMouseDownEventListener(onClickOutside)},
    );
  });

  <nav className=navCss ref={ReactDOM.Ref.domRef(navRef)}>
    <button onClick className=buttonCss>
      <Icons.MenuLine size="1.5rem" />
    </button>
    <FramerMotion.ul variants=ulVariants initial animate className=ulCss>
      <FramerMotion.li variants=liVariants>
        <Link href="/work"> {React.string("Work")} </Link>
      </FramerMotion.li>
      <FramerMotion.li variants=liVariants>
        <Link href="/profile"> {React.string("Profile")} </Link>
      </FramerMotion.li>
    </FramerMotion.ul>
  </nav>;
};
