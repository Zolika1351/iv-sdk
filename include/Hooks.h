namespace plugin
{
	namespace processScriptsEvent
	{
		uintptr_t returnAddress;
		std::list<void(*)()> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f();
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				pushad
				call Run
				popad
				jmp returnAddress
			}
		}
		void Add(void(*funcPtr)())
		{
			funcPtrs.emplace_back(funcPtr);
		}
	};

	namespace gameLoadEvent
	{
		uintptr_t returnAddress;
		std::list<void(*)()> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f();
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				pushad
				call Run
				popad
				jmp returnAddress
			}
		}
		void Add(void(*funcPtr)())
		{
			funcPtrs.emplace_back(funcPtr);
		}
	};

	namespace processAutomobileEvent
	{
		CVehicle* thisParam;
		uintptr_t callAddress;
		std::list<void(*)(CVehicle*)> funcPtrs;

		void Run()
		{
			for (auto& f : funcPtrs)
			{
				f(thisParam);
			}
		}
		void __declspec(naked) MainHook()
		{
			__asm
			{
				mov [thisParam], ecx
				call callAddress
				pushad
				call Run
				popad
				ret
			}
		}
		void Add(void(*funcPtr)(CVehicle*))
		{
			funcPtrs.emplace_back(funcPtr);
		}
	}

	namespace Overrides
	{
		void GetTexture(CSprite2d(__stdcall* funcPtr)(char*))
		{
			injector::MakeJMP(AddressSetter::Get(0x21DA10, 0xD300), funcPtr);
		}
	}
};