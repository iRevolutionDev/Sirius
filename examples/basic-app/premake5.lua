project "basic-app"
    kind "ConsoleApp"
    language "C++"
    cppdialect "C++20"
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
        "Sirius"
    }

    targetdir ("../../bin/" .. outputdir .. "/%{prj.name}")
    objdir ("../../bin-int/" .. outputdir .. "/%{prj.name}")