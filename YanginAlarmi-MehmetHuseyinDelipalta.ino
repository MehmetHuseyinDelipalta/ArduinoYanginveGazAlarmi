// Mehmet Hüseyin Delipalta - coDeveloperman
#include <dht11.h> //DHT11 Sıcaklık Sensörü Kütüphanesi
dht11 DHT; // DHT11 Kütüphane Fonksiyonu
#define DHT11_PIN 6 // DHT11 Sinyal pini ( Dijital 6 )
 
const int buzzer=5; // Buzzer Sinyal Pini
const int AOUTpin=A1; // Duman Sensörü Analog Pini
const int DOUTpin=7; // Duman Sensörü Dijital Pini
 
// RGB Led
const int kirmizi=3; // RGB Led Kırmızı Işık Pini
const int yesil=4; // RGB Led Yeşil Işık Pini
 
int sicaklik; // Sıcaklık Değişkeni
int limit; // Duman Sensörü Dijital Değişkeni
int value; // Duman Sensörü Alanlog Değişkeni
 
void setup()
{
Serial.begin(9600); // Seri Bağlantı Hızı
pinMode(DOUTpin, INPUT); // Duman Sensörü Dijital Pin Girişi
pinMode(kirmizi, OUTPUT); // RGB Led Kırmızı Işık Çıkışı
pinMode(yesil, OUTPUT); // RGB Led Yeşil Işık Çıkışı
 
pinMode(buzzer, OUTPUT); // Buzzer Çıkışı
beep(50);
beep(50);
beep(50);
delay(1000);
}
 
void loop()
{
sicaklik = DHT.read(DHT11_PIN); // Sıcaklık Değeri Okunuyor
value= analogRead(AOUTpin); // Duman Sensörü Analog Değeri Okunuyor
limit= digitalRead(DOUTpin); // Duman Sensörü Dijital Değeri Okunuyor
Serial.print("Duman Seviyesi: \t"); // Serial Monitör Yazısı
Serial.println(value,1); // Serial Monitör Çıktısı
 
Serial.print("Sicaklik: \t"); // Serial Monitör Yazısı
Serial.print(DHT.temperature,1); // Serial Monitör Çıktısı
Serial.print(",\t"); // Boşluk Karakteri
 
delay(300);
 
if (value > 240){
beep(200);
//Kullanılan RGB Led Anot (Pozitif) Uçlu Olduğudan LOW Değeri Ledi Yakar
digitalWrite(kirmizi, LOW); // Kırmızı Işık Açık
digitalWrite(yesil, HIGH); // Yeşil Işık Kapalı
 
}
 
else if (DHT.temperature > 30){
beep(200);
digitalWrite(kirmizi, LOW); // Kırmızı Işık Açık
digitalWrite(yesil, HIGH); // Yeşil Işık Kapalı
 
}
 
else {
digitalWrite(kirmizi, HIGH); // Kırmızı Işık Kapalı
digitalWrite(yesil, LOW); // Yeşil Işık Açık
}
 
}
// Buzzer Alarm Fonksiyonu
void beep(unsigned char delayms){
digitalWrite(buzzer, HIGH); // Buzzer Ses Verir
delay(delayms); // Belirlilen MS cinsinden bekletme
digitalWrite(buzzer, LOW); // Buzzer Sesi Kapatır
delay(delayms); // Belirlilen MS cinsinden bekletme
}
//MehmetHuseyinDelipalta
