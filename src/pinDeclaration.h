//Global
int pinMasterVol = 50;
int pinMode1 = 12;
int pinMode2 = 13;
int pinSub1 = 24;
int pinSub2 = 25;
int pinVel1 = 26;
int pinVel2 = 27;
int pinGlide = A22;

//Oscillators
int pinAWave1 = 2;
int pinAWave2 = 3;
int pinBWave1 = 4;
int pinBWave2 = 5;
int pinCWave1 = 6;
int pinCWave2 = 7;
int pinDWave1 = 8;
int pinDWave2 = 9;
int pinAAmp = 14;
int pinBAmp = 15;
int pinCAmp = 16;
int pinDAmp = 17;
int pinAFreq = 18;
int pinBFreq = 19;
int pinCFreq = 20;
int pinDFreq = 21;

//Envelope
int pinEnvA = 22;
int pinEnvD = 23;
int pinEnvS = 31;
int pinEnvR = 32;
int pinEnvAmt = 33;
int pinEnvVol = 10;
int pinEnvFilter = 11;

//LFO
int pinLfoRate = 35;
int pinLfoAmt = 36;
int pinLfoLed = 37;
int pinLfoVol = 28;
int pinLfoFilter = 29;
int pinLfoPitch = 30;
int pinLfoWave1 = 40;
int pinLfoWave2 = 44;

//Filter
int pinFilterRes = 38;
int pinFilterFreq = 39;
int pinFilterType1 = 42;
int pinFilterType2 = 43;

void setPinMode(){
    pinMode(pinMode1, INPUT_PULLDOWN);
    pinMode(pinMode2, INPUT_PULLDOWN);
    pinMode(pinSub1, INPUT_PULLDOWN);
    pinMode(pinSub2, INPUT_PULLDOWN);
    pinMode(pinVel1, INPUT_PULLDOWN);
    pinMode(pinVel2, INPUT_PULLDOWN);
    pinMode(pinAWave1, INPUT_PULLDOWN);
    pinMode(pinAWave2, INPUT_PULLDOWN);
    pinMode(pinBWave1, INPUT_PULLDOWN);
    pinMode(pinBWave2, INPUT_PULLDOWN);
    pinMode(pinCWave1, INPUT_PULLDOWN);
    pinMode(pinCWave2, INPUT_PULLDOWN);
    pinMode(pinDWave1, INPUT_PULLDOWN);
    pinMode(pinDWave2, INPUT_PULLDOWN);
    pinMode(pinEnvVol, INPUT_PULLDOWN);
    pinMode(pinEnvFilter, INPUT_PULLDOWN);
    pinMode(pinLfoVol, INPUT_PULLDOWN);
    pinMode(pinLfoFilter, INPUT_PULLDOWN);
    pinMode(pinLfoPitch, INPUT_PULLDOWN);
    pinMode(pinLfoWave1, INPUT_PULLDOWN);
    pinMode(pinLfoWave2, INPUT_PULLDOWN);
    pinMode(pinLfoLed, OUTPUT);
    pinMode(pinFilterType1, INPUT_PULLDOWN);
    pinMode(pinFilterType2, INPUT_PULLDOWN);
}