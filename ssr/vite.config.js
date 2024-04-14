import { nodeResolve } from "@rollup/plugin-node-resolve";
import { resolve } from "path";

export default {
  build: {
    rollupOptions: {
      input: {
        index: resolve(__dirname, "index.html"),
        work: resolve(__dirname, "work.html"),
        profile: resolve(__dirname, "profile.html"),
      }
    },
    outDir: "./dist",
  },
  plugins: [nodeResolve()],
};
