import fs from "node:fs";
import path from "node:path";

import { extractCritical } from "@emotion/server";
import * as Render from "../_build/default/app/output/app/Render.mjs";

const routes = [
  ["index.html", []],
  ["work.html", ["work"]],
  ["profile.html", ["profile"]],
  ["blog.html", ["blog"]],
  ["blog/hello.html", ["blog", "hello"]],
]

for (let [name, slug] of routes) {
  const { html, css } = extractCritical(Render.forPath(slug));
  let head = `
<meta name="description" content="justin garcia's website and blog">
<meta property="og:image" content="/banner.png">
<style>${css}</style>
`;
  
  const template = fs.readFileSync("./index.html", "utf-8");
  const rendered = template.replace("<!--app-head-->", head ?? "").replace("<!--app-html-->", html ?? "");

  let dirname = path.join("ssr", path.dirname(name));
  fs.mkdirSync(dirname, {recursive: true});

  let filename = path.join(dirname, path.basename(name));
  fs.writeFileSync(filename, rendered);
}
