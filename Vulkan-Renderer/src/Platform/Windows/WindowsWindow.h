#pragma once
#include "Core/Window.h"

namespace VulkanRenderer
{
	class WindowsWindow : public Window
	{
	public:
		WindowsWindow(const WindowSize& size, const char* title);
		~WindowsWindow();

		//virtual inline void OnUpdate() const = 0;
		//virtual inline void OnRender() const = 0;

		//virtual inline int GetWidth() const = 0;
		//virtual inline int GetHeight() const = 0;
		//virtual inline glm::vec2 GetCurrentResolution() const = 0;
		//virtual inline glm::vec2 GetCurrentPosition() const = 0;
		//virtual inline void* GetNativeWindow() const = 0;

		//virtual inline void SetVSync(bool Enabled) = 0;
		//virtual inline bool IsVSync() const = 0;
		//virtual inline bool IsMaximized() const = 0;

		//virtual inline void MaximizeWindow() const = 0;
		//virtual inline void RestoreWindow() const = 0;
		//virtual inline void MinimizeWindow() const = 0;
		//virtual inline void CloseWindow() const = 0;

		//virtual inline void ShowWindow() const = 0;
		//virtual inline void HideWindow() const = 0;
	};
}