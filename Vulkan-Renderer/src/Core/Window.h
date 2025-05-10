#pragma once
#include <Core/ScopeRef.h>
#include <glm/glm.hpp>

namespace VulkanRenderer
{
	struct WindowSpecifications
	{
		WindowSpecifications() = default;

		glm::vec2 Size = { 0, 0 };
		glm::vec2 Position = { 200, 200 };
		const char* Title = nullptr;
		bool VSync = true;
	};

	struct WindowData
	{
		WindowData() = default;
		WindowData(WindowSpecifications& specs) : Size(specs.Size), Position(specs.Position), Title(specs.Title), IsVSync(specs.VSync) {}

		glm::vec2 Size = { 0, 0 };
		glm::vec2 Position = { 0, 0 };
		const char* Title = nullptr;
		bool IsVSync;
	};

	class Window
	{
	public:
		virtual ~Window() = default;

		virtual inline void OnUpdate() const = 0;
		virtual inline void OnRender() const = 0;

		virtual inline int GetWidth() const { return m_Data.Size.x; }
		virtual inline int GetHeight() const { return m_Data.Size.y; }
		virtual inline glm::vec2 GetCurrentResolution() const { return m_Data.Size; }
		virtual inline glm::vec2 GetCurrentPosition() const { return m_Data.Position; }
		virtual inline void* GetNativeWindow() const = 0;

		virtual inline bool IsVSync() const { return m_Data.IsVSync; }

		virtual inline void SetVSync(bool Enabled) = 0;

		virtual inline void MaximizeWindow() const = 0;
		virtual inline void RestoreWindow() const = 0;
		virtual inline void MinimizeWindow() const = 0;

		virtual inline void Show() const = 0;
		virtual inline void Hide() const = 0;

		static ScopeRef<Window> Create(WindowSpecifications& specs);
	protected:
		Window(WindowSpecifications& specs)
			: m_Data(specs) {}

		WindowData m_Data;
	};
}