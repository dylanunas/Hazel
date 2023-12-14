#ifndef BLINK_CORE_H
#define BLINK_CORE_H

#ifdef BLINK_PLATFORM_WINDOWS
	#ifdef BLINK_BUILD_DLL
		#define BLINK_API __declspec(dllexport)
	#else 
		#define BLINK_API __declspec(dllimport)
	#endif // BLINK_BUILD_DLL
#else
	#error Blink only supports Windows!
#endif // BLINK_PLATFORM_WINDOWS

#endif // BLINK_CORE_H