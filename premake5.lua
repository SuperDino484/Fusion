workspace "Fusion"
    architecture "x64"

    configurations {
        "Debug",
        "Release",
        "Dist"
    }

    startproject "Sandbox"

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"
IncludeDirs = {}
IncludeDirs['Fusion'] = "%{wks.location}/Fusion/src"
IncludeDirs['spdlog'] = "%{wks.location}/Fusion/vendor/spdlog/include"
IncludeDirs['glfw'] = "%{wks.location}/Fusion/vendor/glfw/include"

group "Dependencies"
    include "Fusion/vendor/glfw"
group ""

include "Fusion"
include "Sandbox"