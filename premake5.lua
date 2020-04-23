workspace "Asaurus"
	architecture "x86_64"
	-- Make sure the Sandbox application is the startup application always
	startproject "Sandbox"
	configurations
	{
		"Debug", 
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- Include directories relative to root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Asaurus/vendor/GLFW/include"
IncludeDir["Glad"] = "Asaurus/vendor/Glad/include"
IncludeDir["ImGui"] = "Asaurus/vendor/imgui"

-- Include other Projects premake5.lua file
group "Dependencies"

	include "Asaurus/vendor/GLFW"
	include "Asaurus/vendor/Glad"
	include "Asaurus/vendor/imgui"

group ""



project "Asaurus"
	location "Asaurus"
	kind "SharedLib"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "aspch.h"
	pchsource "%{prj.name}/src/aspch.cpp"

	files
	{ 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}",
		"%{IncludeDir.Glad}",
		"%{IncludeDir.ImGui}"
	}

	links
	{
		"GLFW",
		"Glad",
		"ImGui",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL",
			"GLFW_INCLUDE_NONE"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines { "AS_ENABLE_ASSERTS", "AS_DEBUG", "DEBUG" }
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines { "AS_RELEASE", "RELEASE" }
		runtime "Release"

		optimize "On"

	filter "configurations:Dist"
		defines { "AS_DIST", "RELEASE" }
		runtime "Release"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"
	staticruntime "off"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{ 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs
	{
		"Asaurus/vendor/spdlog/include",
		"Asaurus/src"
	}

	links
	{
		"Asaurus"
	}

	filter "system:windows"
		cppdialect "C++17"
		systemversion "latest"
		
		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "AS_DEBUG", "DEBUG" }
		runtime "Debug"
		symbols "On"
	
	filter "configurations:Release"
		defines { "AS_RELEASE", "RELEASE" }
		runtime "Release"
		optimize "On"

	filter "configurations:Dist"
		defines { "AS_DIST", "RELEASE" }
		runtime "Release"
		optimize "On"