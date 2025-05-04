#pragma once
#include "Logger.h"

#if !defined(DISTRIBUTION_CONFIG)
	#if defined(_MSC_VER)
		#define TRACE(...)	Logger::Trace(__VA_ARGS__)
		#define DEBUG(...)	Logger::Debug(__VA_ARGS__)
		#define INFO(...)	Logger::Info(__VA_ARGS__)
		#define WARN(...)	Logger::Warn(__VA_ARGS__)
		#define ERROR(...)	Logger::Error(__VA_ARGS__)
	#elif defined(__clang__) || defined(__GNUC__)
		#define TRACE(...)	Logger::Trace(##__VA_ARGS__)
		#define DEBUG(...)	Logger::Debug(##__VA_ARGS__)
		#define INFO(...)	Logger::Info(##__VA_ARGS__)
		#define WARN(...)	Logger::Warn(##__VA_ARGS__)
		#define ERROR(...)	Logger::Error(##__VA_ARGS__)
	#endif
#else
	#define TRACE(...)
	#define DEBUG(...)
	#define INFO(...)
	#define WARN(...)
	#define ERROR(...)
#endif