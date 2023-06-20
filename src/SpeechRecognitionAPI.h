#ifndef SPEECH_RECOGNITION_API_H
#define SPEECH_RECOGNITION_API_H

#include <sapi.h>

class SpeechRecognitionAPI
{
private:
    ISpRecognizer* recognizer;
    ISpRecoContext* recoContext;

public:
    SpeechRecognitionAPI();
    ~SpeechRecognitionAPI();

    void StartRecognition();
    void StopRecognition();
    void ProcessRecognizedSpeech();
};

#endif // SPEECH_RECOGNITION_API_H
