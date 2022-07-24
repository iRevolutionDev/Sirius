--> Framework Project <--
workspace "Sirius"
    architecture "x64"
    startproject "Sirius"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["VulkanSDK"] = VULKAN_SDK .. "/Include"
IncludeDir["ImGui"] = "vendors/imgui"

LibraryDir = {}
LibraryDir["VulkanSDK"] = VULKAN_SDK .. "/Lib"

Library = {}
Library["Vulkan"] = LibraryDir.VulkanSDK .. "/vulkan-1.lib"

include "vendors/imgui"
include "vendors/glfw"

project "Sirius"
    kind "StaticLib"
    language "C++"
    cppdialect "C++20"
    staticruntime "off"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

    location "src/"

    files
    {
        "src/**.h",
        "src/**.cpp"
    }

    includedirs
    {
        "src",
        "vendors/glfw/include",
        "%{IncludeDir.ImGui}",
        "%{IncludeDir.VulkanSDK}"
    }

	links
    {
        "GLFW",
        "ImGui",
        "%{Library.Vulkan}"
    }

--> Examples Project <--
workspace "Sirius-Examples"
    architecture "x64"
    startproject "Sirius-Examples"
    configurations { "Debug", "Release" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["VulkanSDK"] = VULKAN_SDK .. "/Include"
IncludeDir["ImGui"] = "vendors/imgui"

LibraryDir = {}
LibraryDir["VulkanSDK"] = VULKAN_SDK .. "/Lib"

Library = {}
Library["Vulkan"] = LibraryDir.VulkanSDK .. "/vulkan-1.lib"


include "vendors/glfw"
include "vendors/imgui"
include "examples/basic-app"