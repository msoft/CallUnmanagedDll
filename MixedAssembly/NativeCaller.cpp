#pragma managed

#include "NativeCaller.h"
#include "NativeCallee.h"

#include <stdio.h>
#include <stdlib.h>
#include <vcclr.h>

using namespace System::Runtime::InteropServices;

MixedAssembly::NativeCaller::NativeCaller(String ^textToDisplay)
{
	this->textToDisplay = textToDisplay;
}

void MixedAssembly::NativeCaller::NativeCaller::CallNativeCode()
{
	pin_ptr<const wchar_t> convertedString = PtrToStringChars(this->textToDisplay);

	NativeCallee *callee = new NativeCallee(const_cast<wchar_t*>(convertedString));
	callee->DisplayText();
	delete callee;
}
