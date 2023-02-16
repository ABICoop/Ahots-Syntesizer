
// _0.0_WaveformModA2waveformFrequencyA3ShapeA4wavefprmMod1FrequenSubMultiploak
// _0.1_VCF
// _0.2_frekuentzia selektorea 12 notatan
// aurrera jarraitzeko pauso esanguratxuena
// Button0 --> waveform1.begin(currentWaveform1)
// Button1 --> waveformMod1.begin(currentWaveformVCO)
// Knob A2 In 0, waveforMod1-modulazioaren frekuentziaren kopurua --> waveform1.amplitude(knob_A1)_bitartez
// Knob A3 In 1, waveforMod1aren shape (Pulse & Var. Triangle) --> sine2.amplitude(knob_A3)_bitartez
// Switch bat daukagu Kbon_A5 bitartez modulazioa submultiplietan kontrolatzen uzten diguna
//USBHost_36 libreria bitartez teklatuaren seinaleak hartzen ditugu ondoren 4 fader bitartez ADSR bolumena kontrolatzen dugu.

#include <Audio.h>
#include <Wire.h>
#include <SPI.h>
#include <SD.h>
#include <SerialFlash.h>
#include <Bounce.h>
#include "USBHost_t36.h"

// GUItool: begin automatically generated code
AudioSynthWaveformSine   sine2;          //xy=72,137
AudioSynthWaveform       waveform1;      //xy=74,84
AudioSynthWaveformModulated waveformMod1;   //xy=245,123
AudioFilterStateVariable filter1;        //xy=406,134
AudioEffectEnvelope      envelope1;      //xy=583,137
AudioOutputI2S           i2s1;           //xy=781,145
AudioConnection          patchCord1(sine2, 0, waveformMod1, 1);
AudioConnection          patchCord2(waveform1, 0, waveformMod1, 0);
AudioConnection          patchCord3(waveformMod1, 0, filter1, 0);
AudioConnection          patchCord4(filter1, 0, envelope1, 0);
AudioConnection          patchCord5(envelope1, 0, i2s1, 0);
AudioConnection          patchCord6(envelope1, 0, i2s1, 1);
AudioControlSGTL5000     sgtl5000_1;     //xy=463,329
// GUItool: end automatically generated code

// GUItool: end automatically generated code

USBHost myusb;
USBHub hub1(myusb);
KeyboardController keyboard1(myusb);
MIDIDevice midi1(myusb);

Bounce button0 = Bounce(0, 60);
Bounce button1 = Bounce(1, 60);
Bounce button2 = Bounce(2, 60);

int currentWaveform1 = 0;
int currentWaveformVCO = 0;
int freqval = 0;
float globalFreq = 0;
int switch_pin  = 2;
float filter = 0;
float fc = 0;



extern const int16_t myWaveform[256];  // defined in myWaveform.ino

elapsedMillis timeout = 0;

void setup() {
  Serial.begin(9600);
  pinMode(0, INPUT_PULLUP);
  pinMode(1, INPUT_PULLUP);
  pinMode(switch_pin, INPUT_PULLUP);

  delay(300);
  Serial.println("Waveform Modulation Test");

  // Audio connections require memory to work.  For more
  // detailed information, see the MemoryAndCpuUsage example
  AudioMemory(12);

  // Comment these out if not using the audio adaptor board.
  sgtl5000_1.enable();
  sgtl5000_1.volume(0.35); // caution: very loud - use oscilloscope only!

  // Confirgure both to use "myWaveform" for WAVEFORM_ARBITRARY
  waveformMod1.arbitraryWaveform(myWaveform, 172.0);

  // Configure for middle C note without modulation
  waveformMod1.frequency(261.63);
  waveformMod1.amplitude(1.0);
  waveform1.frequency(20.3); // Sine waves are low frequency oscillators (LFO)

  currentWaveform1 = WAVEFORM_PULSE;
  currentWaveformVCO = WAVEFORM_PULSE;
  waveform1.begin(currentWaveform1);
  waveformMod1.begin(currentWaveformVCO);

  // Teklatuaren datuak jasotzeko komandoak:
  myusb.begin();
  keyboard1.attachPress(OnPress);
  keyboard1.attachRawPress(OnRawPress);
  keyboard1.attachRawRelease(OnRawRelease);
  midi1.setHandleNoteOff(OnNoteOff);
  midi1.setHandleNoteOn(OnNoteOn);
  midi1.setHandleControlChange(OnControlChange);

  envelope1.attack(10);
  envelope1.decay(25);
  envelope1.sustain(0.4);
  envelope1.release(70);


  timeout = 0;
}

void loop() {
  // Read the buttons and knobs, scale knobs to 0-1.0
  button0.update();
  // USBMidi bistarazi
  myusb.Task();
  midi1.read();
  sine2.frequency(1.2);
  button1.update();
  float knob_A1 = (float)analogRead(A1) / 1023.0;
  float knob_A2 = (float)analogRead(A2) / 1023.0;
  float knob_A3 = (float)analogRead(A3) / 1023.0;
  float knob_A4 = (float)analogRead(A4) / 1023.0;
  float knob_A5 = (float)analogRead(A5) / 1023.0;
  float knob_A0 = (float)analogRead(A0) / 1023.0;



  // use Knobs to adjust the amount of modulation
  waveform1.amplitude(knob_A1);
  waveform1.frequency(knob_A2 * 100.0);
  sine2.amplitude(knob_A3);
  fc = 256 * knob_A0;
  filter1.frequency(knob_A2 * 100.0 * fc);



  if (digitalRead(switch_pin) == HIGH) {
    if (knob_A5 > 0.0 && knob_A5 < 0.083) {
      waveformMod1.frequency(knob_A4 * 1000);
    }
    else if (knob_A5 > 0.2 && knob_A5 < 0.167) {
      waveformMod1.frequency(knob_A4 * 1000 * 0.94387635);
    }
    else if (knob_A5 > 0.167 && knob_A5 < 0.25) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 2));
    }
    else if (knob_A5 > 0.25 && knob_A5 < 0.333) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 3));
    }
    else if (knob_A5 > 0.333 && knob_A5 < 0.417) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 4));
    }
    else if (knob_A5 > 0.417 && knob_A5 < 0.5) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 5));
    }
    else if (knob_A5 > 0.5 && knob_A5 < 0.583) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 6));
    }
    else if (knob_A5 > 0.583 && knob_A5 < 0.6666) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 7));
    }
    else if (knob_A5 > 0.6666 && knob_A5 < 0.75) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 8));
    }
    else if (knob_A5 > 0.75 && knob_A5 < 0.833) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 9));
    }
    else if (knob_A5 > 0.833 && knob_A5 < 0.916) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 10));
    }
    else if (knob_A5 > 0.916 && knob_A5 < 1.0) {
      waveformMod1.frequency(knob_A4 * 1000 * pow(0.94387635, 11));
    }
  }
  else {
    waveformMod1.frequency(knob_A4 * 1000);
    waveformMod1.frequency(globalFreq);
  }

  // Button 0 changes the waveform type of waveform1
  if (button0.fallingEdge()) {
    switch (currentWaveform1) {
      case WAVEFORM_SINE:
        currentWaveform1 = WAVEFORM_SAWTOOTH;
        Serial.println("LFO_Sawtooth");
        Serial.println("");
        break;
      case WAVEFORM_SAWTOOTH:
        currentWaveform1 = WAVEFORM_SAWTOOTH_REVERSE;
        Serial.println("LFO_Reverse Sawtooth");
        Serial.println("");
        break;
      case WAVEFORM_SAWTOOTH_REVERSE:
        currentWaveform1 = WAVEFORM_SQUARE;
        Serial.println("LFO_Square");
        Serial.println("");
        break;
      case WAVEFORM_SQUARE:
        currentWaveform1 = WAVEFORM_TRIANGLE;
        Serial.println("LFO_Triangle");
        Serial.println("");
        break;
      case WAVEFORM_TRIANGLE:
        currentWaveform1 = WAVEFORM_TRIANGLE_VARIABLE;
        Serial.println("LFO_Variable Triangle");
        Serial.println("");
        break;
      case WAVEFORM_TRIANGLE_VARIABLE:
        currentWaveform1 = WAVEFORM_ARBITRARY;
        Serial.println("LFO_Arbitary Waveform");
        Serial.println("");
        break;
      case WAVEFORM_ARBITRARY:
        currentWaveform1 = WAVEFORM_PULSE;
        Serial.println("LFO_Pulse");
        Serial.println("");
        break;
      case WAVEFORM_PULSE:
        currentWaveform1 = WAVEFORM_SAMPLE_HOLD;
        Serial.println("LFO_Sample & Hold");
        Serial.println("");
        break;
      case WAVEFORM_SAMPLE_HOLD:
        currentWaveform1 = WAVEFORM_SINE;
        Serial.println("LFO_Sine");
        Serial.println("");
        break;
    }
    waveform1.begin(currentWaveform1); // lehengoko break ondoren eguneratzen du
  }

  // Button 1 changes the waveform type of waveformMod1
  if (button1.fallingEdge()) {
    switch (currentWaveformVCO) {
      case WAVEFORM_SINE:
        currentWaveformVCO = WAVEFORM_SAWTOOTH;
        Serial.println("VCO_Sawtooth");
        Serial.println("");
        break;
      case WAVEFORM_SAWTOOTH:
        currentWaveformVCO = WAVEFORM_SAWTOOTH_REVERSE;
        Serial.println("VCO_Reverse Sawtooth");
        Serial.println("");
        break;
      case WAVEFORM_SAWTOOTH_REVERSE:
        currentWaveformVCO = WAVEFORM_SQUARE;
        Serial.println("VCO_Square");
        Serial.println("");
        break;
      case WAVEFORM_SQUARE:
        currentWaveformVCO = WAVEFORM_TRIANGLE;
        Serial.println("VCO_Triangle");
        Serial.println("");
        break;
      case WAVEFORM_TRIANGLE:
        currentWaveformVCO = WAVEFORM_TRIANGLE_VARIABLE;
        Serial.println("VCO_Variable Triangle");
        Serial.println("");
        break;
      case WAVEFORM_TRIANGLE_VARIABLE:
        currentWaveformVCO = WAVEFORM_ARBITRARY;
        Serial.println("VCO_Arbitary Waveform");
        Serial.println("");
        break;
      case WAVEFORM_ARBITRARY:
        currentWaveformVCO = WAVEFORM_PULSE;
        Serial.println("VCO_Pulse");
        Serial.println("");
        break;
      case WAVEFORM_PULSE:
        currentWaveformVCO = WAVEFORM_SAMPLE_HOLD;
        Serial.println("VCO_Sample & Hold");
        Serial.println("");
        break;
      case WAVEFORM_SAMPLE_HOLD:
        currentWaveformVCO = WAVEFORM_SINE;
        Serial.println("VCO_Sine");
        Serial.println("");
        break;
    }
    waveformMod1.begin(currentWaveformVCO); // lehengoko break ondoren eguneratzen du
  }



  if (timeout > 2000) {
    Serial.print ("knob_A0: ");
    Serial.println (knob_A0);
    Serial.print ("knob_A1: ");
    Serial.println (knob_A1);
    Serial.print ("knob_A2: ");
    Serial.println (knob_A2);
    Serial.print ("knob_A3: ");
    Serial.println (knob_A3);
    Serial.print ("knob_A4 * 1000: ");
    Serial.println (knob_A4 * 1000);
    Serial.print ("knob_A5: ");
    Serial.println (knob_A5);
    Serial.print ("Attack: ");
    Serial.println (3000 * knob_A10);
    Serial.print ("Decay: ");
    Serial.println (2500 * knob_A11);
    Serial.print ("Sustain: ");
    Serial.println (0.99 * knob_A12);
    Serial.print ("Release: ");
    Serial.println (3000 * knob_A13);
    Serial.print("Frequency= ");
    Serial.println(globalFreq);

    Serial.println ("");
    timeout = 0;
  }
}

//Teklatuaren VOID guztiak
void OnPress(int key)
{

}

void OnRawPress(uint8_t keycode)
{


}

void OnRawRelease(uint8_t keycode)
{

}

void OnNoteOn(byte channel, byte note, byte velocity)
{
  float knob_A10 = (float)analogRead(A10) / 1023.0;
  float knob_A11 = (float)analogRead(A11) / 1023.0;
  float Freq = 440.0 * powf(2.0, (float)(note - 69) * 0.08333333);
  globalFreq = Freq;
  envelope1.noteOn();
  envelope1.attack(3000 * knob_A10);
  envelope1.decay(2500 * knob_A11);

}

void OnNoteOff(byte channel, byte note, byte velocity)
{
  float knob_A12 = (float)analogRead(A12) / 1023.0;
  float knob_A13 = (float)analogRead(A13) / 1023.0;
  envelope1.sustain(0.99 * knob_A12);
  envelope1.release(3000 * knob_A13);
  envelope1.noteOff();
}
void OnControlChange(byte channel, byte control, byte value)
{   }
