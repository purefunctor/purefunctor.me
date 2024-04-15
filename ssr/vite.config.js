import mdx from "@mdx-js/rollup";
import { nodeResolve } from "@rollup/plugin-node-resolve";
import { resolve } from "node:path";
import { defineConfig } from "vite";

export default defineConfig({
  resolve: {
    alias: {
      "~": resolve(__dirname, "../"),
    },
  },
  build: {
    rollupOptions: {
      input: {
        index: resolve(__dirname, "index.html"),
        work: resolve(__dirname, "work.html"),
        profile: resolve(__dirname, "profile.html"),
        blog: resolve(__dirname, "blog.html"),
        blog_hello: resolve(__dirname, "blog", "hello.html")
      }
    },
    outDir: "./dist",
  },
  plugins: [mdx(), nodeResolve()],
  publicDir: resolve(__dirname, "..", "public"),
});
