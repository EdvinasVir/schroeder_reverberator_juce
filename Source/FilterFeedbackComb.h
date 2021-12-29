/*
  ==============================================================================

    FilterFeedbackComb.h
    Created: 22 Sep 2021 7:28:50am
    Author:  Edvinas

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class FilterFeedbackComb
{
public:
    FilterFeedbackComb();
    ~FilterFeedbackComb();
    void initialise(int filterLength, int samplesPerBlock);
    float* process(int filterLength, float gain, float* audioBlock, int samplesPerBlock);
    void clearBuff();
private:
    int samplesPerBlock = 0;
    int writeIndex = 0;
    int buffLength = 0;
    float* fbBuff = NULL;
    float* output = NULL;
};