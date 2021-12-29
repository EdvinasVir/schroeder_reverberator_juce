/*
  ==============================================================================

    SchroederRev.cpp
    Created: 30 Aug 2021 6:00:57pm
    Author:  Edvinas

  ==============================================================================
*/

#include "SchroederRev.h"
#include <math.h>

SchroederRev::SchroederRev() 
{

}

SchroederRev::~SchroederRev() //deallocate memory
{
    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        wetSignal[k] = NULL;
        delete[] wetSignal[k];
    }
    delete [] wetSignal;
    delete drySignal;
    
}

void SchroederRev::initialise(float sampleRate, int inputBlockLength)
{
    samplesPerBlock = inputBlockLength;
    wetSignal = new float* [stagesFeedbackComb];
    drySignal = new float[samplesPerBlock];

    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        wetSignal[k] = new float[samplesPerBlock];
    }

    for (int k = 0; k < stagesAllPass; k++)
    {
        allPassInstance[k].initialise(lengthAllPass[k], samplesPerBlock);
    }

    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        feedbackCombInstance[k].initialise(lengthFeedbackComb[k], samplesPerBlock);
    }

    for (int k = 0; k < stagesAllPass; k++)
    {
        gainAllPass[k] = 0.5;   //initial values
    }

    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        gainFeedbackComb[k] = 0.4;  //initial values
    }
}

void SchroederRev::process(float* audioBlock, int samplesPerBlock, int outputChannelNum)  //main callback function
{   
    for (int n = 0; n < samplesPerBlock; n++)
    {
        drySignal[n] = audioBlock[n];
    }
    
    for(int k = 0; k < stagesAllPass; k++)
    {
        allPassInstance[k].process(lengthAllPass[k], gainAllPass[k], audioBlock, samplesPerBlock);
    }
    
    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        wetSignal[k] = feedbackCombInstance[k].process(lengthFeedbackComb[k], gainFeedbackComb[k], audioBlock, samplesPerBlock);
    }
    
    mixer.process(audioBlock, wetSignal, drySignal, wetAmount, stagesFeedbackComb, outputChannelNum, samplesPerBlock);
    
}

void SchroederRev::clearBuff()
{
    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        feedbackCombInstance[k].clearBuff();
    }

    for (int k = 0; k < stagesAllPass; k++)
    {
        allPassInstance[k].clearBuff();
    }
    
    for (int k = 0; k < stagesFeedbackComb; k++)
    {
        for (int n = 0; n < samplesPerBlock; n++)
        {
            wetSignal[k][n] = 0.0f;
        }
    }
}

void SchroederRev::setWet(float value)
{
    wetAmount = value;
}

void SchroederRev::setSize(float value)
{
    for (int n = 0; n < stagesAllPass; n++)
    {
        gainAllPass[n] = value;
    } 
}

