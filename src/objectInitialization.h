ADC *adc1 = new ADC();

Oscil <8192, AUDIO_RATE> oscilA;
Oscil <8192, AUDIO_RATE> oscilB;
Oscil <8192, AUDIO_RATE> oscilC;
Oscil <8192, AUDIO_RATE> oscilD;
Oscil <2048, AUDIO_RATE> oscilSub(SIN2048_DATA);

Oscil <2048, CONTROL_RATE> lfo;

ADSR <AUDIO_RATE, AUDIO_RATE> envelopeA; //1. Argument: wie oft adsr.update() aufgerufen wird (meist CONTROL_RATE), 2. Argument: wie oft adsr.next() aufgerufen wird (meist AUDIO_RATE)
ADSR <AUDIO_RATE, AUDIO_RATE> envelopeB;
ADSR <AUDIO_RATE, AUDIO_RATE> envelopeC;
ADSR <AUDIO_RATE, AUDIO_RATE> envelopeD;

LowPassFilter lowPassFilterA;
LowPassFilter lowPassFilterB;
LowPassFilter lowPassFilterC;
LowPassFilter lowPassFilterD;
StateVariable <HIGHPASS> highPassFilterA;
StateVariable <HIGHPASS> highPassFilterB;
StateVariable <HIGHPASS> highPassFilterC;
StateVariable <HIGHPASS> highPassFilterD;
StateVariable <BANDPASS> bandPassFilterA;
StateVariable <BANDPASS> bandPassFilterB;
StateVariable <BANDPASS> bandPassFilterC;
StateVariable <BANDPASS> bandPassFilterD;

Portamento <CONTROL_RATE> glide;