#pragma once


#ifdef VOICELIBRARY_EXPORTS
#define VOICELIBRARY_API __declspec(dllexport)
#else
#define VOICELIBRARY_API __declspec(dllimport)
#endif

class VOICELIBRARY_API VoiceLibrary
{
public:
	VoiceLibrary();
	static void recognizeSpeech(char* voiceResult);
};