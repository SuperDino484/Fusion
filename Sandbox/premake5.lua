project "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir("bin/" .. outputdir .. "/%{prj.name}")
    objdir("bin-int/" .. outputdir .. "/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs {
        "%{IncludeDirs.Fusion}",
        "%{IncludeDirs.spdlog}",
        "%{prj.name}/src"
    }

    links {
        "Fusion"
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
        defines { "FN_DEBUG" }

    filter "configurations:Release"
        optimize "on"
        defines { "FN_RELEASE" }

    filter "configurations:Dist"
        optimize "on"
        defines { "FN_DIST" }