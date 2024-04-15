[@react.component]
let make = (~slug) => {
  switch (slug) {
  | [] => <BlogIndex />
  | ["hello"] => <BlogPost.Hello />
  | _ => <> {React.string("Not Found!")} </>
  };
};
