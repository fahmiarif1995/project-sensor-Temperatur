#include <DHT.h>

// Tipe dan pin sensor
#define DHTPIN 2         // DHT11 terhubung ke pin D2
#define DHTTYPE DHT11    // Tipe sensornya DHT11

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(9600);   // Buka komunikasi serial
  dht.begin();          // Mulai sensor DHT
}

void loop() {
  delay(2000); // Delay 2 detik antar pembacaan

  float kelembapan = dht.readHumidity();     // Baca kelembapan
  float suhu = dht.readTemperature();        // Baca suhu dalam Celcius

  // Cek jika pembacaan gagal
  if (isnan(kelembapan) || isnan(suhu)) {
    Serial.println("Gagal membaca dari sensor DHT11!");
    return;
  }

  // Tampilkan hasil
  Serial.print("Suhu: ");
  Serial.print(suhu);
  Serial.print(" °C,  Kelembapan: ");
  Serial.print(kelembapan);
  Serial.println(" %");
}

