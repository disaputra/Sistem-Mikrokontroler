// Array berikut digunakan untuk menyimpan data
unsigned long nilaiADC[50];
unsigned long waktu_mulai[50];
unsigned long waktu_berhenti[50];
  
void setup() {
  //kecepatan serial
  Serial.begin(9600);  
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
