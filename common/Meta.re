let defaultTitle = "Justin Garcia";
let defaultDescription = "justin's website and blog";

let currentTitle = ref(defaultTitle);
let currentDescription = ref(defaultDescription);

let setDocumentTitle: string => unit = [%mel.raw
  {|
(title) => {
  document.title = title;
}
|}
];

let resetCurrent = () => {
  currentTitle := defaultTitle;
  currentDescription := defaultDescription;
};

let useMeta = (~title, ~description) => {
  currentTitle := title;
  currentDescription := description;

  React.useEffect2(
    () => {
      setDocumentTitle(title);
      Some(
        () => {
          resetCurrent();
          setDocumentTitle(defaultTitle);
        },
      );
    },
    (title, description),
  );
};
