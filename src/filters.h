int lowPassFilterCutoff[4] = {0, 0, 0, 0};
int variableStateFilterCutoff[4] = {0, 0, 0, 0};

void grabLpfBaseCutoff(){
    lowPassFilterCutoff[0] = filterCutoff;
    lowPassFilterCutoff[1] = filterCutoff;
    lowPassFilterCutoff[2] = filterCutoff;
    lowPassFilterCutoff[3] = filterCutoff;
}

void grabVariableStateFilterBaseCutoff(){
    variableStateFilterCutoff[0] = constrain(filterCutoff * 13, 0, 3200);
    variableStateFilterCutoff[1] = constrain(filterCutoff * 13, 0, 3200);
    variableStateFilterCutoff[2] = constrain(filterCutoff * 13, 0, 3200);
    variableStateFilterCutoff[3] = constrain(filterCutoff * 13, 0, 3200);
}

void applyEnvelopeToLpf(){
    if(envelopeToFilter == 1){
        lowPassFilterCutoff[0] = constrain((lowPassFilterCutoff[0] + ((envelopeAmount * envelopesSample[0]) >> 8)), 0, 255);
        lowPassFilterCutoff[1] = constrain((lowPassFilterCutoff[1] + ((envelopeAmount * envelopesSample[1]) >> 8)), 0, 255);
        lowPassFilterCutoff[2] = constrain((lowPassFilterCutoff[2] + ((envelopeAmount * envelopesSample[2]) >> 8)), 0, 255);
        lowPassFilterCutoff[3] = constrain((lowPassFilterCutoff[3] + ((envelopeAmount * envelopesSample[3]) >> 8)), 0, 255);
    }
}

void applyEnvelopeToVariableStateFilter(){
    if(envelopeToFilter == 1){
        variableStateFilterCutoff[0] = constrain((variableStateFilterCutoff[0] + ((envelopeAmount * envelopesSample[0])/22)), 0, 3000);
        variableStateFilterCutoff[1] = constrain((variableStateFilterCutoff[1] + ((envelopeAmount * envelopesSample[1])/22)), 0, 3000);
        variableStateFilterCutoff[2] = constrain((variableStateFilterCutoff[2] + ((envelopeAmount * envelopesSample[2])/22)), 0, 3000);
        variableStateFilterCutoff[3] = constrain((variableStateFilterCutoff[3] + ((envelopeAmount * envelopesSample[3])/22)), 0, 3000);
    }
}

void applyVelocityToLpf(){
    if(velocityDestination == 2){
        lowPassFilterCutoff[0] = constrain(lowPassFilterCutoff[0] + velocityArray[0], 0, 255);
        lowPassFilterCutoff[1] = constrain(lowPassFilterCutoff[1] + velocityArray[1], 0, 255);
        lowPassFilterCutoff[2] = constrain(lowPassFilterCutoff[2] + velocityArray[2], 0, 255);
        lowPassFilterCutoff[3] = constrain(lowPassFilterCutoff[3] + velocityArray[3], 0, 255);
    }
}

void applyVelocityToVariableState(){
    if(velocityDestination == 2){
        variableStateFilterCutoff[0] = constrain(variableStateFilterCutoff[0] + (velocityArray[0] << 4), 0, 3000);
        variableStateFilterCutoff[1] = constrain(variableStateFilterCutoff[1] + (velocityArray[1] << 4), 0, 3000);
        variableStateFilterCutoff[2] = constrain(variableStateFilterCutoff[2] + (velocityArray[2] << 4), 0, 3000);
        variableStateFilterCutoff[3] = constrain(variableStateFilterCutoff[3] + (velocityArray[3] << 4), 0, 3000);
    }
}

void applyLfoToLpf(){
    if(lfoToFilter == 1){
        lowPassFilterCutoff[0] = constrain(lowPassFilterCutoff[0] + ((lfoAmount * lfoSample) >> 7), 4, 255);
        lowPassFilterCutoff[1] = constrain(lowPassFilterCutoff[1] + ((lfoAmount * lfoSample) >> 7), 4, 255);
        lowPassFilterCutoff[2] = constrain(lowPassFilterCutoff[2] + ((lfoAmount * lfoSample) >> 7), 4, 255);
        lowPassFilterCutoff[3] = constrain(lowPassFilterCutoff[3] + ((lfoAmount * lfoSample) >> 7), 4, 255);
    }
}

void applyLfoToVariableStateFilter(){
    if(lfoToFilter == 1){
        variableStateFilterCutoff[0] = constrain(variableStateFilterCutoff[0] + ((lfoAmount * lfoSample) >> 4), 0, 3000);
        variableStateFilterCutoff[1] = constrain(variableStateFilterCutoff[1] + ((lfoAmount * lfoSample) >> 4), 0, 3000);
        variableStateFilterCutoff[2] = constrain(variableStateFilterCutoff[2] + ((lfoAmount * lfoSample) >> 4), 0, 3000);
        variableStateFilterCutoff[3] = constrain(variableStateFilterCutoff[3] + ((lfoAmount * lfoSample) >> 4), 0, 3000);
    }
}

void updateLpfCutoff(){
    grabLpfBaseCutoff();
    applyEnvelopeToLpf();
    applyVelocityToLpf();
    applyLfoToLpf();
    lowPassFilterA.setCutoffFreq(lowPassFilterCutoff[0]);
    lowPassFilterB.setCutoffFreq(lowPassFilterCutoff[1]);
    lowPassFilterC.setCutoffFreq(lowPassFilterCutoff[2]);
    lowPassFilterD.setCutoffFreq(lowPassFilterCutoff[3]);
}

void updateLpfResonance(){
    lowPassFilterA.setResonance(filterResonance);
    lowPassFilterB.setResonance(filterResonance);
    lowPassFilterC.setResonance(filterResonance);
    lowPassFilterD.setResonance(filterResonance);
}

void updateVariableStateFilterCutoff(){
    grabVariableStateFilterBaseCutoff();
    applyEnvelopeToVariableStateFilter();
    applyVelocityToVariableState();
    applyLfoToVariableStateFilter();
    highPassFilterA.setCentreFreq(variableStateFilterCutoff[0]);
    highPassFilterB.setCentreFreq(variableStateFilterCutoff[1]);
    highPassFilterC.setCentreFreq(variableStateFilterCutoff[2]);
    highPassFilterD.setCentreFreq(variableStateFilterCutoff[3]);
    bandPassFilterA.setCentreFreq(variableStateFilterCutoff[0]);
    bandPassFilterB.setCentreFreq(variableStateFilterCutoff[1]);
    bandPassFilterC.setCentreFreq(variableStateFilterCutoff[2]);
    bandPassFilterD.setCentreFreq(variableStateFilterCutoff[3]);
}

void updateVariableStateFilterResonance(){
    highPassFilterA.setResonance(map(filterResonance, 0, 255, 255, 64));
    highPassFilterB.setResonance(map(filterResonance, 0, 255, 255, 64));
    highPassFilterC.setResonance(map(filterResonance, 0, 255, 255, 64));
    highPassFilterD.setResonance(map(filterResonance, 0, 255, 255, 64));
    bandPassFilterA.setResonance(map(filterResonance, 0, 255, 255, 64));
    bandPassFilterB.setResonance(map(filterResonance, 0, 255, 255, 64));
    bandPassFilterC.setResonance(map(filterResonance, 0, 255, 255, 64));
    bandPassFilterD.setResonance(map(filterResonance, 0, 255, 255, 64));
}

void updateLpfControl(){
    updateLpfCutoff();
    updateLpfResonance();
}

void updateVariableStateFilterControl(){
    updateVariableStateFilterCutoff();
    updateVariableStateFilterResonance();
}

void updateFilterControl(){
    updateLpfControl();
    updateVariableStateFilterControl();
}