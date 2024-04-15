module Hello = {
  [@react.component] [@mel.module "./mdx/hello.mdx"]
  external make: unit => React.element = "default";
};

[@react.component]
let make = (~slug) => {
  <main>
    {switch (slug) {
     | [] => <> {React.string("Blog posts")} </>
     | ["hello"] => <Hello />
     | _ => <> {React.string("Not Found!")} </>
     }}
  </main>;
};
