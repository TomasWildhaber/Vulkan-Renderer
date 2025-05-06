#pragma once
#include "Log.h"

#if defined(_MSC_VER)
	#define DEBUGBREAK() __debugbreak();
#elif defined(__clang__)
	#if defined(__has_builtin)
		#if __has_builtin(__builtin_debugtrap)
			#define DEBUGBREAK() __builtin_debugtrap()
		#else
			#define DEBUGBREAK() raise(SIGTRAP)
		#endif
	#else
		#define DEBUGBREAK() raise(SIGTRAP)
	#endif
#elif defined(__GNUC__)
	#if defined(__i386__) || defined(__x86_64__)
		#define DEBUGBREAK() __asm__ __volatile__("int $3")
	#else
		#define DEBUGBREAK() raise(SIGTRAP)
	#endif
#else
	#error Other compilers are not supported yet!
#endif

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

#if defined(ENABLE_ASSERTS) && defined(DEBUG_CONFIG)
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