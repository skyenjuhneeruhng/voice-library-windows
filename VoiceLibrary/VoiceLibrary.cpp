// VoiceLibrary.cpp : Defines the exported functions for the DLL application.
//

#include "stdafx.h"
#include "VoiceLibrary.h"
#include <iostream>
#include <speechapi_cxx.h>
using namespace std;
using namespace Microsoft::CognitiveServices::Speech;

VoiceLibrary::VoiceLibrary()
{

}

void VoiceLibrary::recognizeSpeech(char* voiceResult)
{
	// Creates an instance of a speech factory with specified
	// subscription key and service region. Replace with your own subscription key
	// and service region (e.g., "westus").
	//b5802c0754e34d269359e601aa29111e
	//80860cbc367e4572a61b673ea61433aa
	auto factory = SpeechFactory::FromSubscription(L"80860cbc367e4572a61b673ea61433aa", L"westus");

	// Creates a speech recognizer.
	auto recognizer = factory->CreateSpeechRecognizer();
	wcout << L"Say something...\n";

	// Performs recognition.
	// RecognizeAsync() returns when the first utterance has been recognized, so it is suitable 
	// only for single shot recognition like command or query. For long-running recognition, use
	// StartContinuousRecognitionAsync() instead.
	auto result = recognizer->RecognizeAsync().get();

	// Checks result.
	if (result->Reason != Reason::Recognized)
	{
		wcout << L"Recognition Status: " << int(result->Reason) << L". ";
		if (result->Reason == Reason::Canceled)
		{
			wcout << L"There was an error, reason: " << result->ErrorDetails.c_str() << std::endl;
			voiceResult[0] = '\0';
		}
		else
		{
			wcout << L"No speech could be recognized.\n";
			voiceResult[0] = '\0';
		}
	}
	else {
		
		for (int i = 0; i < wcslen(result->Text.c_str()); i++)
		{
			voiceResult[i] = (char)(result->Text.c_str()[i]);
		}
		voiceResult[wcslen(result->Text.c_str())] = '\0';
		wcout << L"We recognized: " << result->Text << std::endl;
	}
}