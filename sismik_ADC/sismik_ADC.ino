volatile int value;

void setup() {
  // put your setup code here, to run once:
  // ADC -----------------------------------------------------------
  // Enable the global interrupt enable bit
  SREG |= (1<<7);
  //sei();

  // set refernce to no avcc input to adc0
  ADMUX |= (1<<REFS0); // internal ref voltage
  ADMUX &= (~(1<<REFS1));

  // set data aligment in data register
  ADMUX &= (~(1<<ADLAR)); // right aligment

  // enable adc
  ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADATE); // enable adc

  // set prescaler - Clock ADC = 16 MHz/16 = 1MHz
  ADCSRA |= (1<<ADPS2);  // mengatur prescaler
  //ADCSRA &= (~(1<<ADPS0)) & (~(1<<ADPS1)); // mengatur prescaler

  // start conversion
  ADCSRA |= (1<<ADSC);

  // select the channel
  ADMUX &= (~(1<<MUX0)) & (~(1<<MUX1)) & (~(1<<MUX2)) & (~(1<<MUX3)); // chanel ADC0 AnalogRead(0)
  // -----------------------------------------------------------------------

  // baca di serial
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(value);
  delay(1);
}

// implementasi ISR interrupt handler ADC

  ISR(ADC_vect)
  {
    value = ADC; 
    }

    
