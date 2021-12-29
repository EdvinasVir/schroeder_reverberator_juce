/*
  ==============================================================================

    FilterAllPass.h
    Created: 22 Sep 2021 6:30:53am
    Author:  Edvinas

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class FilterAllPass
{
public:
    FilterAllPass();
    ~FilterAllPass();
    void initialise(int filterLength, int samplesPerBlock);
    void process(int filterLength, float gain, float* audioBlock, int samplesPerBlock);
    void clearBuff();
private:
    int buffLength = 0;
    int samplesPerBlock = 0;
    int writeIndex = 0;
    float* ffBuff = NULL;
    float* fbBuff = NULL;
    float* output = NULL;
};
