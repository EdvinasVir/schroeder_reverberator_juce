/*
  ==============================================================================

  This is an automatically generated GUI class created by the Projucer!

  Be careful when adding custom code to these files, as only the code within
  the "//[xyz]" and "//[/xyz]" sections will be retained when the file is loaded
  and re-saved.

  Created with Projucer version: 6.0.7

  ------------------------------------------------------------------------------

  The Projucer is part of the JUCE library.
  Copyright (c) 2020 - Raw Material Software Limited.

  ==============================================================================
*/

#pragma once

//[Headers]     -- You can add your own extra header files here --
#include <JuceHeader.h>
#include "PluginProcessor.h"

//[/Headers]



//==============================================================================
/**
                                                                    //[Comments]
    An auto-generated component, created by the Projucer.

    Describe your class and how it works here!
                                                                    //[/Comments]
*/
class SchroederReverbAudioProcessorEditor  : public juce::AudioProcessorEditor,
                                             public juce::Slider::Listener,
                                             public juce::Button::Listener
{
public:
    //==============================================================================
    SchroederReverbAudioProcessorEditor (SchroederReverbAudioProcessor& owner);
    ~SchroederReverbAudioProcessorEditor() override;

    //==============================================================================
    //[UserMethods]     -- You can add your own custom methods in this section.
    //[/UserMethods]

    void paint (juce::Graphics& g) override;
    void resized() override;
    void sliderValueChanged (juce::Slider* sliderThatWasMoved) override;
    void buttonClicked (juce::Button* buttonThatWasClicked) override;



private:
    //[UserVariables]   -- You can add your own custom variables in this section.
    SchroederReverbAudioProcessor& audioProcessor;
    //[/UserVariables]

    //==============================================================================
    std::unique_ptr<juce::Slider> m_sizeSlider;
    std::unique_ptr<juce::Slider> m_wetSlider;
    std::unique_ptr<juce::TextButton> m_clearButton;
    std::unique_ptr<juce::Label> m_textBoxName;
    std::unique_ptr<juce::Label> m_textBoxWet;
    std::unique_ptr<juce::Label> m_textBoxSize;
    std::unique_ptr<juce::Label> m_textBoxVersion;
    std::unique_ptr<juce::Label> m_aboutTextBox;


    //==============================================================================
    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SchroederReverbAudioProcessorEditor)
};

//[EndFile] You can add extra defines here...
//[/EndFile]

