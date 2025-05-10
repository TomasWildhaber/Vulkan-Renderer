#pragma once
#include "Log.h"
#include "SmartAllocators.h"
#include "Window.h"

namespace VulkanRenderer
{
	struct CommandArgs
	{
		CommandArgs() = default;
		CommandArgs(int argc, char** argv) : Count(argc), Args(argv) {}

		int Count = 0;
		char** Args = nullptr;
	};

	struct ApplicationSpecifications
	{
		ApplicationSpecifications() = default;

		CommandArgs Args;
		LoggingLevel LogLevel = LoggingLevel::Info;
		WindowSpecifications WindowSpecs;
	};

	class Application
	{
	public:
		Application() = delete;
		Application(const ApplicationSpecifications& specs);

		~Application();

		inline static Application& Get() { return *s_Instance; }

		inline bool IsRunning() { return m_IsRunning; }
		inline static bool IsApplicationThreadRunning() { return s_IsApplicationThreadRunning; }

		void Run();

		void Close();
	private:
		ScopeRef<Window> m_Window;

		ApplicationSpecifications m_Specifications;

		bool m_IsRunning = true;
		static inline bool s_IsApplicationThreadRunning = true;

		static inline Application* s_Instance = nullptr;
	};
}