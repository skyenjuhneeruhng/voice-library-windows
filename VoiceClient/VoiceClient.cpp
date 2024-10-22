// VoiceClient.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include "VoiceLibrary.h"
#include <string>
#include <Windows.h>
HANDLE threadHandle;
DWORD threadID;
bool isRunning;
void threadBegin();
void threadEnd();
DWORD threadProc();
static DWORD WINAPI voiceThreadProc();

int main()
{
	threadBegin();
	while (isRunning)
	{

	}
}
void threadBegin()
{
	if (threadHandle)
	{
		threadEnd();
	}
	isRunning = true;
	threadHandle = CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)voiceThreadProc, NULL, 0, (LPDWORD)&threadID);
	if (threadHandle == NULL)
	{
		return;
		isRunning = false;
	}

}
void threadEnd()
{
	if (threadHandle != NULL)
	{
		isRunning = false;
		WaitForSingleObject(threadHandle, INFINITE);
		CloseHandle(threadHandle);
		threadHandle = NULL;
	}
}
DWORD threadProc()
{
	char *voiceResult = new char[128];
	do
	{
		VoiceLibrary::recognizeSpeech(voiceResult);
		printf("%s", voiceResult);
		
	} while (isRunning);
	return 0;
}
static DWORD WINAPI voiceThreadProc()
{
	return threadProc();
}
// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
