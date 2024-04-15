let pink = CssJs.hex("FEC3E7");
let blue = CssJs.hex("C8E6F9");
let mint = CssJs.hex("C9F7E5");

let white = CssJs.hex("F5F5F5");
let white_60 = CssJs.hex("626262");
let black = CssJs.hex("1F1F1F");

let small = "(min-width: 640px)";
let afterSmall = {j|@media screen and $small|j};

let medium = "(min-width: 768px)";
let afterMedium = {j|@media screen and $medium|j};

let large = "(min-width: 1024px)";
let afterLarge = {j|@media screen and $large|j};

let maxWidth = CssJs.px(900);
