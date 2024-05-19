-- properties
Name = "surtils"
Props = {
    std = "c17",
    version = "0.1",
    type = "bin",
    compiler = "gcc",
}

-- C files that should not be compiled manually (don't have a header)

-- external dependenciess
Dependencies = {
    { "https://github.com/Surtur-Team/surtests", 0.1 }
}
