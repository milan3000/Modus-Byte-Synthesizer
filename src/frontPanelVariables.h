// Digital Frontpanel Variables
int mode;
int velocityDestination;
float subOctave;

int oscilAWave;
int oscilBWave;
int oscilCWave;
int oscilDWave;

int envelopeToVol;
int envelopeToFilter;

int lfoWave;
int lfoToVolume;
int lfoToFilter;
int lfoToPitch;

int filterType;

//Analog Frontpanel Variables
int masterVol;
int glideTime;

int oscilAAmp;
int oscilBAmp;
int oscilCAmp;
int oscilDAmp;
float oscilADetune;
float oscilBDetune;
float oscilCDetune;
float oscilDDetune;

int envelopeAttackTime;
int envelopeDecayTime;
int envelopeSustainLevel;
int envelopeReleaseTime;
int envelopeAmount;

float lfoRate;
int lfoAmount;

int filterCutoff;
int filterResonance;

void callDigitalReadings(){
    mode = getSwitchPosition(pinMode1, pinMode2);
    velocityDestination = getSwitchPosition(pinVel1, pinVel2);
    subOctave = (float)getSwitchPosition(pinSub2, pinSub1)/4;
    oscilAWave = getSwitchPosition(pinAWave1, pinAWave2);
    oscilBWave = getSwitchPosition(pinBWave1, pinBWave2);
    oscilCWave = getSwitchPosition(pinCWave1, pinCWave2);
    oscilDWave = getSwitchPosition(pinDWave1, pinDWave2);
    envelopeToVol = digitalRead(pinEnvVol);
    envelopeToFilter = digitalRead(pinEnvFilter);
    lfoWave = getSwitchPosition(pinLfoWave1, pinLfoWave2);
    lfoToVolume = digitalRead(pinLfoVol);
    lfoToFilter = digitalRead(pinLfoFilter);
    lfoToPitch = digitalRead(pinLfoPitch);
    filterType = getSwitchPosition(pinFilterType1, pinFilterType2);
}

void callAnalogReadings(){
    masterVol = getInt(1, pinMasterVol, 0, 255);
    glideTime = mapIntEnvTimes(getInt(1, pinGlide, 0, 1023));
    oscilAAmp = getInt(0, pinAAmp, 0, 255);
    oscilBAmp = getInt(0, pinBAmp, 0, 255);
    oscilCAmp = getInt(0, pinCAmp, 0, 255);
    oscilDAmp = getInt(0, pinDAmp, 0, 255);
    oscilADetune = pow(getFloat(0, pinAFreq, -1, 1), 3);
    oscilBDetune = pow(getFloat(0, pinBFreq, -1, 1), 3);
    oscilCDetune = pow(getFloat(0, pinCFreq, -1, 1), 3);
    oscilDDetune = pow(getFloat(0, pinDFreq, -1, 1), 3);
    envelopeAttackTime = mapIntEnvTimes(getInt(0, pinEnvA, 0, 1023));
    envelopeDecayTime = mapIntEnvTimes(getInt(0, pinEnvD, 0, 1023));
    envelopeSustainLevel = getInt(1, pinEnvS, 0, 255);
    envelopeReleaseTime = mapIntEnvTimes(getInt(1, pinEnvR, 0, 1023));
    envelopeAmount = getInt(0, pinEnvAmt, 0, 255);
    lfoRate = getFloat(1, pinLfoRate, 0, 55);
    lfoAmount = getInt(1, pinLfoAmt, 0, 255);
    filterCutoff = getInt(1, pinFilterFreq, 0, 255);
    filterResonance = getInt(1, pinFilterRes, 0, 255);
}

void callFrontPanelReadings(){
        callDigitalReadings();
        callAnalogReadings();
}

void manuallySetFrontPanelVariables(){
    //Digital 
    mode = 1;
    oscilAWave = 0;
    oscilBWave = 0;
    oscilCWave = 0;
    oscilDWave = 0;
    envelopeToVol = 1;
    envelopeToFilter = 1;
    lfoWave = 0;
    filterType = 0;
    //subOctave = 0;

    //Analog
    glideTime = 255;
    masterVol = 255;
    oscilAAmp = 255;
    oscilBAmp = 255;
    oscilCAmp = 255;
    oscilDAmp = 255;
    oscilADetune = 0;
    oscilBDetune = -1;
    oscilCDetune = 1;
    oscilDDetune = 0.01;
    envelopeAttackTime = 10;
    envelopeDecayTime = 1;
    envelopeSustainLevel = 255;
    envelopeReleaseTime = 400;
    envelopeAmount = 0;
    lfoRate = 10;
    lfoAmount = 127;
    filterCutoff = 255;
    filterResonance = 64;
}