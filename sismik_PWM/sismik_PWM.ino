void setup() {
  // put your setup code here, to run once:
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
  DDRB |= (1<<DDB1); // PB1 sebagai output dapat dihubungkan ke LED
}

unsigned int i = 0;
void loop() {
  // put your main code here, to run repeatedly:
  // set duty cycle
  for (i=0; i<1024; i++)
  {
    OCR1A = i; // 100%
    delay(2); 
    }
    delay(2000);
    
   for (i=1023; i>0; i--)
  {
    OCR1A = i;
    delay(2); 
    }
    delay(2000);

  // OCR1A = 1023; // 100%
}
