/*
  ==============================================================================

    dryWetMixer.h
    Created: 27 Sep 2021 2:50:56pm
    Author:  Edvinas

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>

class DryWetMixer
{
public:
    void process(float* audioBlock, float** wetSignal, float* drySignal, float wet, int numStages, int numOutChannel, int samplesPerBlock);


private:


};