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

include "Fusion"
include "Sandbox"