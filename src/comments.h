/*
Seperate: 

Global Initialisation
  Libraries
  Tables
  Control Rate
  Midi Instance
  Objects (ADC, Oscil, ADSR, Filter)

Pin Decleration (unsigned static, new names)
  setPinMode (called in setup)

setup

getReadingInt(pin,min,max)
getReadingFloat(pin,min,max)

MIDI
  Midi Variables
  setMidiCommunications (called in setup)
  handleNoteOffMono
  handleNoteOnMono
  handleNoteOffPoly
  handleNoteOnPoly

updateControl
  updateOscillators
  updateLfo
  updateEnvelope
  updateFilters

updateOscillators
  setFrequencies
  setTables (+buffer)
  setVolumes

updateLfo
  setFrequency
  setTable (+buffer)
  setAmount

updateEnvelope
  setTimes
  Mono -> 1 Env, Poly -> 4 Env

updateFilters
  setType (+buffer)
  setFrequency
  setResonance

updateAudio
  sumOscillators
  filterWave
  modulateWave
  constrain




Alt:
void addNoteToKeysHeld(byte note){
  for(int i = 4; i > 0 ; i--){
    keysHeld[i] = keysHeld[i-1];                                //Array gehaltener Tasten 1 nach rechts gerückt
  }
  keysHeld[0] = note;
}

void removeKeyFromKeysHeld(byte note){
  for(int i = 0; i < 4; i++){                                     
        if (note == keysHeld[i]){                                //Durchsuche das Array, welche Taste losgelassen wurde
           for(int j = i; j < 3; j++){                           //Entferne die Taste und rücke die übrigen Tasten "rechts davon" nach links auf
              keysHeld[j] = keysHeld[j+1];
            }
            keysHeld[3] = 0;
        }
  }
}


byte findFreeSpotInKeysHeld(){
  byte freeSpotinKeysHeld;
  for(int i = 0; i < 4; i++){
    if(keysHeld[i] == 0){
      freeSpotinKeysHeld = i;
      return freeSpotinKeysHeld;
    }
  }
  freeSpotinKeysHeld = 0;
  return freeSpotinKeysHeld;
}

byte findReleasedKeyInKeysHeld(byte note){
  byte releasedKeyInKeysHeld;
  for(int i = 0; i < 4; i++){
    if(keysHeld[i] == note){
      releasedKeyInKeysHeld = i;
      return releasedKeyInKeysHeld;
    }
  }
  return 0;
}

void addKeyToKeysHeld(byte note, byte freeSpotInKeysHeld){
  keysHeld[freeSpotInKeysHeld] = note;
}

void removeKeyFromKeysHeld(byte note, byte releasedKeyInKeysHeld){
  keysHeld[releasedKeyInKeysHeld] = 0;
}

void handleNoteOn(byte channel, byte note, byte velocity) {
  byte freeSpotInKeysHeld = findFreeSpotInKeysHeld();
  addKeyToKeysHeld(note, freeSpotInKeysHeld);
  startEnvelope(freeSpotInKeysHeld);
}

void handleNoteOff(byte channel, byte note, byte velocity) {
  byte releasedKeyInKeysHeld = findReleasedKeyInKeysHeld(note);
  removeKeyFromKeysHeld(note, releasedKeyInKeysHeld);
  stopEnvelope(releasedKeyInKeysHeld);
}


//oscilADetune = pow(linearizePinAFreq(), 3);

*/