import fs from "node:fs";
import path, { basename, resolve } from "node:path";
import { globSync } from "glob";

import { constructStyleTagsFromChunks, extractCriticalToChunks } from "@emotion/server";

import * as Render from "../_build/default/app/output/app/Render.mjs";
import * as Meta from "../_build/default/app/output/common/Meta.mjs";
import * as ReactDOMServer from "react-dom/server";

const template = fs.readFileSync("./index.html", "utf-8")
  .replace("_build", resolve(basename(import.meta.url), "..", "_build"))
  .replace("node_modules", resolve(basename(import.meta.url), "..", "node_modules"))
  .replace("Main.mjs", "Hydrate.mjs")
  .replace("index.css", resolve(basename(import.meta.url), "..", "index.css"));

function renderSingle(name, slug) {
  Meta.resetCurrent();

  const element = Render.elementFor(slug);
  const markup = ReactDOMServer.renderToString(element);
  const chunks = extractCriticalToChunks(markup);

  const title = Meta.currentTitle.contents;
  const description = Meta.currentDescription.contents;

  const html = chunks.html;
  const styles = constructStyleTagsFromChunks(chunks);

  let head = `
<title>${title}</title>
<meta name="description" content="${description}">

<meta property="og:url" content="https://purefunctor.me">
<meta property="og:type" content="website">
<meta property="og:title" content="${title}">
<meta property="og:description" content="${description}">
<meta property="og:image" content="https://purefunctor.me/banner.png">

<meta name="twitter:card" content="summary_large_image">
<meta property="twitter:domain" content="purefunctor.me">
<meta property="twitter:url" content="https://purefunctor.me">
<meta name="twitter:title" content="${title}">
<meta name="twitter:description" content="${description}">
<meta name="twitter:image" content="https://purefunctor.me/banner.png">
${styles}
  `;

  const rendered = template
    .replace("<!--app-head-->", head ?? "")
    .replace("<!--app-html-->", html ?? "");

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
  ["404.html", ["404"]],
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
renderSingle(`blog/404.html`, ["404"]);
