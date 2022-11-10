void setup() {
  DDRB |= (1<<DDB5); // konfigurasi PB5 sebagai output
  
  // enabel Global Interupt Enable Bit
  SREG |= (1<<7);

  // Enable ekternal interupt yang dibutuhkan dari register yang digunakan
  EIMSK |= (1<<INT0) |(1<<INT1); // mengaktifkan eksternal interup 0 dan 1

  // Atur edge select dari eksternal interupt
  EICRA |= (1<<ISC00) | (1<<ISC01) | (1<<ISC10) | (1<<ISC11);
}

void loop() {
  // put your main code here, to run repeatedly:
}


// implementasikan interupt handler
ISR(INT1_vect) 
{
  PORTB &= ~(1<<PB5); // led akan mati
  }

ISR(INT0_vect)
{
  PORTB |= (1<<PB5); // led akan menyala
  }
  
