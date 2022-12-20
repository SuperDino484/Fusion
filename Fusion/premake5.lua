project "Fusion"
    kind "StaticLib"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{IncludeDirs.Fusion}",
        "%{IncludeDirs.spdlog}"
    }

    filter "system:windows"
        cppdialect "C++20"
        staticruntime "on"
        systemversion "latest"

        defines {
            "FN_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        symbols "on"
        runtime "Debug"
        defines { "FN_DEBUG" }

    filter "configurations:Release"
        optimize "on"
        runtime "Debug"
        defines { "FN_RELEASE" }

    filter "configurations:Dist"
        optimize "on"
        runtime "Release"
        defines { "FN_DIST" }