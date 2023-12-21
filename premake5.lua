workspace "Blink"
	architecture "x64"
	configurations { "Debug", "Release", "Dist" }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

-- include directories relative to the root folder
IncludeDir = {}
IncludeDir["GLFW"] = "Blink/vendor/GLFW/include"

include "Hazel/vendor/GLFW"

project "Blink"
	location "Blink"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "BlinkPCH.h"
	pchsource "Blink/src/BlinkPCH.cpp"

	files { 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/vendor/spdlog/include",
		"%{prj.name}/src",
		"%{IncludeDir.GLFW}"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"BLINK_PLATFORM_WINDOWS",
			"BLINK_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} \"../bin/" .. outputdir .. "/Sandbox/\"")
		}

	filter "configurations:Debug"
		defines "BLINK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files { 
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"Blink/vendor/spdlog/include",
		"Blink/src"
	}

	links {
		"Blink"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines {
			"BLINK_PLATFORM_WINDOWS",
		}

	filter "configurations:Debug"
		defines "BLINK_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "BLINK_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "BLINK_DIST"
		optimize "On"

