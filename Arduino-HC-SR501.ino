// Gelişmiş PIR Hareket Dedektörü

int pirPin = 2;      // PIR sensörü OUT pini
int ledPin = 3;      // LED pini
int pirState = LOW;  
unsigned long hareketBaslangic = 0;
bool hareketVar = false;

void setup() {
  pinMode(pirPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
  Serial.println("Gelişmiş PIR Sensörü Başlatıldı!");
}

void loop() {
  pirState = digitalRead(pirPin);
  
  if (pirState == HIGH && !hareketVar) {
    // Yeni hareket algılandı
    hareketVar = true;
    hareketBaslangic = millis();
    digitalWrite(ledPin, HIGH);
    Serial.println("🔴 HAREKET ALGILANDI!");
    
    // Yanıp sönme efekti (3 kez)
    for (int i = 0; i < 3; i++) {
      digitalWrite(ledPin, HIGH);
      delay(200);
      digitalWrite(ledPin, LOW);
      delay(200);
    }
    digitalWrite(ledPin, HIGH); // Son halinde yanık kalsın
    
  } else if (pirState == LOW && hareketVar) {
    // Hareket sona erdi - 5 saniye sonra LED'i söndür
    if (millis() - hareketBaslangic > 5000) {
      hareketVar = false;
      digitalWrite(ledPin, LOW);
      Serial.println("⏰ Hareket sona erdi, LED söndü");
    }
  }
  
  delay(50);
}
