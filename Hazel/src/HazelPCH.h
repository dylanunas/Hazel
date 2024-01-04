#ifndef HAZEL_PCH_H
#define HAZEL_PCH_H

// general stuff
#include <iostream>
#include <memory>
#include <functional>
#include <utility>
#include <algorithm>
#include <sstream>

// data structures
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

#ifdef HAZEL_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // HAZEL_PLATFORM_WINDOWS

#endif // HAZEL_PCH_H