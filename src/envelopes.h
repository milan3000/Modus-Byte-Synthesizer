int envelopesSample[4] = {0, 0, 0, 0};

void updateEnvelopes(){
    envelopeA.update();
    envelopeB.update();
    envelopeC.update();
    envelopeD.update();
}

void grabEnvelopesSamples(){
    envelopesSample[0] = envelopeA.next();
    envelopesSample[1] = envelopeB.next();
    envelopesSample[2] = envelopeC.next();
    envelopesSample[3] = envelopeD.next();
}

void setupEnvelopes(){
    int attackLevel = 255;
    int sustainTime = 200000;
    int releaseLevel = 0;
    envelopeA.setAttackLevel(attackLevel);
    envelopeA.setSustainTime(sustainTime);
    envelopeA.setReleaseLevel(releaseLevel);
    envelopeB.setAttackLevel(attackLevel);
    envelopeB.setSustainTime(sustainTime);
    envelopeB.setReleaseLevel(releaseLevel);
    envelopeC.setAttackLevel(attackLevel);
    envelopeC.setSustainTime(sustainTime);
    envelopeC.setReleaseLevel(releaseLevel);
    envelopeD.setAttackLevel(attackLevel);
    envelopeD.setSustainTime(sustainTime);
    envelopeD.setReleaseLevel(releaseLevel);
}

void updateEnvelopeControl(){
    envelopeA.setAttackTime(envelopeAttackTime);
    envelopeA.setDecayTime(envelopeDecayTime);
    envelopeA.setDecayLevel(envelopeSustainLevel);
    envelopeA.setSustainLevel(envelopeSustainLevel);
    envelopeA.setReleaseTime(envelopeReleaseTime);
    envelopeB.setAttackTime(envelopeAttackTime);
    envelopeB.setDecayTime(envelopeDecayTime);
    envelopeB.setDecayLevel(envelopeSustainLevel);
    envelopeB.setSustainLevel(envelopeSustainLevel);
    envelopeB.setReleaseTime(envelopeReleaseTime);
    envelopeC.setAttackTime(envelopeAttackTime);
    envelopeC.setDecayTime(envelopeDecayTime);
    envelopeC.setDecayLevel(envelopeSustainLevel);
    envelopeC.setSustainLevel(envelopeSustainLevel);
    envelopeC.setReleaseTime(envelopeReleaseTime);
    envelopeD.setAttackTime(envelopeAttackTime);
    envelopeD.setDecayTime(envelopeDecayTime);
    envelopeD.setDecayLevel(envelopeSustainLevel);
    envelopeD.setSustainLevel(envelopeSustainLevel);
    envelopeD.setReleaseTime(envelopeReleaseTime);
}

void startEnvelope(byte oscillator){
    switch (oscillator){
        case 0:
            envelopeA.noteOff();
            envelopeA.noteOn();
            break;
        case 1:
            envelopeB.noteOff();
            envelopeB.noteOn();
            break;
        case 2:
            envelopeC.noteOff();
            envelopeC.noteOn();
            break;
        case 3:
            envelopeD.noteOff();
            envelopeD.noteOn();
            break;
        case 4:
            envelopeA.noteOff();
            envelopeB.noteOff();
            envelopeC.noteOff();
            envelopeD.noteOff();
            envelopeA.noteOn();
            envelopeB.noteOn();
            envelopeC.noteOn();
            envelopeD.noteOn();
            break;
    }
}

void stopEnvelopes(byte oscillatorIndexA, byte oscillatorIndexB, byte oscillatorIndexC, byte oscillatorIndexD){
    if(oscillatorIndexA == 1){
        envelopeA.noteOff();
    }
    if(oscillatorIndexB == 1){
        envelopeB.noteOff();
    }
    if(oscillatorIndexC == 1){
        envelopeC.noteOff();
    }
    if(oscillatorIndexD == 1){
        envelopeD.noteOff();
    }
    
}