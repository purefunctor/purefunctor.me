import fs from "node:fs";
import path, { basename, resolve } from "node:path";
import { globSync } from "glob";

import { constructStyleTagsFromChunks, extractCriticalToChunks } from "@emotion/server";

import * as Render from "../_build/default/app/output/app/Render.mjs";
import * as ReactDOMServer from "react-dom/server";

function renderSingle(name, slug) {
  const element = Render.elementFor(slug);
  const markup = ReactDOMServer.renderToString(element);
  const chunks = extractCriticalToChunks(markup);

  const html = chunks.html;
  const styles = constructStyleTagsFromChunks(chunks);

  let head = `
<meta name="description" content="justin garcia's website and blog">
<meta property="og:image" content="/banner.png">
${styles}
  `;

  const template = fs.readFileSync("./index.html", "utf-8");
  const rendered = template
    .replace("<!--app-head-->", head ?? "")
    .replace("<!--app-html-->", html ?? "")
    .replace("_build", resolve(basename(import.meta.url), "..", "_build"))
    .replace("node_modules", resolve(basename(import.meta.url), "..", "node_modules"))
    .replace("Main.mjs", "Hydrate.mjs")
    .replace("index.css", resolve(basename(import.meta.url), "..", "index.css"));

  let dirname = path.join("ssr", path.dirname(name));
  fs.mkdirSync(dirname, { recursive: true });

  let filename = path.join(dirname, path.basename(name));
  fs.writeFileSync(filename, rendered);
}

// top-level pages

const config = [
  ["index.html", []],
  ["work.html", ["work"]],
  ["profile.html", ["profile"]],
  ["blog.html", ["blog"]],
]

for (let [name, slug] of config) {
  renderSingle(name, slug);
}

// individual blog posts

const mdxFiles = globSync("blog/mdx/*.mdx");
for (let mdxFile of mdxFiles) {
  let slug = path.basename(mdxFile, ".mdx");
  renderSingle(`blog/${slug}.html`, ["blog", slug]);
}
