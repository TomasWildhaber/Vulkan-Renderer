#include "pch.h"
#include "Application.h"
#include "Assert.h"

namespace VulkanRenderer
{
	Application::Application(const ApplicationSpecifications& specs) : m_Specifications(specs)
	{
		ASSERT(s_Instance == nullptr, "Application already initialized!");

		s_Instance = this;

#ifndef DISTRIBUTION_CONFIG
		Logger::Level = m_Specifications.LogLevel;
#endif

		WindowSpecifications& windowSpecs = m_Specifications.WindowSpecs;
		m_Window = Window::Create(windowSpecs);
		m_Window->Show();
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
			m_Window->OnUpdate();
			m_Window->OnRender();
		}
	}

	void Application::Close()
	{
		m_IsRunning = false;
		s_IsApplicationThreadRunning = false;
	}
}