#pragma once

#include "..\Classes\IClientNetworkable.h"
#include "..\Classes\EStructs.h"

namespace SDK {

	class ClientClass;
	class RecvTable;

	typedef IClientNetworkable* (*CreateClientClassFn)(int entnum, int serialNum);
	typedef IClientNetworkable* (*CreateEventFn)();

	class ClientClass {
	public:

		CreateClientClassFn      pCreateFn;
		CreateEventFn            pCreateEventFn;
		char*                    pNetworkName;
		RecvTable*				 pRecvTable;
		ClientClass*             pNext;
		EClassIds                ClassID;

	};
}