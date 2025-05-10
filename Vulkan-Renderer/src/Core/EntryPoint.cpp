#include "pch.h"
#include "Core/Application.h"

int Main(VulkanRenderer::CommandArgs args)
{
	VulkanRenderer::WindowSpecifications windowSpecifications{};
	windowSpecifications.Title = "Vulkan renderer";
	windowSpecifications.Size = { 1280, 720 };
	windowSpecifications.VSync = true;

	VulkanRenderer::ApplicationSpecifications appSpecifications{};
	appSpecifications.Args = args;
	appSpecifications.LogLevel = LoggingLevel::Trace;
	appSpecifications.WindowSpecs = windowSpecifications;

	while (VulkanRenderer::Application::IsApplicationThreadRunning())
	{
		VulkanRenderer::Application Application(appSpecifications);
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

#include <Windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR lpCmdLine, int nCmdShow)
{
	return Main({ __argc, __argv }); // TODO: command line arguments for other compilers
}
#endif

#endif