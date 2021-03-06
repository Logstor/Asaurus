#pragma once

// Most used standard libraries
#include <memory>
#include <stdio.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <utility>
#include <chrono>

#include <string>
#include <sstream>
#include <array>
#include <vector>
#include <unordered_map>
#include <unordered_set>

// Made for this project
#include "Asaurus/Core/Log.h"
#include "Asaurus/Debug/Instrumentor.h"

// Extra libraries depending on platform
#ifdef AS_PLATFORM_WINDOWS
	#include <Windows.h>
#endif
