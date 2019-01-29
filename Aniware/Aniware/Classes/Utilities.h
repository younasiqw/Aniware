#pragma once

#include <Windows.h>
#include <iostream>
#include <string>

namespace Aniware { 

	namespace Utilities {

		template <typename T>
		static T* GetInterface(char* szModule, char* szInterface) {

			typedef void * (*oInterface_t)(char*, int);
			oInterface_t original = (oInterface_t)GetProcAddress(GetModuleHandleA(szModule), "CreateInterface");

			return (T*)original(szInterface, 0);
		}

		static void ConsoleLog(const std::string& szOutput) {

			std::cout << "[*] " << szOutput << std::endl;

		}

		template <typename T>
		static T VirtualFunction(void* pClass, int iIndex) {

			PDWORD pVTable = *(PDWORD*)pClass;
			DWORD dwAddress = pVTable[iIndex];

			return (T)(dwAddress);
		}
	}
}