[@react.component] [@mel.module "framer-motion"] [@mel.scope "motion"]
external p:
  (
    ~initial: 'initial=?,
    ~animate: 'animate=?,
    ~exit: 'exit=?,
    ~transition: 'transition=?,
    ~variants: 'variants=?,
    ~variant: string=?,
    ~className: string=?,
    ~children: React.element=?,
    ~role: string=?
  ) =>
  React.element =
  "p";

[@react.component] [@mel.module "framer-motion"] [@mel.scope "motion"]
external ul:
  (
    ~initial: 'initial=?,
    ~animate: 'animate=?,
    ~exit: 'exit=?,
    ~transition: 'transition=?,
    ~variants: 'variants=?,
    ~variant: string=?,
    ~className: string=?,
    ~children: React.element=?,
    ~role: string=?
  ) =>
  React.element =
  "ul";

[@react.component] [@mel.module "framer-motion"] [@mel.scope "motion"]
external li:
  (
    ~initial: 'initial=?,
    ~animate: 'animate=?,
    ~exit: 'exit=?,
    ~transition: 'transition=?,
    ~variants: 'variants=?,
    ~variant: string=?,
    ~className: string=?,
    ~children: React.element=?,
    ~role: string=?
  ) =>
  React.element =
  "li";

[@react.component] [@mel.module "framer-motion"] [@mel.scope "motion"]
external div:
  (
    ~initial: 'initial=?,
    ~animate: 'animate=?,
    ~exit: 'exit=?,
    ~transition: 'transition=?,
    ~variants: 'variants=?,
    ~variant: string=?,
    ~className: string=?,
    ~children: React.element=?,
    ~role: string=?
  ) =>
  React.element =
  "div";

module AnimatePresence = {
  [@react.component] [@mel.module "framer-motion"]
  external make: (~children: React.element=?) => React.element =
    "AnimatePresence";
};
