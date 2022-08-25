project "basic-app"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
    targetdir "bin/%{cfg.buildcfg}"
    staticruntime "off"

    files { "**.h", "**.cpp" }

    includedirs
    {
        "../../vendors/imgui",
        "../../vendors/glfw/include",
        "../../src",
        "%{IncludeDir.VulkanSDK}"
    }

    links
    {
        "../../bin/" .. outputdir .. "/Sirius/Sirius.lib"
    }

    targetdir ("../../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../../bin-int/" .. outputdir .. "/%{prj.name}")
	
    filter "system:windows"
        systemversion "latest"
        defines { "_PLATFORM_WINDOWS" }

    filter "configurations:Debug"
        defines { "_DEBUG" }
        runtime "Debug"
        symbols "On"

    filter "configurations:Release"
        defines { "_RELEASE" }
        runtime "Release"
        optimize "On"
        symbols "On"

    filter "configurations:Dist"
        kind "WindowedApp"
        defines { "_DIST" }
        runtime "Release"
        optimize "On"
        symbols "Off"