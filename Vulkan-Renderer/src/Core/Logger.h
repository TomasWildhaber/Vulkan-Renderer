#pragma once

enum class LoggingLevel
{
	Trace = 0, Debug, Info, Warn, Error
};

#ifndef DISTRIBUTION_CONFIG

#include "Core/Time.h"

class Logger
{
	Logger() = delete;
public:
	static inline LoggingLevel Level;

	template<typename... Args>
	static void Trace(const char* message, Args&&... _args)
	{
		if (Level == LoggingLevel::Trace)
		{
			std::vector<std::any> args = { _args... };

			GetLogTime();
			std::cout << "\033[94m[" << s_TimeCharBuffer << "] APP TRACE: ";
			while (*message)
			{
				if (*message == '{' && *(message + 2) == '}')
				{
					int i = *(message + 1) - 48;
					printArg(args, i);
					message += 3;
				}
				else
				{
					std::cout << *message;
					message++;
				}
			}

			std::cout << std::endl;
		}
	}

	template<typename... Args>
	static void Debug(const char* message, Args&&... _args)
	{
		if (Level <= LoggingLevel::Debug)
		{
			std::vector<std::any> args = { _args... };

			GetLogTime();
			std::cout << "\033[35m[" << s_TimeCharBuffer << "] APP DEBUG: ";
			while (*message)
			{
				if (*message == '{' && *(message + 2) == '}')
				{
					int i = *(message + 1) - 48;
					printArg(args, i);
					message += 3;
				}
				else
				{
					std::cout << *message;
					message++;
				}
			}

			std::cout << std::endl;
		}
	}

	template<typename... Args>
	static void Info(const char* message, Args&&... _args)
	{
		if (Level <= LoggingLevel::Info)
		{
			std::vector<std::any> args = { _args... };

			GetLogTime();
			std::cout << "\033[32m[" << s_TimeCharBuffer << "] APP INFO: ";
			while (*message)
			{
				if (*message == '{' && *(message + 2) == '}')
				{
					int i = *(message + 1) - 48;
					printArg(args, i);
					message += 3;
				}
				else
				{
					std::cout << *message;
					message++;
				}
			}

			std::cout << std::endl;
		}
	}

	template<typename... Args>
	static void Warn(const char* message, Args&&... _args)
	{
		if (Level <= LoggingLevel::Warn)
		{
			std::vector<std::any> args = { _args... };

			GetLogTime();
			std::cout << "\033[33m[" << s_TimeCharBuffer << "] APP WARNING: ";
			while (*message)
			{
				if (*message == '{' && *(message + 2) == '}')
				{
					int i = *(message + 1) - 48;
					printArg(args, i);
					message += 3;
				}
				else
				{
					std::cout << *message;
					message++;
				}
			}

			std::cout << std::endl;
		}
	}

	template<typename... Args>
	static void Error(const char* message, Args&&... _args)
	{
		if (Level <= LoggingLevel::Error)
		{
			std::vector<std::any> args = { _args... };

			GetLogTime();
			std::cout << "\033[31m[" << s_TimeCharBuffer << "] APP ERROR: ";
			while (*message)
			{
				if (*message == '{' && *(message + 2) == '}')
				{
					int i = *(message + 1) - 48;
					printArg(args, i);
					message += 3;
				}
				else
				{
					std::cout << *message;
					message++;
				}
			}

			std::cout << std::endl;
		}
	}
private:
	static inline void printArg(std::vector<std::any>& args, int& index)
	{
		if (args[index].type() == typeid(const char*))
			std::cout << any_cast<const char*>(args[index]);
		else if (args[index].type() == typeid(char*))
			std::cout << any_cast<char*>(args[index]);
		else if (args[index].type() == typeid(int))
			std::cout << any_cast<int>(args[index]);
		else if (args[index].type() == typeid(uint32_t))
			std::cout << any_cast<uint32_t>(args[index]);
		else if (args[index].type() == typeid(size_t))
			std::cout << any_cast<size_t>(args[index]);
		else if (args[index].type() == typeid(float))
			std::cout << any_cast<float>(args[index]);
		else if (args[index].type() == typeid(double))
			std::cout << any_cast<double>(args[index]);
		else if (args[index].type() == typeid(bool))
			std::cout << any_cast<bool>(args[index]);
		else if (args[index].type() == typeid(std::string))
			std::cout << any_cast<std::string>(args[index]);
		else if (args[index].type() == typeid(VulkanRenderer::Time))
			std::cout << (float)any_cast<VulkanRenderer::Time>(args[index]);
		else
			std::cout << "Argument at position: " << index << " not supported!" << std::endl;
	}

	static inline void GetLogTime()
	{
		std::time_t current_time = std::time(0);
		std::tm* timestamp = std::localtime(&current_time);
		strftime(s_TimeCharBuffer, 80, "%T", timestamp);
	}

	static inline char s_TimeCharBuffer[80];
};

#endif