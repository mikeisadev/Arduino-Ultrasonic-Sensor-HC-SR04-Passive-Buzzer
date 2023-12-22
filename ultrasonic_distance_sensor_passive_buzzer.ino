#include "SR04.h"
#include "pitches.h"

#define TRIG_PIN 12
#define ECHO_PIN 11
#define BUZZER_PIN 8
SR04 sr04 = SR04(ECHO_PIN,TRIG_PIN);
long a;

long _delay;

void setup() {
  Serial.begin(9600);
  delay(1000);
}

void loop() {
  a=sr04.Distance();
  Serial.print(a);
  Serial.println("cm");

  if (a > 8 && a <= 16) {
    tone(8, NOTE_D5, 250);
    delay(1000);

    _delay = 1000;
  }

  if (a > 4 && a <= 8) {
    tone(8, NOTE_D5, 100);
    delay(150);
    tone(8, NOTE_D5, 100);
    delay(150);
    tone(8, NOTE_D5, 100);

    _delay = 0;
  }

  if (a <= 4) {
    tone(8, NOTE_D5, 200);
    delay(50);
    tone(8, NOTE_D5, 200);
    delay(50);
    tone(8, NOTE_D5, 200);

    _delay = 0;
  }
  
  delay(_delay);
}
