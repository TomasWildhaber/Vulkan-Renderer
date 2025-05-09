#include "pch.h"
#include "Application.h"
#include "Assert.h"

namespace VulkanRenderer
{
	Application::Application(const ApplicationSpecifications& specs)
	{
		ASSERT(s_Instance == nullptr, "Application already initialized!");

		s_Instance = this;

#ifndef DISTRIBUTION_CONFIG
		Logger::Level = specs.LogLevel;
#endif

		m_Window = Window::Create(specs.Size, specs.Title);
	}

	Application::~Application()
	{
		s_Instance = nullptr;
	}

	void Application::Run()
	{
		TRACE("Application is running!");

		while (m_IsRunning)
		{

		}
	}
}