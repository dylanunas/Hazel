#ifndef BLINK_CORE_H
#define BLINK_CORE_H

// Exporting the entire Blink project module as a dynamic library
#ifdef BLINK_PLATFORM_WINDOWS
	#ifdef BLINK_BUILD_DLL
		#define BLINK_API __declspec(dllexport)
	#else 
		#define BLINK_API __declspec(dllimport)
	#endif // BLINK_BUILD_DLL
#else
	#error Blink only supports Windows!
#endif // BLINK_PLATFORM_WINDOWS

#define BIT(x) (1 << x)

#endif // BLINK_CORE_H