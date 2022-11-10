
unsigned char segmen[10] = {0x3f, 0x06, 0x5b, 0x4f, 0x66, 0x6d, 0x7c, 0x07, 0x7f, 0x6f};
unsigned char i = 0;

void setup() {
  DDRD = 0xFF; // semua port D dikonfigurasikan sebagai output 
}

void loop() {
  for(i = 0; i<10; i++)
  {
    PORTD = segmen[i];
    delay(1000);
    }

}
