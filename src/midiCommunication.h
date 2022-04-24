MIDI_CREATE_INSTANCE(HardwareSerial, Serial1, MIDI);

byte oscillatorIndex = 0;
byte keysHeld[4] = {0, 0, 0, 0};
byte releasedKeyInKeysHeld[4] = {0, 0, 0, 0};
byte velocityArray[4] = {0, 0, 0, 0};

void incrementOscillatorIndex(){
  oscillatorIndex++;
  if(oscillatorIndex > 3){
    oscillatorIndex = 0;
  }
  return;
}

void findReleasedKeyInKeysHeld(byte note){
  for(int i = 0; i < 4; i++){
    if(keysHeld[i] == note){
      releasedKeyInKeysHeld[i] = 1;
    }
    else{
      releasedKeyInKeysHeld[i] = 0;
    }
  }
  return;
}

void addKeyToKeysHeld(byte note, byte oscillatorIndex){
  keysHeld[oscillatorIndex] = note;
}

void addVelocityToArray(byte velocity, byte oscillatorIndex){
  velocityArray[oscillatorIndex] = velocity;
}

void handleNoteOnPoly(byte channel, byte note, byte velocity){
  startEnvelope(oscillatorIndex);
  addKeyToKeysHeld(note, oscillatorIndex);
  addVelocityToArray(velocity, oscillatorIndex);
  incrementOscillatorIndex();
  //lfo.setPhase(0);
}

void handleNoteOnMono(byte channel, byte note, byte velocity){
  startEnvelope(4);
  incrementOscillatorIndex();
  addKeyToKeysHeld(note, oscillatorIndex);
  addVelocityToArray(velocity, oscillatorIndex);
  glide.start(keysHeld[oscillatorIndex]);
  //lfo.setPhase(0);
}

void handleNoteOn(byte channel, byte note, byte velocity) { 
  switch (mode){
    case 0:
      handleNoteOnMono(channel, note, velocity);
      break;
    case 1: 
      handleNoteOnPoly(channel, note, velocity);
      break;
    case 2:
      return;
      break;
  }
}

void handleNoteOffPoly(byte channel, byte note, byte velocity){
  findReleasedKeyInKeysHeld(note);
  for(int i = 0; i < 4; i++){
    if(releasedKeyInKeysHeld[i] == 1){
      oscillatorIndex = i;
    }
  }
  stopEnvelopes(releasedKeyInKeysHeld[0], releasedKeyInKeysHeld[1],releasedKeyInKeysHeld[2],releasedKeyInKeysHeld[3]);
}

void handleNoteOffMono(byte channel, byte note, byte velocity){
  findReleasedKeyInKeysHeld(note);
  for(int i = 0; i < 4; i++){
    if(releasedKeyInKeysHeld[oscillatorIndex] == 1){
      stopEnvelopes(1, 1, 1, 1);
    }
  }
}

void handleNoteOff(byte channel, byte note, byte velocity){
  switch (mode){
    case 0:
      handleNoteOffMono(channel, note, velocity);
      break;
    case 1: 
      handleNoteOffPoly(channel, note, velocity);
      break;
    case 2:
      return;
      break;
  }
}

void setMidiCommunication(){
    MIDI.begin(1);
    MIDI.setHandleNoteOn(handleNoteOn);
    MIDI.setHandleNoteOff(handleNoteOff);
}