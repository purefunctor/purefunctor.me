import { globSync } from "glob";
import mdx from "@mdx-js/rollup";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { basename, resolve } from "node:path";
import { defineConfig } from "vite";

let mdxFiles = globSync(resolve(__dirname, "..", "blog/mdx/*.mdx"));
let blogInputs = {};

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
        ...blogInputs,
      }
    },
    outDir: "./dist",
  },
  plugins: [mdx(), nodeResolve()],
  publicDir: resolve(__dirname, "..", "public"),
});
