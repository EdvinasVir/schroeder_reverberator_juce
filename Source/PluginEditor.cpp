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

//[Headers] You can add your own extra header files here...
//[/Headers]

#include "PluginEditor.h"


//[MiscUserDefs] You can add your own user definitions and misc code here...
//[/MiscUserDefs]

//==============================================================================
SchroederReverbAudioProcessorEditor::SchroederReverbAudioProcessorEditor (SchroederReverbAudioProcessor& owner)
    : AudioProcessorEditor(owner), audioProcessor(owner)
{
    //[Constructor_pre] You can add your own custom stuff here..
    //[/Constructor_pre]

    m_sizeSlider.reset (new juce::Slider ("sizeSlider"));
    addAndMakeVisible (m_sizeSlider.get());
    m_sizeSlider->setRange (0.6, 0.85, 0);
    m_sizeSlider->setSliderStyle (juce::Slider::LinearVertical);
    m_sizeSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    m_sizeSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    m_sizeSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffff8e50));
    m_sizeSlider->setColour (juce::Slider::trackColourId, juce::Colours::white);
    m_sizeSlider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    m_sizeSlider->setColour (juce::Slider::textBoxTextColourId, juce::Colours::white);
    m_sizeSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x77ffffff));
    m_sizeSlider->addListener (this);

    m_sizeSlider->setBounds (8, 104, 104, 96);

    m_wetSlider.reset (new juce::Slider ("wetSlider"));
    addAndMakeVisible (m_wetSlider.get());
    m_wetSlider->setRange (0, 1, 0);
    m_wetSlider->setSliderStyle (juce::Slider::RotaryHorizontalVerticalDrag);
    m_wetSlider->setTextBoxStyle (juce::Slider::NoTextBox, true, 80, 20);
    m_wetSlider->setColour (juce::Slider::backgroundColourId, juce::Colours::white);
    m_wetSlider->setColour (juce::Slider::thumbColourId, juce::Colour (0xffffc158));
    m_wetSlider->setColour (juce::Slider::trackColourId, juce::Colours::white);
    m_wetSlider->setColour (juce::Slider::rotarySliderFillColourId, juce::Colours::white);
    m_wetSlider->setColour (juce::Slider::rotarySliderOutlineColourId, juce::Colours::white);
    m_wetSlider->setColour (juce::Slider::textBoxTextColourId, juce::Colours::white);
    m_wetSlider->setColour (juce::Slider::textBoxBackgroundColourId, juce::Colour (0x00ffffff));
    m_wetSlider->setColour (juce::Slider::textBoxHighlightColourId, juce::Colour (0x00ffffff));
    m_wetSlider->setColour (juce::Slider::textBoxOutlineColourId, juce::Colour (0x79ffffff));
    m_wetSlider->addListener (this);

    m_wetSlider->setBounds (148, 80, 104, 144);

    m_clearButton.reset (new juce::TextButton ("clearButton"));
    addAndMakeVisible (m_clearButton.get());
    m_clearButton->setButtonText (TRANS("Clear"));
    m_clearButton->setConnectedEdges (juce::Button::ConnectedOnRight);
    m_clearButton->addListener (this);
    m_clearButton->setColour (juce::TextButton::buttonColourId, juce::Colour (0xffeee480));
    m_clearButton->setColour (juce::TextButton::buttonOnColourId, juce::Colour (0x00ffffff));
    m_clearButton->setColour (juce::TextButton::textColourOffId, juce::Colours::white);

    m_clearButton->setBounds (296, 136, 56, 32);

    m_textBoxName.reset (new juce::Label ("textBoxName",
                                          TRANS("Schroeder\n"
                                          "Reverberator")));
    addAndMakeVisible (m_textBoxName.get());
    m_textBoxName->setFont (juce::Font ("Eras ITC", 38.20f, juce::Font::italic));
    m_textBoxName->setJustificationType (juce::Justification::centredLeft);
    m_textBoxName->setEditable (false, false, false);
    m_textBoxName->setColour (juce::Label::textColourId, juce::Colours::white);
    m_textBoxName->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_textBoxName->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_textBoxName->setBounds (64, 8, 280, 80);

    m_textBoxWet.reset (new juce::Label ("textBoxWet",
                                         TRANS("Dry/Wet")));
    addAndMakeVisible (m_textBoxWet.get());
    m_textBoxWet->setFont (juce::Font (juce::Font::getDefaultSansSerifFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_textBoxWet->setJustificationType (juce::Justification::centred);
    m_textBoxWet->setEditable (false, false, false);
    m_textBoxWet->setColour (juce::Label::textColourId, juce::Colours::white);
    m_textBoxWet->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_textBoxWet->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_textBoxWet->setBounds (162, 192, 72, 24);

    m_textBoxSize.reset (new juce::Label ("textBoxSize",
                                          TRANS("Size")));
    addAndMakeVisible (m_textBoxSize.get());
    m_textBoxSize->setFont (juce::Font (juce::Font::getDefaultSansSerifFontName(), 15.00f, juce::Font::plain).withTypefaceStyle ("Regular"));
    m_textBoxSize->setJustificationType (juce::Justification::centred);
    m_textBoxSize->setEditable (false, false, false);
    m_textBoxSize->setColour (juce::Label::textColourId, juce::Colours::white);
    m_textBoxSize->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_textBoxSize->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_textBoxSize->setBounds (24, 192, 72, 24);

    m_textBoxVersion.reset (new juce::Label ("textBoxVersion",
                                             TRANS("V1.0")));
    addAndMakeVisible (m_textBoxVersion.get());
    m_textBoxVersion->setFont (juce::Font ("Eras ITC", 18.70f, juce::Font::italic));
    m_textBoxVersion->setJustificationType (juce::Justification::centredLeft);
    m_textBoxVersion->setEditable (false, false, false);
    m_textBoxVersion->setColour (juce::Label::textColourId, juce::Colours::white);
    m_textBoxVersion->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_textBoxVersion->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_textBoxVersion->setBounds (256, 32, 88, 80);

    m_aboutTextBox.reset (new juce::Label ("aboutTextBox",
                                           TRANS("This is an implementatio of Schroeder reverberator algorithm JCREV developed by Prof. John Chowning. https://ccrma.stanford.edu\n"
                                           "/~jos/pasp/Schroeder_Reverberators.html")));
    addAndMakeVisible (m_aboutTextBox.get());
    m_aboutTextBox->setFont (juce::Font (15.00f, juce::Font::plain).withTypefaceStyle ("Italic"));
    m_aboutTextBox->setJustificationType (juce::Justification::centredLeft);
    m_aboutTextBox->setEditable (false, false, false);
    m_aboutTextBox->setColour (juce::Label::textColourId, juce::Colours::white);
    m_aboutTextBox->setColour (juce::TextEditor::textColourId, juce::Colours::black);
    m_aboutTextBox->setColour (juce::TextEditor::backgroundColourId, juce::Colour (0x00000000));

    m_aboutTextBox->setBounds (32, 224, 336, 72);


    //[UserPreSize]
    //[/UserPreSize]

    setSize (400, 300);


    //[Constructor] You can add your own custom stuff here..
    //[/Constructor]
}

SchroederReverbAudioProcessorEditor::~SchroederReverbAudioProcessorEditor()
{
    //[Destructor_pre]. You can add your own custom destruction code here..
    //[/Destructor_pre]

    m_sizeSlider = nullptr;
    m_wetSlider = nullptr;
    m_clearButton = nullptr;
    m_textBoxName = nullptr;
    m_textBoxWet = nullptr;
    m_textBoxSize = nullptr;
    m_textBoxVersion = nullptr;
    m_aboutTextBox = nullptr;


    //[Destructor]. You can add your own custom destruction code here..
    //[/Destructor]
}

//==============================================================================
void SchroederReverbAudioProcessorEditor::paint (juce::Graphics& g)
{
    //[UserPrePaint] Add your own custom painting code here..
    //[/UserPrePaint]

    g.fillAll (juce::Colour (0xffd5cfc9));

    //[UserPaint] Add your own custom painting code here..
    //[/UserPaint]
}

void SchroederReverbAudioProcessorEditor::resized()
{
    //[UserPreResize] Add your own custom resize code here..
    //[/UserPreResize]

    //[UserResized] Add your own custom resize handling here..
    //[/UserResized]
}

void SchroederReverbAudioProcessorEditor::sliderValueChanged (juce::Slider* sliderThatWasMoved)
{
    //[UsersliderValueChanged_Pre]
    //[/UsersliderValueChanged_Pre]

    if (sliderThatWasMoved == m_sizeSlider.get())
    {
        //[UserSliderCode_m_sizeSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kSize, m_sizeSlider->getValue());
        //[/UserSliderCode_m_sizeSlider]
    }
    else if (sliderThatWasMoved == m_wetSlider.get())
    {
        //[UserSliderCode_m_wetSlider] -- add your slider handling code here..
        audioProcessor.updateParameters(kWet, m_wetSlider->getValue());
        //[/UserSliderCode_m_wetSlider]
    }

    //[UsersliderValueChanged_Post]
    //[/UsersliderValueChanged_Post]
}

void SchroederReverbAudioProcessorEditor::buttonClicked (juce::Button* buttonThatWasClicked)
{
    //[UserbuttonClicked_Pre]
    //[/UserbuttonClicked_Pre]

    if (buttonThatWasClicked == m_clearButton.get())
    {
        //[UserButtonCode_m_clearButton] -- add your button handler code here..
        audioProcessor.updateParameters(kClearBuff, NULL);
        //[/UserButtonCode_m_clearButton]
    }

    //[UserbuttonClicked_Post]
    //[/UserbuttonClicked_Post]
}



//[MiscUserCode] You can add your own definitions of your custom methods or any other code here...
//[/MiscUserCode]


//==============================================================================
#if 0
/*  -- Projucer information section --

    This is where the Projucer stores the metadata that describe this GUI layout, so
    make changes in here at your peril!

BEGIN_JUCER_METADATA

<JUCER_COMPONENT documentType="Component" className="SchroederReverbAudioProcessorEditor"
                 componentName="" parentClasses="public juce::AudioProcessorEditor"
                 constructorParams="SchroederReverbAudioProcessor&amp; owner"
                 variableInitialisers="AudioProcessorEditor(owner), audioProcessor(owner)"
                 snapPixels="8" snapActive="1" snapShown="1" overlayOpacity="0.330"
                 fixedSize="0" initialWidth="400" initialHeight="300">
  <BACKGROUND backgroundColour="ffd5cfc9"/>
  <SLIDER name="sizeSlider" id="34d60c9217f4776" memberName="m_sizeSlider"
          virtualName="" explicitFocusOrder="0" pos="8 104 104 96" bkgcol="ffffffff"
          thumbcol="ffff8e50" trackcol="ffffffff" rotarysliderfill="ffffffff"
          textboxtext="ffffffff" textboxoutline="77ffffff" min="0.6" max="0.85"
          int="0.0" style="LinearVertical" textBoxPos="NoTextBox" textBoxEditable="0"
          textBoxWidth="80" textBoxHeight="20" skewFactor="1.0" needsCallback="1"/>
  <SLIDER name="wetSlider" id="68230142a9c63a69" memberName="m_wetSlider"
          virtualName="" explicitFocusOrder="0" pos="148 80 104 144" bkgcol="ffffffff"
          thumbcol="ffffc158" trackcol="ffffffff" rotarysliderfill="ffffffff"
          rotaryslideroutline="ffffffff" textboxtext="ffffffff" textboxbkgd="ffffff"
          textboxhighlight="ffffff" textboxoutline="79ffffff" min="0.0"
          max="1.0" int="0.0" style="RotaryHorizontalVerticalDrag" textBoxPos="NoTextBox"
          textBoxEditable="0" textBoxWidth="80" textBoxHeight="20" skewFactor="1.0"
          needsCallback="1"/>
  <TEXTBUTTON name="clearButton" id="441a05df5979cc0e" memberName="m_clearButton"
              virtualName="" explicitFocusOrder="0" pos="296 136 56 32" bgColOff="ffeee480"
              bgColOn="ffffff" textCol="ffffffff" buttonText="Clear" connectedEdges="2"
              needsCallback="1" radioGroupId="0"/>
  <LABEL name="textBoxName" id="a6f1be5eb77f5e91" memberName="m_textBoxName"
         virtualName="" explicitFocusOrder="0" pos="64 8 280 80" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Schroeder&#10;Reverberator"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Eras ITC" fontsize="38.2" kerning="0.0" bold="0" italic="1"
         justification="33" typefaceStyle="Italic"/>
  <LABEL name="textBoxWet" id="a0a1405dd9a3649a" memberName="m_textBoxWet"
         virtualName="" explicitFocusOrder="0" pos="162 192 72 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Dry/Wet" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="textBoxSize" id="ad8aaa085e4b8207" memberName="m_textBoxSize"
         virtualName="" explicitFocusOrder="0" pos="24 192 72 24" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="Size" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Default sans-serif font"
         fontsize="15.0" kerning="0.0" bold="0" italic="0" justification="36"/>
  <LABEL name="textBoxVersion" id="3fe2ff7c0b2ed93d" memberName="m_textBoxVersion"
         virtualName="" explicitFocusOrder="0" pos="256 32 88 80" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="V1.0" editableSingleClick="0"
         editableDoubleClick="0" focusDiscardsChanges="0" fontname="Eras ITC"
         fontsize="18.7" kerning="0.0" bold="0" italic="1" justification="33"
         typefaceStyle="Italic"/>
  <LABEL name="aboutTextBox" id="ac83a7845a23b69d" memberName="m_aboutTextBox"
         virtualName="" explicitFocusOrder="0" pos="32 224 336 72" textCol="ffffffff"
         edTextCol="ff000000" edBkgCol="0" labelText="This is an implementatio of Schroeder reverberator algorithm JCREV developed by Prof. John Chowning. https://ccrma.stanford.edu&#10;/~jos/pasp/Schroeder_Reverberators.html"
         editableSingleClick="0" editableDoubleClick="0" focusDiscardsChanges="0"
         fontname="Default font" fontsize="15.0" kerning="0.0" bold="0"
         italic="1" justification="33" typefaceStyle="Italic"/>
</JUCER_COMPONENT>

END_JUCER_METADATA
*/
#endif


//[EndFile] You can add extra defines here...
//[/EndFile]

