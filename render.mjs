import fs from "node:fs";

import { extractCritical } from "@emotion/server";
import * as Render from "./_build/default/app/output/app/Render.mjs";

const paths = [
  ["index.html", []],
  ["work.html", ["work"]],
  ["profile.html", ["profile"]],
]

for (let [name, path] of paths) {
  const { html, css } = extractCritical(Render.forPath(path));
  let head = `<style>${css}</style>`;
  
  const template = fs.readFileSync("./index.template.html", "utf-8");
  const rendered = template.replace("<!--app-head-->", head ?? "").replace("<!--app-html-->", html ?? "");

  fs.writeFileSync(`ssr/${name}`, rendered);
}
