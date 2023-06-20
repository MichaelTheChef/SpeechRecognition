#include "SpeechRecognitionAPI.h"
#include <iostream>

int main()
{
    SpeechRecognitionAPI speechRecognitionAPI;

    speechRecognitionAPI.StartRecognition();

    std::cout << "Speech Recognition API started. Press any key to stop..." << std::endl;
    std::cin.get();

    speechRecognitionAPI.StopRecognition();

    return 0;
}
