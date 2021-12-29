/*
  ==============================================================================

    SchroederRev.h
    Created: 30 Aug 2021 6:00:33pm
    Author:  Edvinas

  ==============================================================================
*/

#pragma once

#include <JuceHeader.h>
#include "FilterAllPass.h"
#include "FilterFeedbackComb.h"
#include "DryWetMixer.h"

class SchroederRev
{
public:
    SchroederRev();
    ~SchroederRev();
    void initialise(float sampleRate, int samplesPerBlock);
    void process(float* audioBlock, int samplesPerBlock, int outputChannelNum);
    void clearBuff();
    void setWet(float value);
    void setSize(float value);

private:
    int samplesPerBlock = 0;
    static const int stagesAllPass = 5; 
    static const int stagesFeedbackComb = 4;
    float wetAmount = 0.0f;
    float lengthAllPass[stagesAllPass] = { 3984, 2418, 1579, 742, 343 };
    float gainAllPass[stagesAllPass] = { 0.0f };

    float lengthFeedbackComb[stagesFeedbackComb] = { 51, 32, 58, 27 };
    float gainFeedbackComb[stagesFeedbackComb] = { 0.0f };
    
    float* drySignal = NULL;
    float** wetSignal = NULL;

    FilterAllPass allPassInstance[stagesAllPass];
    FilterFeedbackComb feedbackCombInstance[stagesFeedbackComb];
    DryWetMixer mixer;
};
