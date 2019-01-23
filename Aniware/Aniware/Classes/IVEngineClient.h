#pragma once

#include "..\Utilities\Globals.h"

namespace SDK {

	class IVEngineClient {
	public:

		void GetScreenSize(int& width, int& height) {

			typedef int(__thiscall *OrigFn)(void*, int&, int&);
			Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 5)(this, width, height);
		
		}

		int GetLocalPlayer() {

			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 12)(this);
	
		}

		float GetLastTimeStamp() {

			typedef float(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 14)(this);
		
		}

		int GetMaxClients() {

			typedef int(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 20)(this);
		
		}

		bool isInGame() {

			typedef bool(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 26)(this);
		
		}

		bool isConnected() {

			typedef bool(__thiscall *OrigFn)(void*);
			return Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 27)(this);
		
		}

		void ExecuteClientCmd(const char* szCmdString) {

			typedef void(__thiscall *OrigFn)(void*, const char *);
			Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 108)(this, szCmdString);
		
		}

		void ClientCmd_Unrestricted(const char* szCmdString) {

			typedef void(__thiscall* OrigFn)(void*, const char*, char);
			Aniware::g_pCUtilities->VirtualFunction<OrigFn>(this, 114)(this, szCmdString, 1);

		}
	};
}