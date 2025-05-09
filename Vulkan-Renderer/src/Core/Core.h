#pragma once

#if !defined(PLATFORM_WINDOWS)
	#error Other platforms are not supported yet!
#endif

#if defined(DEBUG_CONFIG)
	#define UNDEFINED_PTR 3722304989
#else
	#define UNDEFINED_PTR 0
#endif

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