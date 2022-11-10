void setup() {
  // put your setup code here, to run once:

  // Output Compare
  // ----------------------------
  // Enable the global interrupt enable bit
  SREG |= (1 << 7);

  // enable the required timer interrupt
  TIMSK1 |= (1<<TOIE1);

  // set mode of the timer
  TCCR1A &= (~(1<<WGM10)) & (~(1<<WGM11));
  TCCR1B &= (~(1<<WGM12)) & (~(1<<WGM13));
  
  // set the compare output mode
  TCCR1A |= (1<<COM1A0);
  TCCR1A &= (~(1<<COM1A1));

  // set the prescaler for the timer
  TCCR1B |= (1<<CS12) | (1<<CS10);
  TCCR1B &= (~(1<<CS11)); // prescaler 1024

  // start the timer with initial value
  TCNT1 = 0;
  
  // load the periode for the timer
  OCR1A = 15625;
  
  // configure the output compare as output
  DDRB |= (1<<DDB1); // PB1 sebagai output dapat dihubungkan ke LED

}

void loop() {
  // put your main code here, to run repeatedly:

}

  // implementationISR function
  ISR(TIMER_COMPA_vect)
  {
    TCNT1 = 0;
    OCR1A = 15625;
    }
