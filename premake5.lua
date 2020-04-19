workspace "Asaurus"
	architecture "x86_64"
	configurations
	{
		"Debug", 
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Asaurus"
	location "Asaurus"
	kind "SharedLib"
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
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include"
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