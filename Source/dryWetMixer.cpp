/*
  ==============================================================================

    dryWetMixer.cpp
    Created: 27 Sep 2021 2:50:56pm
    Author:  Edvinas

  ==============================================================================
*/

#include "dryWetMixer.h"

void DryWetMixer::process(float* audioBlock, float** wetSignal, float* drySignal, float wet, int numStages, int numOutChannel, int samplesPerBlock)
{
    for (int n = 0; n < samplesPerBlock; n++)
    {
        audioBlock[n] = ((1 - wet) * drySignal[n]) + (wetSignal[numOutChannel][n] * wet);
    }
}