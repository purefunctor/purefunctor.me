import mdx from "@mdx-js/rollup";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { resolve } from "node:path";
import { defineConfig } from "vite";

export default defineConfig({
  resolve: {
    alias: [
      { find: "~", replacement: resolve(__dirname) },
    ],
  },
  build: {
    outDir: "./dist",
  },
  plugins: [mdx(), nodeResolve()],
});
