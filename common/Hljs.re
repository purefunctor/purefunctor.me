type language;
type options = {language: string};
type result = {value: string};
type hljs = {
  highlight: (string, options, bool) => result,
  registerLanguage: (string, language) => unit,
};

[@mel.module "highlight.js/lib/core"] external hljs: hljs = "default";

module Languages = {
  [@mel.module "highlight.js/lib/languages/javascript"]
  external javascript: language = "default";

  [@mel.module "highlight.js/lib/languages/python"]
  external python: language = "default";

  [@mel.module "highlight.js/lib/languages/plaintext"]
  external plaintext: language = "default";

  [@mel.module "highlight.js/lib/languages/reasonml"]
  external reasonml: language = "default";

  [@mel.module "highlight.js/lib/languages/haskell"]
  external haskell: language = "default";

  let all = [|
    ("javascript", javascript),
    ("python", python),
    ("text", plaintext),
    ("reasonml", reasonml),
    ("purescript", haskell),
  |];
};

let lazyInitialize = {
  let initialized = ref(false);
  () =>
    if (! initialized^) {
      initialized := true;
      Languages.all
      |> Array.iter(((languageName, languageModule)) => {
           hljs.registerLanguage(languageName, languageModule)
         });
    };
};

let highlight = (~ignoreIllegals=false, code, options) => {
  lazyInitialize();
  hljs.highlight(code, options, ignoreIllegals);
};
