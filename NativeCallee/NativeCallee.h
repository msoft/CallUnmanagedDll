#ifndef NATIVECALLEE_H 
#define NATIVECALLEE_H 

#pragma once 

#ifdef NATIVECALLEE_EXPORTS 
#define NATIVECALLEE_API __declspec(dllexport) 
#else 
#define NATIVECALLEE_API __declspec(dllimport) 
#endif 

extern "C" NATIVECALLEE_API void DisplayTextWithCallee(const wchar_t *textToDisplay);
extern "C" NATIVECALLEE_API void DisplayTextWithCalleeAndReturnCopy(const wchar_t *textToDisplay, wchar_t *const returnedString);

class NativeCallee
{
private:
	wchar_t *textToDisplay;

public:
	NativeCallee(wchar_t *textToDisplay);
	~NativeCallee();

	void DisplayText();
};

#endif /* NATIVECALLEE_H */ 