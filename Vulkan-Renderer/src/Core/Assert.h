#pragma once
#include "Core/Core.h"
#include "Log.h"

#if defined(ENABLE_VERIFY)
	#define VERIFY(con, msg) { if (!(con)) { ERROR(msg); DEBUGBREAK(); } }

	#if defined(_MSC_VER)
		#define VERIFY_ARGS(con, msg, ...) { if (!(con)) { ERROR(msg, __VA_ARGS__); DEBUGBREAK(); } }
	#elif defined(__clang__) || defined(__GNUC__)
		#define VERIFY_ARGS(con, msg, ...) { if (!(con)) { ERROR(msg, ##__VA_ARGS__); DEBUGBREAK(); } }
	#endif
#else
	#define VERIFY(con, msg) con
	#define VERIFY_ARGS(con, msg, ...) con
#endif

#if defined(ENABLE_ASSERTS)
	#define ASSERT(con, msg) { if (!(con)) { ERROR(msg); DEBUGBREAK(); } }

	#if defined(_MSC_VER)
		#define ASSERT_ARGS(con, msg, ...) { if (!(con)) { ERROR(msg, __VA_ARGS__); DEBUGBREAK(); } }
	#elif defined(__clang__) || defined(__GNUC__)
		#define ASSERT_ARGS(con, msg, ...) { if (!(con)) { ERROR(msg, ##__VA_ARGS__); DEBUGBREAK(); } }
	#endif
#else
	#define ASSERT(con, msg) con
	#define ASSERT_ARGS(con, msg, ...) con
#endif