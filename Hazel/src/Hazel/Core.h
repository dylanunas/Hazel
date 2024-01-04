#ifndef HAZEL_CORE_H
#define HAZEL_CORE_H

// Exporting the entire Hazel project module as a dynamic library
#ifdef HAZEL_PLATFORM_WINDOWS
	#ifdef HAZEL_BUILD_DLL
		#define HAZEL_API __declspec(dllexport)
	#else 
		#define HAZEL_API __declspec(dllimport)
	#endif // HAZEL_BUILD_DLL
#else
	#error Hazel only supports Windows!
#endif // HAZEL_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#endif // HAZEL_CORE_H