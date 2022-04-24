int lfoSample = 0;
float lfoPitchOctaveSample = 0;

void blinkLed(){
    analogWrite(pinLfoLed, ((lfoSample + 128) * (64 + lfoAmount)) >> 8);
}

float getLfoPitchOctaveSample(){
    if(lfoToPitch == 1){
        return pow(2, (((1.0f) / 256) * (float)(((lfoSample + 128) * lfoAmount) >> 8)));
    }
    else{
        return 1;
    }
}

void updateLfoControl(){
    setLfoTable(lfoWave);
    lfo.setFreq(lfoRate);
    lfoSample = lfo.next();
    lfoPitchOctaveSample = getLfoPitchOctaveSample();
    blinkLed();
}