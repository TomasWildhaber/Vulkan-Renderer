project "Vulkan-Renderer"
    language "C++"
    cppdialect "C++20"
	staticruntime "on"

    targetdir (outputdir .. "$(Configuration)/$(ProjectName)")
	objdir (intoutputdir .. "$(Configuration)/$(ProjectName)")

    -- pchheader "pch.h"
	-- pchsource "src/pch.cpp"

    files
	{
		"src/**.h",
		"src/**.cpp",
	}

    includedirs
    {
        "src",
    }

    links
    {
        
    }

    filter "configurations:Debug"
        kind "ConsoleApp"

	filter "configurations:Release"
        kind "ConsoleApp"

    filter "configurations:Distribution"
        kind "WindowedApp"