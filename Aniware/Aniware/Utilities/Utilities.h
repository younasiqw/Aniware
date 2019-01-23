#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

namespace Aniware { 

	class CUtilities {
	public:

		void ConsoleLog(const std::string&);
		void* GetInterface(char*, char*);

		template <typename T>
		T VirtualFunction(void*, int);

	};
}