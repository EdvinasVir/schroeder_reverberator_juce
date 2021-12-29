/*
  ==============================================================================

    This file contains the basic framework code for a JUCE plugin processor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"

//==============================================================================
SchroederReverbAudioProcessor::SchroederReverbAudioProcessor()
#ifndef JucePlugin_PreferredChannelConfigurations
     : AudioProcessor (BusesProperties()
                     #if ! JucePlugin_IsMidiEffect
                      #if ! JucePlugin_IsSynth
                       .withInput  ("Input",  juce::AudioChannelSet::stereo(), true)
                      #endif
                       .withOutput ("Output", juce::AudioChannelSet::stereo(), true)
                     #endif
                       )
#endif
{
}

SchroederReverbAudioProcessor::~SchroederReverbAudioProcessor()
{
}

//==============================================================================
const juce::String SchroederReverbAudioProcessor::getName() const
{
    return JucePlugin_Name;
}

bool SchroederReverbAudioProcessor::acceptsMidi() const
{
   #if JucePlugin_WantsMidiInput
    return true;
   #else
    return false;
   #endif
}

bool SchroederReverbAudioProcessor::producesMidi() const
{
   #if JucePlugin_ProducesMidiOutput
    return true;
   #else
    return false;
   #endif
}

bool SchroederReverbAudioProcessor::isMidiEffect() const
{
   #if JucePlugin_IsMidiEffect
    return true;
   #else
    return false;
   #endif
}

double SchroederReverbAudioProcessor::getTailLengthSeconds() const
{
    return 0.0;
}

int SchroederReverbAudioProcessor::getNumPrograms()
{
    return 1;   // NB: some hosts don't cope very well if you tell them there are 0 programs,
                // so this should be at least 1, even if you're not really implementing programs.
}

int SchroederReverbAudioProcessor::getCurrentProgram()
{
    return 0;
}

void SchroederReverbAudioProcessor::setCurrentProgram (int index)
{
}

const juce::String SchroederReverbAudioProcessor::getProgramName (int index)
{
    return {};
}

void SchroederReverbAudioProcessor::changeProgramName (int index, const juce::String& newName)
{
}

//==============================================================================
void SchroederReverbAudioProcessor::prepareToPlay (double sampleRate, int samplesPerBlock)
{
    // Use this method as the place to do any pre-playback
    m_schroederRevInstanceL.initialise(sampleRate, samplesPerBlock);
    m_schroederRevInstanceR.initialise(sampleRate, samplesPerBlock);
    
    // initialisation that you need..
}

void SchroederReverbAudioProcessor::releaseResources()
{
    // When playback stops, you can use this as an opportunity to free up any
    // spare memory, etc.
}

#ifndef JucePlugin_PreferredChannelConfigurations
bool SchroederReverbAudioProcessor::isBusesLayoutSupported (const BusesLayout& layouts) const
{
  #if JucePlugin_IsMidiEffect
    juce::ignoreUnused (layouts);
    return true;
  #else
    // This is the place where you check if the layout is supported.
    // In this template code we only support mono or stereo.
    // Some plugin hosts, such as certain GarageBand versions, will only
    // load plugins that support stereo bus layouts.
    if (layouts.getMainOutputChannelSet() != juce::AudioChannelSet::mono()
     && layouts.getMainOutputChannelSet() != juce::AudioChannelSet::stereo())
        return false;

    // This checks if the input layout matches the output layout
   #if ! JucePlugin_IsSynth
    if (layouts.getMainOutputChannelSet() != layouts.getMainInputChannelSet())
        return false;
   #endif

    return true;
  #endif
}
#endif

void SchroederReverbAudioProcessor::processBlock (juce::AudioBuffer<float>& buffer, juce::MidiBuffer& midiMessages)
{
    //juce::ScopedNoDenormals noDenormals;
    auto totalNumInputChannels = getTotalNumInputChannels();
    auto totalNumOutputChannels = getTotalNumOutputChannels();

    for (auto i = totalNumInputChannels; i < totalNumOutputChannels; ++i)
        buffer.clear(i, 0, buffer.getNumSamples());

    // This is the place where you'd normally do the guts of your plugin's
    // audio processing...
    // Make sure to reset the state if your inner loop is processing
    // the samples and the outer loop is handling the channels.
    // Alternatively, you can process the samples with the channels
    // interleaved by keeping the same state.
    //for (int channel = 0; channel < totalNumInputChannels; ++channel)
    //{
    //    auto* inputChannelData = buffer.getWritePointer(channel);
    //    int lengthBuff = buffer.getNumSamples();

    //    algorithmicRevInstance.process(inputChannelData, lengthBuff);
    //    // ..do something to the data...
    //}

    float* leftData = buffer.getWritePointer(1);
    float* rightData = buffer.getWritePointer(0);
    int samplesPerBlock = buffer.getNumSamples();

    m_schroederRevInstanceL.process(leftData, samplesPerBlock, 0); //third argument is output channel number (0-1)
    m_schroederRevInstanceR.process(rightData, samplesPerBlock, 1);
}

//==============================================================================
bool SchroederReverbAudioProcessor::hasEditor() const
{
    return true; // (change this to false if you choose to not supply an editor)
}

juce::AudioProcessorEditor* SchroederReverbAudioProcessor::createEditor()
{
    return new SchroederReverbAudioProcessorEditor (*this);
}

//==============================================================================
void SchroederReverbAudioProcessor::getStateInformation (juce::MemoryBlock& destData)
{
    // You should use this method to store your parameters in the memory block.
    // You could do that either as raw data, or use the XML or ValueTree classes
    // as intermediaries to make it easy to save and load complex data.
}

void SchroederReverbAudioProcessor::setStateInformation (const void* data, int sizeInBytes)
{
    // You should use this method to restore your parameters from this memory block,
    // whose contents will have been created by the getStateInformation() call.
}

//==============================================================================
// This creates new instances of the plugin..
juce::AudioProcessor* JUCE_CALLTYPE createPluginFilter()
{
    return new SchroederReverbAudioProcessor();
}
void SchroederReverbAudioProcessor::updateParameters(int param, float value)
{
    if (param == kSize)
    {
        m_schroederRevInstanceL.setSize(value);
        m_schroederRevInstanceR.setSize(value);
    }

    if (param == kWet)
    {
        m_schroederRevInstanceL.setWet(value);
        m_schroederRevInstanceR.setWet(value);
    }

    if (param == kClearBuff)
    {
    m_schroederRevInstanceL.clearBuff();
    m_schroederRevInstanceR.clearBuff();
    }           
}
