#include "SpeechRecognitionAPI.h"
#include <iostream>

SpeechRecognitionAPI::SpeechRecognitionAPI()
{
    CoInitialize(NULL);
    CoCreateInstance(CLSID_SpRecognizer, NULL, CLSCTX_ALL, IID_ISpRecognizer, (void**)&recognizer);
    recognizer->CreateRecoContext(&recoContext);
    recoContext->SetAudioOptions(SPAO_RETAIN_AUDIO, NULL, NULL);
    recoContext->SetNotifyWin32Event();
    HANDLE eventHandle = recoContext->GetNotifyEventHandle();
    WaitForSingleObject(eventHandle, INFINITE);
}

SpeechRecognitionAPI::~SpeechRecognitionAPI()
{
    recoContext->Release();
    recognizer->Release();
    CoUninitialize();
}

void SpeechRecognitionAPI::StartRecognition()
{
    recoContext->SetRecoState(SPRST_ACTIVE_ALWAYS);
}

void SpeechRecognitionAPI::StopRecognition()
{
    recoContext->SetRecoState(SPRST_INACTIVE);
}

void SpeechRecognitionAPI::ProcessRecognizedSpeech()
{
    SPPHRASE* phrase;
    if (SUCCEEDED(recoContext->GetEvents(1, (SPEVENT*)&phrase, NULL)))
    {
        if (phrase->pElements != NULL)
        {
            std::wstring recognizedText(phrase->pElements[0].pszDisplayText);
            std::wcout << "Recognized: " << recognizedText << std::endl;
        }

        ::CoTaskMemFree(phrase);
    }
}
