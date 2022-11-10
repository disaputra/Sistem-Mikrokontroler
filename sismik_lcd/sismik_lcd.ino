void setup() {
  DDRD = 0xff; // konfigurasi DDRD0-7 sebagai output
  DDRB |= (1<<DDB0) | (1<<DDB1) | (1<<DDB2); // konfigurasi DDB0, DDB1, DDB2 sebagai output
  
  lcd_inisialisasi();
}

void loop() {
  lcd_cmd(0x80);
  lcd_string("TE UNJANI", 9);
  lcd_cmd(0xc0);
  lcd_string("MIKROKONTROLER", 14);
}

//---------------------------------------------------------
// Fungsi untuk LCD
//---------------------------------------------------------
void lcd_data(unsigned char data)
{
  PORTD = data;
  PORTB |= (1<<PB0);      // RS = 1
  PORTB &= (~(1<<PB1));   // RW = 0
  PORTB |= (1<<PB2);      // EN = 1
  _delay_ms(10);          // 10ms
  PORTB &= (~(1<<PB2));   // EN = 0 
  }

//---------------------------------------------------------
void lcd_cmd(unsigned char command)
{
  PORTD = command;
  PORTB &= (~(1<<PB0));   // RS = 0
  PORTB &= (~(1<<PB1));   // RW = 0
  PORTB |= (1<<PB2);      // EN = 1
  _delay_ms(10);          // 10 ms
  PORTB &= (~(1<<PB2));   //EN = 0
  }
  
//--------------------------------------------------------
void lcd_string(const unsigned char *str, unsigned length)
{
  char i=0;
  for (i=0; i<length; i++)
  {
    lcd_data(str[i]);
    }
  }

//--------------------------------------------------------
void lcd_inisialisasi()
{
  lcd_cmd(0x38);
  lcd_cmd(0x06);
  lcd_cmd(0x0c);
  lcd_cmd(0x01);
  }
//---------------------------------------------------------
