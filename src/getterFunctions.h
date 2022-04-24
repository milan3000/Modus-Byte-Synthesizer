int getSwitchPosition(int pin1, int pin2){
    if (digitalRead(pin1) == HIGH && digitalRead(pin2) == LOW){
        return 2;
    }
    else if (digitalRead(pin1) == LOW && digitalRead(pin2) == HIGH){
        return 1;
    }
    else{
        return 0;
    }
}

int getInt(int adc, int pin, int min, int max){
    int reading = 0;
    switch (adc){
    case 0:
        reading = mozziAnalogRead(pin);
        break;
    case 1:
        reading = adc1->analogRead(pin);
        break;
    }
     return (map(reading, 0, 1023, min, max));
}

float getFloat(int adc, int pin, float min, float max){
    float reading = 0;
    switch (adc){
    case 0:
        reading = mozziAnalogRead(pin);
        break;
    case 1:
        reading = adc1->analogRead(pin);
        break;
    }
     return (min + ((max - min) / 1023) * reading);
}

int mapIntEnvTimes(int reading){ //reading between 0, 1023
  if (reading <= 512){
    return reading;
  }
  else{
    return map(reading, 512, 1023, 512, 8191);
  }
}

float linearizePinAFreq(){
  float reading = (float)mozziAnalogRead(pinAFreq);
  if (reading < 245){
    reading = -1 + reading/245;
  }
  else if (reading >= 245){
    reading = (reading-245)/778;
  }
  return reading;
}