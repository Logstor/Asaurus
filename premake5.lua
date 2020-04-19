workspace "Asaurus"
	architecture "x86_64"
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

-- Include GLFW Project premake5.lua file
include "Asaurus/vendor/GLFW"

project "Asaurus"
	location "Asaurus"
	kind "SharedLib"
	language "C++"

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
		"%{IncludeDir.GLFW}"
	}

	links
	{
		"GLFW"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"AS_PLATFORM_WINDOWS",
			"AS_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines { "AS_DEBUG", "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "AS_RELEASE", "RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "AS_DIST", "RELEASE" }
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

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
		staticruntime "On"
		systemversion "latest"
		
		defines
		{
			"AS_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines { "AS_DEBUG", "DEBUG" }
		symbols "On"
	
	filter "configurations:Release"
		defines { "AS_RELEASE", "RELEASE" }
		optimize "On"

	filter "configurations:Dist"
		defines { "AS_DIST", "RELEASE" }
		optimize "On"