#pragma managed

using namespace System;

namespace MixedAssembly
{
	public ref class NativeCaller
	{
	private:
		String ^textToDisplay;

	public:
		NativeCaller(String ^textToDisplay);

		void CallNativeCode();
	};
}

