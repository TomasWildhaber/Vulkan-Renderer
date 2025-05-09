#pragma once
#include <Core/ScopeRef.h>
#include <glm/glm.hpp>

namespace VulkanRenderer
{
	struct WindowSize
	{
		int Width;
		int Height;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

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

		static ScopeRef<Window> Create(const WindowSize& size, const char* Title);
	protected:
		int m_X, m_Y, m_Width, m_Height;
	};
}