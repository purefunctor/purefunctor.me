type t =
  | Initial
  | ToggledOn
  | ToggledOff;

let unsafeSetBodyOverflow: string => unit = [%mel.raw
  {|(value) => {
      document.body.style.overflow = value;
    }|}
];

let setBodyOverflow = state => {
  switch (state) {
  | Initial => unsafeSetBodyOverflow("auto")
  | ToggledOn => unsafeSetBodyOverflow("hidden")
  | ToggledOff => unsafeSetBodyOverflow("auto")
  };
};

let use = () => {
  let (kind, setKind) = React.useState(() => Initial);

  React.useEffect1(
    () => {
      setBodyOverflow(kind);
      None;
    },
    [|kind|],
  );

  let toggleKind =
    React.useCallback0(() => {
      setKind(previous => {
        switch (previous) {
        | Initial
        | ToggledOff => ToggledOn
        | ToggledOn => ToggledOff
        }
      })
    });

  (kind, toggleKind);
};

let useInitialAnimate = (kind: t) => {
  React.useMemo1(
    () => {
      switch (kind) {
      | Initial => ("close", "close")
      | ToggledOn => ("close", "open")
      | ToggledOff => ("open", "close")
      }
    },
    [|kind|],
  );
};
