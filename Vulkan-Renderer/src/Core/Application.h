#pragma once

namespace VulkanRenderer
{
	struct CommandArgs
	{
		CommandArgs() = default;
		CommandArgs(int argc, char** argv) : Count(argc), Args(argv) {}

		int Count;
		char** Args;
	};

	struct WindowSize
	{
		int Width;
		int Height;
	};

	struct ApplicationSpecifications
	{
		ApplicationSpecifications() = default;

		const char* Title;
		WindowSize Size;
		CommandArgs Args;
	};

	class Application
	{
	public:
		Application() = delete;
		Application(const ApplicationSpecifications& Specs);

		~Application();

		inline static Application& Get() { return *s_Instance; }

		inline bool IsRunning() { return isRunning; }
		inline static bool IsApplicationThreadRunning() { return isApplicationThreadRunning; }

		void Run();
	private:
		bool isRunning = true;
		static inline bool isApplicationThreadRunning = true;

		static inline Application* s_Instance = nullptr;
	};
}
