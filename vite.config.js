import mdx from "@mdx-js/rollup";
import mdxConfiguration from "./mdx.config.js";

import { nodeResolve } from "@rollup/plugin-node-resolve";
import { defineConfig } from "vite";

export default defineConfig({
  build: {
    outDir: "./dist",
  },
  plugins: [mdx(mdxConfiguration), nodeResolve()],
  server: {
    headers: {
      "Cross-Origin-Opener-Policy": "same-origin",
      "Cross-Origin-Embedder-Policy": "require-corp",
    },
  },
});
