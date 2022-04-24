#define CONTROL_RATE 512

#include <includes.h>

void setup() {
  startMozzi(CONTROL_RATE);
  setPinMode();
  setMidiCommunication();
  setupEnvelopes();
  //Serial.begin(9600);
}

void updateControl() {
  MIDI.read();
  updateOscillators();
  updateEnvelopeControl();
  updateLfoControl();
  updateFilterControl();
  callFrontPanelReadings();
  //manuallySetFrontPanelVariables();
  //Serial.println(getInt(1, pinMasterVol, 0, 255));
}

int updateAudio() {
  grabRawWavesSamples();
  applyAmplitude();
  applyFilter();
  return constrain((wavesSample[0] + wavesSample[1] + wavesSample[2] + wavesSample[3] + wavesSample[4]) >> 1, -244, 243);
}

void loop() {
  audioHook(); 
}