#include "NativeCallee.h"

#include <wchar.h> 
#include <iostream>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

void DisplayTextWithCallee(const wchar_t *textToDisplay)
{
	NativeCallee *callee = new NativeCallee(const_cast<wchar_t*>(textToDisplay));
	callee->DisplayText();
	delete callee;
}

void DisplayTextWithCalleeAndReturnCopy(const wchar_t *textToDisplay, wchar_t *const returnedString)
{
	NativeCallee *callee = new NativeCallee(const_cast<wchar_t*>(textToDisplay));
	callee->DisplayText();
	delete callee;

	size_t stringLength = wcslen(textToDisplay);
	wcscpy_s(returnedString, stringLength + 1, textToDisplay);
}


NativeCallee::NativeCallee(wchar_t *textToDisplay)
{
	this->textToDisplay = textToDisplay;
}

NativeCallee::~NativeCallee()
{
}

void NativeCallee::DisplayText()
{
	_setmode(_fileno(stdout), _O_U16TEXT);
	wprintf(L"Displaying from unmanaged code: %s\n", this->textToDisplay);
}