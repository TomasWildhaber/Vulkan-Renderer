workspace "Vulkan-Renderer"
	architecture "x64"
	platforms { "Win64" }

	startproject "Vulkan-Renderer"

	configurations
	{
		"Debug",
		"Release",
		"Distribution"
	}

	flags
	{
		"MultiProcessorCompile"
	}

	outputdir = "$(SolutionDir)Output/Bin/"
	intoutputdir = "$(SolutionDir)Output/Intermediate/"

	defines { "_CRT_SECURE_NO_WARNINGS" }

	filter "system:windows"
		defines { "PLATFORM_WINDOWS" }

	filter "configurations:Debug"
		defines "DEBUG_CONFIG"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		defines "RELEASE_CONFIG"
		runtime "Release"
		optimize "on"
		symbols "on"

	filter "configurations:Distribution"
		defines "DISTRIBUTION_CONFIG"
		runtime "Release"
		optimize "on"
		symbols "off"

group "vendor"
	
group ""

include "Vulkan-Renderer"