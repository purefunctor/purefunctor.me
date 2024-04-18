import { globSync } from "glob";
import mdx from "@mdx-js/rollup";
import mdxConfiguration from "../mdx.config.js";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { basename, resolve } from "node:path";
import { defineConfig } from "vite";

let mdxFiles = globSync(resolve(__dirname, "..", "blog/mdx/*.mdx"));
let blogInputs = {"blog_404": resolve(__dirname, "blog", "404.html")};

for (let mdxFile of mdxFiles) {
  let slug = basename(mdxFile, ".mdx");
  blogInputs[`blog_${slug}`] = resolve(__dirname, "blog", `${slug}.html`);
}

export default defineConfig({
  build: {
    rollupOptions: {
      input: {
        index: resolve(__dirname, "index.html"),
        work: resolve(__dirname, "work.html"),
        profile: resolve(__dirname, "profile.html"),
        blog: resolve(__dirname, "blog.html"),
        _404: resolve(__dirname, "404.html"),
        ...blogInputs,
      }
    },
    outDir: "./dist",
  },
  plugins: [mdx(mdxConfiguration), nodeResolve()],
  publicDir: resolve(__dirname, "..", "public"),
});
