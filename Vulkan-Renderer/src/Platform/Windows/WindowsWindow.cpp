#include "pch.h"
#ifdef PLATFORM_WINDOWS

#include "WindowsWindow.h"
#include "Core/Application.h"
#include "Core/Time.h"

#include "Core/Log.h"
#include "Core/Assert.h"
#include "Core/Buffer.h"

namespace VulkanRenderer
{
	static LARGE_INTEGER cpu_frequency;
	static LARGE_INTEGER lastTime;

	LRESULT WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			Application::Get().Close();
		}

		return DefWindowProc(hWnd, msg, wParam, lParam);
	}

	ScopeRef<Window> Window::Create(WindowSpecifications& specs)
	{
		return ScopeRef<WindowsWindow>::Create(specs);
	}

	WindowsWindow::WindowsWindow(WindowSpecifications& specs) : Window(specs), m_HInstance(GetModuleHandle(nullptr))
	{
		const wchar_t* windowClassName = L"Window class";

		WNDCLASS wndClass = {};
		wndClass.lpszClassName = windowClassName;
		wndClass.hInstance = m_HInstance;
		wndClass.hIcon = LoadIcon(NULL, IDI_WINLOGO);
		wndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
		wndClass.lpfnWndProc = WindowProc;

		RegisterClass(&wndClass);

		RECT rect;
		rect.left = m_Data.Position.x;
		rect.top = m_Data.Position.y;

		rect.right = rect.left + m_Data.Size.x;
		rect.bottom = rect.top + m_Data.Size.y;

		AdjustWindowRect(&rect, m_Style, false);

		Buffer title(MultiByteToWideChar(CP_UTF8, 0, m_Data.Title, -1, NULL, 0) * sizeof(wchar_t));
		MultiByteToWideChar(CP_UTF8, 0, m_Data.Title, -1, title.GetDataAs<wchar_t>(), title.GetSize());

		m_HWindow = CreateWindowEx(0, windowClassName, title.GetDataAs<wchar_t>(), m_Style, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, NULL, NULL, m_HInstance, NULL);

		VERIFY(m_HWindow != nullptr, "Window creation failed!");

		SetVSync(m_Data.IsVSync);

		TRACE("Window created!");
	}

	WindowsWindow::~WindowsWindow()
	{
		const wchar_t* className = L"Window class";
		UnregisterClass(className, m_HInstance);

		DestroyWindow(m_HWindow);

		TRACE("Window destroyed!");
	}

	void WindowsWindow::OnUpdate() const
	{
		MSG msg;
		while (PeekMessage(&msg, m_HWindow, 0u, 0u, PM_REMOVE))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		LARGE_INTEGER currentTime;
		QueryPerformanceCounter(&currentTime);
		DeltaTime = (float)(currentTime.QuadPart - lastTime.QuadPart) / (float)cpu_frequency.QuadPart;
		lastTime = currentTime;
	}

	void WindowsWindow::OnRender() const
	{

	}

	void WindowsWindow::SetVSync(bool Enabled)
	{

	}
}

#endif