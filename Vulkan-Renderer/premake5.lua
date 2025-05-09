project "Vulkan-Renderer"
    language "C++"
    cppdialect "C++20"
	staticruntime "on"

    targetdir (outputdir .. "$(Configuration)/$(ProjectName)")
	objdir (intoutputdir .. "$(Configuration)/$(ProjectName)")

    pchheader "pch.h"
	pchsource "src/pch.cpp"

    files
	{
		"src/**.h",
		"src/**.cpp",
	}

    includedirs
    {
        "src",
        "$(SolutionDir)vendor/glm/src",
    }

    links
    {
        
    }

    defines { "ENABLE_VERIFY" }

    filter "configurations:Debug"
        defines "ENABLE_ASSERTS"
        kind "ConsoleApp"

	filter "configurations:Release"
        kind "ConsoleApp"

    filter "configurations:Distribution"
        kind "WindowedApp"