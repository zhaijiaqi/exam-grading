{
    files = {
        "build/.objs/summary/macosx/arm64/release/learn/summary.cpp.o",
        "build/macosx/arm64/release/libtest.a"
    },
    values = {
        "/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/clang++",
        {
            "-target",
            "arm64-apple-macos15.1",
            "-isysroot",
            "/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX15.2.sdk",
            "-lz",
            "-Lbuild/macosx/arm64/release",
            "-Wl,-x",
            "-Wl,-dead_strip",
            "-ltest"
        }
    }
}