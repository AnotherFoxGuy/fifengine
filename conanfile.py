import os
from conan import ConanFile
from conan.tools.files import copy


class Fifengine(ConanFile):
    name = "fifengine"
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"
    default_options = {
        "tinyxml*:with_stl": True,
    }

    def requirements(self):
        #self.requires("swig/4.1.0")
        self.requires("boost/1.82.0")
        self.requires("fifechan/0.1.6")
        self.requires("glew/2.2.0")
        self.requires("libpng/1.6.40", force=True)
        self.requires("libwebp/1.3.1", override=True)
        self.requires("ogg/1.3.5")
        self.requires("openal/1.22.2")
        self.requires("sdl_image/2.0.5")
        self.requires("sdl_ttf/2.20.2")
        self.requires("sdl/2.28.5", force=True)
        self.requires("tinyxml/2.6.2")
        self.requires("vorbis/1.3.7")
        self.requires("zlib/1.2.13")
        if self.settings.os == "Linux":
            self.requires("xz_utils/5.4.2", override=True)

    def generate(self):
        for dep in self.dependencies.values():
            if len(dep.cpp_info.bindirs) > 0:
                self.cp_data(dep.cpp_info.bindirs[0])
            if len(dep.cpp_info.libdirs) > 0:
                self.cp_data(dep.cpp_info.libdirs[0])

    def cp_data(self, src):
        # bin, *.dll -> bin @ keep_path=False
        # lib, *.dll -> bin @ keep_path=False
        # lib, *.dylib -> bin @ keep_path=False
        # lib, *.so* -> bin @ keep_path=False
        bindir = os.path.join(self.build_folder, "bin")
        copy(self, "*.dll", src, bindir)
        copy(self, "*.dylib", src, bindir)
        copy(self, ".so*", src, bindir)
