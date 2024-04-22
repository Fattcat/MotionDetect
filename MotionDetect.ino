// Definícia pinov
const int pirPin = 2; // PIR senzor pripojený na pin 2
const int led1Pin = 3; // Prvá LED pripojená na pin 3
const int led2Pin = 4; // Druhá LED pripojená na pin 4
const int led3Pin = 5; // Tretia LED pripojená na pin 5

// ----------------------------------------
// PIR --> Arduino Nano
// VCC --> 5V
// OUT --> D2
// GND --> GND
// 
// LED Diodes --> Arduino Nano
// D3, D4, D5
// GND --> GND
// ----------------------------------------

// Premenné pre sledovanie pohybu
bool motionDetected = false; // Príznak detekcie pohybu
unsigned long motionStartTime = 0; // Čas od detekcie pohybu

// Doba trvania LED
const unsigned long ledDuration = 15000; // 15 sekúnd

void setup() {
  // Nastavenie pinov
  pinMode(pirPin, INPUT);
  pinMode(led1Pin, OUTPUT);
  pinMode(led2Pin, OUTPUT);
  pinMode(led3Pin, OUTPUT);

  // Zhasnutie LED
  digitalWrite(led1Pin, LOW);
  digitalWrite(led2Pin, LOW);
  digitalWrite(led3Pin, LOW);

  // Zapamätaj si čas spustenia programu
  motionStartTime = millis();
}

void loop() {
  // Ak je detekovaný pohyb
  if (digitalRead(pirPin) == HIGH) {
    // Zapamätaj si čas detekcie pohybu
    motionStartTime = millis();
    // Nastav príznak detekcie pohybu na true
    motionDetected = true;
    // Rozsviet LED diódy
    digitalWrite(led1Pin, HIGH);
    digitalWrite(led2Pin, HIGH);
    digitalWrite(led3Pin, HIGH);
  }

  // Ak uplynula doba trvania LED a pohyb bol detekovaný
  if (millis() - motionStartTime >= ledDuration && motionDetected) {
    // Vynuluj príznak detekcie pohybu
    motionDetected = false;
    // Zhasni LED diódy
    digitalWrite(led1Pin, LOW);
    digitalWrite(led2Pin, LOW);
    digitalWrite(led3Pin, LOW);
  }
}
