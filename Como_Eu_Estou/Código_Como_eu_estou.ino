#include <LedControl.h>
#include <MatrizLed.h>

#include <Arduino.h>
#include <Wire.h>
#include <SoftwareSerial.h>

LedControl led = LedControl(8, 10, 9, 1);
MatrizLed displayLCD;

String isturnOn, figure2, isturnOn_2, figure2_2;

String figure_1 = "0011110001000010101010011000010110000101101010010100001000111100";

void _delay(float seconds) {
  long endTime = millis() + seconds * 1000;
  while(millis() < endTime) _loop();
}

void setup() {

  for(int i = 0; i < 1 + 1; i++){
  led.shutdown(i, false);
  }

  displayLCD.begin(8,10,9,1);
  displayLCD.rotar(false);
  while(1) {

    displayLCD.borrar();
    displayLCD.escribirFraseScroll("Como estou me sentindo", 50);

    for (int counter = 0; counter < 8; counter++) {
        figure2 = figure_1.substring(counter * 8, (counter + 1) * 8);
        for (int counter2 = 0; counter2 < 8; counter2++) {
          isturnOn = figure2.substring(counter2, counter2 + 1);
          if (isturnOn == "1") {
            led.setLed(1 - 1, counter, 7 - counter2, true);
          }
          else {
            led.setLed(1 - 1, counter, 7 - counter2, false);
          }
        }
    }
    _delay(3);

  	_loop();
  }

}

void _loop() {
}
