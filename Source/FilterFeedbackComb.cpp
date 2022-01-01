/*
  ==============================================================================

    FilterFeedbackComb.cpp
    Created: 22 Sep 2021 7:28:50am
    Author:  Edvinas

  ==============================================================================
*/

#include "FilterFeedbackComb.h"
#include <math.h>

FilterFeedbackComb::FilterFeedbackComb()
{
    
}

FilterFeedbackComb::~FilterFeedbackComb() //deallocate memory
{
    delete[] output;
    delete[] fbBuff;
}

void FilterFeedbackComb::initialise(int filterLength, int inputBlockLength)
{
    samplesPerBlock = inputBlockLength;
    buffLength = filterLength + samplesPerBlock - 1;

    fbBuff = new float[buffLength];
    output = new float[samplesPerBlock];
}

float* FilterFeedbackComb::process(int filterLength, float gain, float* audioBlock, int samplesPerBlock) 
{
    for (int n = 0; n < samplesPerBlock; n++)  //circular buffer
    {
        float acc = 0.0f;
        int buffLength = filterLength + samplesPerBlock - 1;

        int delayIndex = (writeIndex - (filterLength - 1) + buffLength) % buffLength;

        acc += audioBlock[n];
        acc -= fbBuff[delayIndex] * gain;

        fbBuff[writeIndex] = acc;
        output[n] = acc;

        writeIndex += 1;
        if (writeIndex >= buffLength)
            writeIndex = 0;
    }
    return output;
}

void FilterFeedbackComb::clearBuff()
{
    for (int n = 0; n < buffLength; n++)
    {
        fbBuff[n] = 0.0f;
    }

    for (int n = 0; n < samplesPerBlock; n++)
    {
        output[n] = 0;
    }
}
