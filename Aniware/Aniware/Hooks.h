#pragma once

#include "..\Aniware\Classes\IClientEntity.h"
#include "..\Aniware\Classes\IClientEntityList.h"
#include "..\Aniware\Classes\ISurface.h"
#include "..\Aniware\Classes\IVEngineClient.h"
#include "..\Aniware\Classes\IClientMode.h"
#include "..\Aniware\Classes\CInput.h"
#include "..\Aniware\Interfaces.h"

namespace Aniware {

	class VMTHook;
	class Hooks {
	public:
		
		static void Init();
		static void Restore();

		static bool __fastcall CreateMove(SDK::IClientMode*, void*, float, SDK::CUserCmd*);

	private:
		std::unique_ptr<VMTHook> pClientModeHook;
		std::unique_ptr<VMTHook> pSurfaceHook;

		typedef bool(__fastcall* CreateMove_t)(SDK::IClientMode*, void*, float, SDK::CUserCmd*);
		//typedef void(__fastcall* LockCursor_t) (ISurface*, void*);
	};

	extern Hooks g_Hooks;

	class VMTHook {
	public:

		VMTHook(void* ppClass) {

			this->ppBaseClass = static_cast<std::uintptr_t**>(ppClass);

			while (static_cast<std::uintptr_t*>(*this->ppBaseClass)[this->indexCount])
				++this->indexCount;

			const std::size_t kSizeTable = this->indexCount * sizeof(std::uintptr_t);

			this->pOriginalVMT = *this->ppBaseClass;
			this->pNewVMT = std::make_unique<std::uintptr_t[]>(this->indexCount);

			std::memcpy(this->pNewVMT.get(), this->pOriginalVMT, kSizeTable);
			*this->ppBaseClass = this->pNewVMT.get();

		};
		
		~VMTHook() { *this->ppBaseClass = this->pOriginalVMT; };

		template <class Type>
		Type GetOriginal(const std::size_t index) {

			return reinterpret_cast<Type>(this->pOriginalVMT[index]);

		};

		HRESULT Hook(const std::size_t index, void* fnNew) {
		
			if (index > this->indexCount)
				return E_INVALIDARG;

			this->pNewVMT[index] = reinterpret_cast<std::uintptr_t>(fnNew);
			return S_OK;

		};

		HRESULT Unhook(const std::size_t index) {
			
			if (index > this->indexCount)
				return E_INVALIDARG;

			this->pNewVMT[index] = this->pOriginalVMT[index];
			return S_OK;

		};

	private:
		
		std::unique_ptr<std::uintptr_t[]> pNewVMT = nullptr;
		std::uintptr_t** ppBaseClass = nullptr;
		std::uintptr_t* pOriginalVMT = nullptr;
		std::size_t indexCount = 0;
	
	};
}