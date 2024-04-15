import mdx from "@mdx-js/rollup";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { defineConfig } from "vite";

export default defineConfig({
  build: {
    outDir: "./dist",
  },
  plugins: [mdx(), nodeResolve()],
});
