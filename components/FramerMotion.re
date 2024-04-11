[@react.component] [@mel.module "framer-motion"] [@mel.scope "motion"]
external p:
  (
    ~initial: Js.t({..})=?,
    ~animate: Js.t({..})=?,
    ~exit: Js.t({..})=?,
    ~transition: Js.t({..})=?,
    ~className: string=?,
    ~children: React.element=?,
    ~role: string=?
  ) =>
  React.element =
  "p";

module AnimatePresence = {
  [@react.component] [@mel.module "framer-motion"]
  external make: (~children: React.element=?) => React.element =
    "AnimatePresence";
};
