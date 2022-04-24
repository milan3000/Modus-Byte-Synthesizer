int wavesSample[5] = {0,0,0,0,0};
int lfoMasterVol;

void applyLowPassFilter(){
    if(filterType == 0){
        wavesSample[0] = lowPassFilterA.next(wavesSample[0]);
        wavesSample[1] = lowPassFilterB.next(wavesSample[1]);
        wavesSample[2] = lowPassFilterC.next(wavesSample[2]);
        wavesSample[3] = lowPassFilterD.next(wavesSample[3]);
    }
}

void applyHighPassFilter(){
    if(filterType == 1){
        wavesSample[0] = highPassFilterA.next(wavesSample[0]);
        wavesSample[1] = highPassFilterB.next(wavesSample[1]);
        wavesSample[2] = highPassFilterC.next(wavesSample[2]);
        wavesSample[3] = highPassFilterD.next(wavesSample[3]);
    }
}

void applyBandPassFilter(){
    if(filterType == 2){
        wavesSample[0] = bandPassFilterA.next(wavesSample[0]);
        wavesSample[1] = bandPassFilterB.next(wavesSample[1]);
        wavesSample[2] = bandPassFilterC.next(wavesSample[2]);
        wavesSample[3] = bandPassFilterD.next(wavesSample[3]);
    }
}

void applyFilter(){
    applyLowPassFilter();
    applyHighPassFilter();
    applyBandPassFilter();
}

void applyLfoToMasterVol(){
    if(lfoToVolume == 1){
        lfoMasterVol = constrain(masterVol + ((lfoAmount * lfoSample) >> 7), 0, 255);
    }
    else{
        lfoMasterVol = masterVol;
    }
}

void applyMasterVol(){
    wavesSample[0] = (wavesSample[0] * lfoMasterVol) >> 8;
    wavesSample[1] = (wavesSample[1] * lfoMasterVol) >> 8;
    wavesSample[2] = (wavesSample[2] * lfoMasterVol) >> 8;
    wavesSample[3] = (wavesSample[3] * lfoMasterVol) >> 8;
    wavesSample[4] = (wavesSample[4] * lfoMasterVol) >> 8;
}

void applyVelocityMono(){
    wavesSample[0] = (wavesSample[0] * velocityArray[oscillatorIndex]) >> 7;
    wavesSample[1] = (wavesSample[1] * velocityArray[oscillatorIndex]) >> 7;
    wavesSample[2] = (wavesSample[2] * velocityArray[oscillatorIndex]) >> 7;
    wavesSample[3] = (wavesSample[3] * velocityArray[oscillatorIndex]) >> 7;
    wavesSample[4] = (wavesSample[4] * velocityArray[oscillatorIndex]) >> 7;
}

void applyVelocityPoly(){
    wavesSample[0] = (wavesSample[0] * velocityArray[0]) >> 7;
    wavesSample[1] = (wavesSample[1] * velocityArray[1]) >> 7;
    wavesSample[2] = (wavesSample[2] * velocityArray[2]) >> 7;
    wavesSample[3] = (wavesSample[3] * velocityArray[3]) >> 7;
    wavesSample[4] = (wavesSample[4] * velocityArray[3]) >> 7;
}

void applyVelocity(){
    if(velocityDestination == 1){
        switch (mode){
            case 0:
                applyVelocityMono();
                break;
            case 1:
                applyVelocityPoly();
                break;
            case 2:
                break;
        }
    }
}

void applyEnvelopes(){
    updateEnvelopes();
    grabEnvelopesSamples();
    if(envelopeToVol == 1){
        wavesSample[0] = (wavesSample[0] * envelopesSample[0]) >> 8;
        wavesSample[1] = (wavesSample[1] * envelopesSample[1]) >> 8;
        wavesSample[2] = (wavesSample[2] * envelopesSample[2]) >> 8;
        wavesSample[3] = (wavesSample[3] * envelopesSample[3]) >> 8;
        wavesSample[4] = (wavesSample[4] * envelopesSample[3]) >> 8;
    }
}

void applyPotentiometerAmounts(){
    if(mode == 0){
        wavesSample[0] = (wavesSample[0] * oscilAAmp) >> 8;
        wavesSample[1] = (wavesSample[1] * oscilBAmp) >> 8;
        wavesSample[2] = (wavesSample[2] * oscilCAmp) >> 8;
        wavesSample[3] = (wavesSample[3] * oscilDAmp) >> 8;
    }
}

void grabRawWavesSamples(){
    wavesSample[0] = oscilA.next();
    wavesSample[1] = oscilB.next();
    wavesSample[2] = oscilC.next();
    wavesSample[3] = oscilD.next();
    wavesSample[4] = oscilSub.next();
}

void applyAmplitude(){
    applyLfoToMasterVol();
    applyMasterVol();
    applyVelocity();
    applyEnvelopes();
    applyPotentiometerAmounts();
}