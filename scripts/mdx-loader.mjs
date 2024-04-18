import { createLoader } from "@mdx-js/node-loader";
import mdxConfiguration from "../mdx.config.js";

const mdxLoader = createLoader(mdxConfiguration);
export const load = mdxLoader.load;
