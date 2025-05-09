#include "pch.h"
#include "Core/Application.h"

int Main(VulkanRenderer::CommandArgs args)
{
	VulkanRenderer::ApplicationSpecifications specifications;
	specifications.Args = args;
	specifications.LogLevel = LoggingLevel::Trace;
	specifications.Title = "Vulkan Renderer";
	specifications.Size = { 1280, 720 };

	while (VulkanRenderer::Application::IsApplicationThreadRunning())
	{
		VulkanRenderer::Application Application(specifications);
		Application.Run();
	}

	return 0;
}

#ifdef PLATFORM_WINDOWS

#ifndef DISTRIBUTION_CONFIG
int main(int argc, char** argv)
{
	return Main({ argc, argv });
}
#else
int WinMain(int argc, char** argv)
{
	return Main({ argc, argv });
}
#endif

#endif