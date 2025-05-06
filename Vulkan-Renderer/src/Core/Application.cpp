#include "pch.h"
#include "Application.h"
#include "Log.h"
#include "Assert.h"

namespace VulkanRenderer
{
	Application::Application(const ApplicationSpecifications& Specs)
	{
		ASSERT(s_Instance == nullptr, "Application already initialized!");

		s_Instance = this;
	}

	Application::~Application()
	{
		s_Instance = nullptr;
	}

	void Application::Run()
	{
		TRACE("Project is working");

		while (isRunning)
		{

		}
	}
}