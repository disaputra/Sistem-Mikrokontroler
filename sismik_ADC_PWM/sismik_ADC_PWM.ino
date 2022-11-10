volatile int value;

void setup() {
 
  // ADC -----------------------------------------------------------
  // Enable the global interrupt enable bit
  SREG |= (1<<7);
  //sei();

  // set refernce to no avcc input to adc0
  ADMUX &= ~(1<<REFS0); // internal ref voltage
  ADMUX &= (~(1<<REFS1));

  // set data aligment in data register
  ADMUX &= (~(1<<ADLAR)); // right aligment

  // enable adc
  ADCSRA |= (1<<ADEN) | (1<<ADIE) | (1<<ADATE); // enable adc

  // set prescaler - Clock ADC = 16 MHz/16 = 1MHz
  ADCSRA |= (1<<ADPS2);  // mengatur prescaler PS_16
  //ADCSRA &= (~(1<<ADPS0)) & (~(1<<ADPS1)); // mengatur prescaler

  // start conversion
  ADCSRA |= (1<<ADSC);

  // select the channel
  ADMUX &= (~(1<<MUX0)) & (~(1<<MUX1)) & (~(1<<MUX2)) & (~(1<<MUX3)); // chanel ADC0
  // -----------------------------------------------------------------------

  // set PWM ------------------------------------------------------------------------
  // Set mode of the timer
  TCCR1B &= (~(1<<WGM13));
  TCCR1B |= (1<<WGM12);
  TCCR1A |= (1<<WGM10) | (1<<WGM11); // fast PWM 10 bit mode = 2^10 = 1024; 0-1023

  // set pwm mode
  TCCR1A |= (1<<COM1A1);
  TCCR1A &= (~(1<<COM1A0)); // non inverting mode

  // set prescler
  // clock 16 Mhz / 64 = 250 kHz
  TCCR1B |= (1<<CS10) | (1<<CS11);
  TCCR1B &= (~(1<<CS12)); // prescaler 64 

  // configure the output compare register as output
  DDRB |= (1<<DDB1); // PB1 sebagai output harus pin pwm

  // baca di serial
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println(ADC);
  delay(1);
}

// implementasi ISR interrupt handler ADC

  ISR(ADC_vect)
  {
   OCR1A = ADC;    
    }

    
