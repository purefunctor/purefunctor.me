module BookLine = {
  [@react.component]
  let make = (~size="1em", ~className="") => {
    <svg
      className
      xmlns="http://www.w3.org/2000/svg"
      width=size
      height=size
      viewBox="0 0 24 24">
      <path
        fill="currentColor"
        d="M3 18.5V5a3 3 0 0 1 3-3h14a1 1 0 0 1 1 1v18a1 1 0 0 1-1 1H6.5A3.5 3.5 0 0 1 3 18.5M19 20v-3H6.5a1.5 1.5 0 0 0 0 3zM5 15.337A3.486 3.486 0 0 1 6.5 15H19V4H6a1 1 0 0 0-1 1z"
      />
    </svg>;
  };
};

module DotLine = {
  [@react.component]
  let make = (~size="1em", ~className="") => {
    <svg
      className
      xmlns="http://www.w3.org/2000/svg"
      width=size
      height=size
      viewBox="0 0 256 256">
      <path
        fill="currentColor"
        d="M144 128a16 16 0 1 1-16-16a16 16 0 0 1 16 16"
      />
    </svg>;
  };
};

module HeartLine = {
  [@react.component]
  let make = (~size="1em", ~className="") => {
    <svg
      className
      xmlns="http://www.w3.org/2000/svg"
      width=size
      height=size
      viewBox="0 0 24 24">
      <path
        fill="currentColor"
        d="M12.001 4.529a5.998 5.998 0 0 1 8.242.228a6 6 0 0 1 .236 8.236l-8.48 8.492l-8.478-8.492a6 6 0 0 1 8.48-8.464m6.826 1.641a3.998 3.998 0 0 0-5.49-.153l-1.335 1.198l-1.336-1.197a4 4 0 0 0-5.686 5.605L12 18.654l7.02-7.03a4 4 0 0 0-.193-5.454"
      />
    </svg>;
  };
};

module HomeLine = {
  [@react.component]
  let make = (~size="1em", ~className="") => {
    <svg
      className
      xmlns="http://www.w3.org/2000/svg"
      width=size
      height=size
      viewBox="0 0 24 24">
      <path
        fill="currentColor"
        d="M21 20a1 1 0 0 1-1 1H4a1 1 0 0 1-1-1V9.49a1 1 0 0 1 .386-.79l8-6.223a1 1 0 0 1 1.228 0l8 6.223a1 1 0 0 1 .386.79zm-2-1V9.978l-7-5.444l-7 5.444V19z"
      />
    </svg>;
  };
};

module MenuLine = {
  [@react.component]
  let make = (~size="1em", ~className="") => {
    <svg
      className
      xmlns="http://www.w3.org/2000/svg"
      width=size
      height=size
      viewBox="0 0 24 24">
      <path fill="currentColor" d="M3 4h18v2H3zm0 7h18v2H3zm0 7h18v2H3z" />
    </svg>;
  };
};
