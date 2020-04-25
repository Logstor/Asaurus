project "Glad"
	kind "StaticLib"
	language "C"
	staticruntime "On"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files
	{
		"include/glad/glad.h",
		"include/KHR/khrplatform.h",
		"src/glad.c"
	}

	includedirs 
	{
		"include"
	}

	filter "system:linux"
		pic "On"

		systemversion "latest"


	filter "system:windows"
		systemversion "latest"


	filter "configurations:Debug"
		defines { "DEBUG" }
		runtime "Debug"
		symbols "on"
	
	filter "configurations:Release"
		defines { "RELEASE" }
		runtime "Release"
		optimize "on"
