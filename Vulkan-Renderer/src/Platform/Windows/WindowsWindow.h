#pragma once
#include "Core/Window.h"

#define WIN32_LEAN_AND_MEAN
#define NOMINMAX
#include <windows.h>

namespace VulkanRenderer
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(WindowSpecifications& specs);
		~WindowsWindow();

		virtual inline void OnUpdate() const override;
		virtual inline void OnRender() const override;

		virtual inline void* GetNativeWindow() const override { return m_HWindow; }

		virtual inline void SetVSync(bool Enabled) override;

		virtual inline void MaximizeWindow() const override { ShowWindow(m_HWindow, SW_MAXIMIZE); }
		virtual inline void RestoreWindow() const override { ShowWindow(m_HWindow, SW_RESTORE); }
		virtual inline void MinimizeWindow() const override { ShowWindow(m_HWindow, SW_MINIMIZE); }

		virtual inline void Show() const override { ShowWindow(m_HWindow, SW_SHOW); }
		virtual inline void Hide() const override { ShowWindow(m_HWindow, SW_HIDE); }
	private:
		friend LRESULT CALLBACK WindowProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam);

		HINSTANCE m_HInstance;
		HWND m_HWindow;

		DWORD m_Style = WS_CLIPSIBLINGS | WS_CLIPCHILDREN | CS_OWNDC | WS_OVERLAPPEDWINDOW | CS_HREDRAW | CS_VREDRAW
			| WS_CAPTION | WS_BORDER | WS_MINIMIZEBOX | WS_MAXIMIZEBOX | WS_SYSMENU | WS_THICKFRAME;
	};
}