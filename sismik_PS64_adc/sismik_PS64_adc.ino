// Array berikut digunakan untuk menyimpan data
unsigned long nilaiADC[50];
unsigned long waktu_mulai[50];
unsigned long waktu_berhenti[50];
  
// Tentukan nilai-nilai Prescaler
// Lakukan pengaturan pada bit ADPS2 sampai ADPS0
const unsigned char PS_16 = (1 << ADPS2);
const unsigned char PS_32 = (1 << ADPS2) | (1 << ADPS0);
const unsigned char PS_64 = (1 << ADPS2) | (1 << ADPS1);
const unsigned char PS_128 = (1 << ADPS2) | (1 << ADPS1) | (1 << ADPS0);
  
void setup() {
  //kecepatan serial
  Serial.begin(9600); 
  // Lakukan inisialisasi. 
  // Hapus pengaturan oleh library Arduino
  ADCSRA &= ~PS_128; 
  // pilih prescaler yang digunakan.
  // Saat ini gunakan nilai 64
  ADCSRA |= PS_16; 
}
  
void loop() {  
  unsigned int i;
    
  // catat waktu mulai dan berhenti
  //simpan hasilnya di memori
  for(i=0;i<50;i++) {
    waktu_mulai[i] = micros();
    nilaiADC[i] = analogRead(0);
    waktu_berhenti[i] = micros();
  }
  
  // tampilkan hasilnya ke serial monitor  
  for(i=0;i<50;i++) {
    Serial.print(" Nilai ADC = ");
    Serial.print(nilaiADC[i]);
    Serial.print(" Waktu konversi = ");
    Serial.print(waktu_berhenti[i] - waktu_mulai[i]);
    Serial.print(" us\n");
  }
  delay(5000);
}
