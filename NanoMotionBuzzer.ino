const int pirPin = 2;     // Pin PIR senzora
const int buzzerPin = 3;  // Pin bzučiaka

void setup() {
  pinMode(pirPin, INPUT);       // Nastavenie PIR senzora ako vstup
  pinMode(buzzerPin, OUTPUT);   // Nastavenie bzučiaka ako výstup
  Serial.begin(9600);           // Pre ladenie
}

void loop() {
  int pirState = digitalRead(pirPin);  // Čítanie stavu PIR senzora
  
  if (pirState == HIGH) {              // Ak je pohyb detekovaný
    Serial.println("Pohyb detekovaný!");
    
    for (int i = 0; i < 3; i++) {      // Bzučiak 3-krát zapípa
      digitalWrite(buzzerPin, HIGH);   // Zapne bzučiak
      delay(100);                      // Bzučí na 100 ms
      digitalWrite(buzzerPin, LOW);    // Vypne bzučiak
      delay(100);                      // Pauza medzi pípaniami
    }
    
    delay(1000);                       // Čaká 1 sekundu, aby zabránil opakovaným spúšťaniam
  }
}
