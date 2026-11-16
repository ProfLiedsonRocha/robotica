
// Robótica Paraná
// Equalizador com sensor de som KY-038

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while (millis() < endTime) _loop();
}

void setup() {

  Serial.begin(9600);

  pinMode(A0+3, INPUT);

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);

  Serial.println("================================");
  Serial.println(" EQUALIZADOR - SENSOR KY-038");
  Serial.println("================================");

}

void _loop() {

}

void loop() {

  // Realiza a leitura do sensor
  int som = analogRead(A0+3);

  // Exibe a leitura no Monitor Serial
  Serial.print("Leitura do sensor: ");
  Serial.print(som);

  Serial.print(" | LEDs acesos: ");

  if (som > 50) {

    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);

    Serial.println("Nenhum");

  }

  if ((som > 145) && (som < 160)) {

    digitalWrite(2, 0);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);

    Serial.println("Nenhum");

  }

  if ((som > 160) && (som < 175)) {

    digitalWrite(2, 1);
    digitalWrite(3, 0);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);

    Serial.println("1 LED");

  }

  if ((som > 175) && (som < 190)) {

    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 0);
    digitalWrite(5, 0);
    digitalWrite(6, 0);

    Serial.println("2 LEDs");

  }

  if ((som > 205) && (som < 220)) {

    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 0);

    Serial.println("4 LEDs");

  }

  if (som > 220) {

    digitalWrite(2, 1);
    digitalWrite(3, 1);
    digitalWrite(4, 1);
    digitalWrite(5, 1);
    digitalWrite(6, 1);

    Serial.println("5 LEDs");

  }

  delay(100);

}
