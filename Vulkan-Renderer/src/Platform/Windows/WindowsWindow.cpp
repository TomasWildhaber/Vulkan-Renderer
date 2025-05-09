#include "pch.h"
#include "WindowsWindow.h"
#include "Core/Log.h"

namespace VulkanRenderer
{
	ScopeRef<Window> Window::Create(const WindowSize& size, const char* title)
	{
		return ScopeRef<WindowsWindow>::Create(size, title);
	}

	WindowsWindow::WindowsWindow(const WindowSize& size, const char* title)
	{
		TRACE("Window created!");
	}

	WindowsWindow::~WindowsWindow()
	{
		TRACE("Window destroyed!");
	}
}