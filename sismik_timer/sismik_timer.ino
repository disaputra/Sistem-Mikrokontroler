void setup() {
  // put your setup code here, to run once:
  DDRB |= (1 << DDB5); // pin dikonfigurasikan sebagai output

  //--------------------------------------------
  // fungsi timer
  // -------------------------------------------
  // Enable Global Interrupt Enable Bit -------
  SREG |= (1 << 7);
  //sei();

  // Enable Required Timer Interrupt ----------
  TIMSK1 |= (1 << TOIE1);

  // Set Mode dari Timer ----------------------
  TCCR1A &= (~(1 << WGM10)) & (~(1 << WGM11));
  TCCR1B &= (~(1 << WGM12)) & (~(1 << WGM13));

  // Set Prescaler dari Timer -----------------
  TCCR1B |= (1 << CS12) | (1 << CS10);
  TCCR1B &= (~(1 << CS11)); // prescaler 1024

  // Set Nilai Periode ------------------------
  TCNT1 = 49910; // 1 detik
}

void loop() {
  // put your main code here, to run repeatedly:
}

// Implementasi Interrupt Handler --------------
ISR(TIMER1_OVF_vect)
{
  // user code
  // program akan blink setiap satu detik
  PORTB ^= (1<<PB5); // xor
  TCNT1 = 49910;
}
