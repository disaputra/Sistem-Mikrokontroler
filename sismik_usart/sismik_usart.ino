void setup() {
  // put your setup code here, to run once:
  // enable TX RX
  UCSR0B |= (1<<RXEN0) | (1<<TXEN0);

  //set data size for communication
  UCSR0C &= (~(1<<UMSL00)) & (~(1<<UMSL01)); //asynchronous
  UCSR0C &= (~(1<<UUPM00)) & (~(1<<UPM01)); //bit parity
  UCSR0C &= (~(1<<USBS0)); // 1 stop bit

  // set data length
  UCSR0B &= (~(1<<UCSZ02));
  UCSR0B |= (1<<UCSZ00) | (1<<UCSZ01); // 8 bit

  // set speed transmission
  UCSR0A |= (1<<U2x0); // High speed

  // set baud rate
  UBRR0 = 207; // 9600 bps
   
}

void loop() {
  // put your main code here, to run repeatedly:

}

 //
  unsigned char USART_Rx()
  {
    while (!(UCSR0A & (1<<RXC0)));
    return UDR0;
    }

  //
  void UART_Tx(char ch)
  {
    while (!(UCSR0A & (1<<UDRE0))); // menugnggu buffer kosong
    UDR0 = ch;
    }
