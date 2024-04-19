  $ ./pp.exe -impl success.input
  module HelloWorld =
    struct
      let slug = [|"hello-world"|]
      external title : string = "title"[@@mel.module "./mdx/hello-world.mdx"]
      external description : string = "description"[@@mel.module
                                                     "./mdx/hello-world.mdx"]
      external published : Js.Date.t = "published"[@@mel.module
                                                    "./mdx/hello-world.mdx"]
      external readingTime : Mdx_ppx_runtime.readingTime = "readingTime"
      [@@mel.module "./mdx/hello-world.mdx"]
      external make :
        ?components:Mdx_ppx_runtime.components -> React.element = "default"
      [@@mel.module "./mdx/hello-world.mdx"][@@react.component ]
    end

  $ ./pp.exe -impl failure.input
  File "failure.input", line 1, characters 28-32:
  1 | module HelloWorld = [%mdx { file = "./mdx/hello-world.mdx" }]
                                  ^^^^
  Error: mdx_ppx: expected "path"
  [1]
