#ifndef BLINK_PCH_H
#define BLINK_PCH_H

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

#ifdef BLINK_PLATFORM_WINDOWS
	#include <Windows.h>
#endif // BLINK_PLATFORM_WINDOWS

#endif // BLINK_PCH_H