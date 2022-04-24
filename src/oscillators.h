void setOscilTablesMono(){
    setOscilATableMono(oscilAWave);
    setOscilBTableMono(oscilBWave);
    setOscilCTableMono(oscilCWave);
    setOscilDTableMono(oscilDWave);
}

void setOscilFreqsMono(){
    oscilA.setFreq_Q16n16(lfoPitchOctaveSample * glide.next() * pow(2, oscilADetune));
    oscilB.setFreq_Q16n16(lfoPitchOctaveSample * glide.next() * pow(2, oscilBDetune));
    oscilC.setFreq_Q16n16(lfoPitchOctaveSample * glide.next() * pow(2, oscilCDetune));
    oscilD.setFreq_Q16n16(lfoPitchOctaveSample * glide.next() * pow(2, oscilDDetune));
    oscilSub.setFreq_Q16n16(lfoPitchOctaveSample * glide.next() * subOctave);
}

void setOscilTablesPoly(){
    setOscilATablePoly(oscilAWave, oscilBWave);
    setOscilBTablePoly(oscilAWave, oscilBWave);
    setOscilCTablePoly(oscilAWave, oscilBWave);
    setOscilDTablePoly(oscilAWave, oscilBWave);
}

void setOscilFreqsPoly(){
    oscilA.setFreq(lfoPitchOctaveSample * (float)mtof(keysHeld[0]));
    oscilB.setFreq(lfoPitchOctaveSample * (float)mtof(keysHeld[1]));
    oscilC.setFreq(lfoPitchOctaveSample * (float)mtof(keysHeld[2]));
    oscilD.setFreq(lfoPitchOctaveSample * (float)mtof(keysHeld[3]));
    oscilSub.setFreq(0);
}

void updateOscillatorsMono(){
    glide.setTime(glideTime);
    setOscilTablesMono();
    setOscilFreqsMono();
}

void updateOscillatorsPoly(){
    setOscilTablesPoly();
    setOscilFreqsPoly();
}

void updateOscillators(){
    switch (mode){
        case 0:
            updateOscillatorsMono();
            break;
        case 1:
            updateOscillatorsPoly();
            break;
        case 2:
            return;
            break;
    }
}