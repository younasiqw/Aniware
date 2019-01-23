#include "Utilities.h"

namespace Aniware {

	void* CUtilities::GetInterface(char* szModule, char* szInterface) {

		typedef void * (*oInterface_t)(char*, int);
		oInterface_t original = (oInterface_t)GetProcAddress(GetModuleHandleA(szModule), "CreateInterface");

		return (void*)original(szInterface, 0);
	}

	void CUtilities::ConsoleLog(const std::string& szOutput) {

		std::cout << "[*] " << szOutput << std::endl;

	}

	template <typename T>
	T CUtilities::VirtualFunction(void* pClass, int iIndex) {

		PDWORD pVTable = *(PDWORD*)pClass;
		DWORD dwAddress = pVTable[iIndex];

		return (T)(dwAddress);
	}
}