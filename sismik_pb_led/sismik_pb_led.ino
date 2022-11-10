

void setup() {
  DDRB |= (1<<DDB5); // PB5 dikonfigurasikan sebagai output
  DDRD &= ~(1<<DD2); // PD2 dikonfigurasikan sebagai input
}

void loop() {
  if (PIND & (1<<PIND2))
  {
    PORTB |= (1<<PB5); // high atau lampu menyala
    }
    else 
    {
      PORTB &= ~(1<<PB5); // low atau lampu mati
      }
}
