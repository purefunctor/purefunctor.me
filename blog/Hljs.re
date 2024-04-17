type options = {language: string};
type result = {value: string};
type hljs = {highlight: (string, options, bool) => result};

[@mel.module "highlight.js"] external hljs: hljs = "default";

let highlight = (~ignoreIllegals=false, code, options) => {
  hljs.highlight(code, options, ignoreIllegals);
};
