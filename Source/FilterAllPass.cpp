/*
  ==============================================================================

    FilterAllPass.cpp
    Created: 22 Sep 2021 6:30:53am
    Author:  Edvinas

  ==============================================================================
*/

#include "FilterAllPass.h"
#include <math.h>

FilterAllPass::FilterAllPass()
{
    
}

FilterAllPass::~FilterAllPass() //deallocate memory
{
    delete[] ffBuff;
    delete[] fbBuff;
    delete[] output;
}

void FilterAllPass::initialise(int filterLength, int inputBlockLength)
{
    samplesPerBlock = inputBlockLength;
    buffLength = filterLength + samplesPerBlock - 1;  
    
    //dynamically allocate memory for the arrays
    ffBuff = new float[buffLength];
    fbBuff = new float[buffLength];
    output = new float[samplesPerBlock];
}

void FilterAllPass::process(int filterLength, float gain, float* audioBlock, int samplesPerBlock)
{
    for (int n = 0; n < samplesPerBlock; n++) 
    {
        float acc = 0.0f;
        int buffLength = filterLength + samplesPerBlock - 1;
        int delayIndex = (writeIndex - filterLength - 1 + buffLength) % buffLength; //track the delayed sample position in the circular buffer

        ffBuff[writeIndex] = audioBlock[n];

        acc += audioBlock[n] * gain;
        acc += ffBuff[delayIndex];
        acc -= fbBuff[delayIndex] * gain;

        fbBuff[writeIndex] = acc;
        audioBlock[n] = acc;

        writeIndex += 1;
        if (writeIndex >= buffLength)
            writeIndex = 0;
    }
}

void FilterAllPass::clearBuff()
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