//Ideia de código para o terceiro desafio, modificar de acordo com sua missão

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 display(
  SCREEN_WIDTH,
  SCREEN_HEIGHT,
  &Wire,
  -1
);

int etapa = 0;

void mostrar(String linha1, String linha2) {

  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(SSD1306_WHITE);

  display.setCursor(0, 20);
  display.println(linha1);

  display.setCursor(0, 35);
  display.println(linha2);

  display.display();
}

void setup() {

  Serial.begin(9600);

  display.begin(
    SSD1306_SWITCHCAPVCC,
    0x3C
  );

  mostrar("OLA!", "PRECISA DE AJUDA?");

  Serial.println("Digite sua resposta:");
}

void loop() {

  if (Serial.available()) {

    String mensagem = Serial.readString();

    mensagem.trim();

    mensagem.toUpperCase();

    Serial.println(mensagem);

    // ETAPA 0
    if (etapa == 0) {

      if (mensagem == "SIM") {

        mostrar("VOCE ESTA", "COM DOR?");

        etapa = 1;

      }

      else if (mensagem == "NAO") {

        mostrar("TUDO BEM!", "ATE LOGO.");

        etapa = 0;

      }

      else {

        mostrar("NAO ENTENDI", "DIGITE SIM OU NAO");

      }
    }

    // ETAPA 1
    else if (etapa == 1) {

      if (mensagem == "SIM") {

        mostrar("ONDE ESTA", "A DOR?");

        etapa = 2;

      }

      else if (mensagem == "NAO") {

        mostrar("ENTENDI.", "COMO POSSO AJUDAR?");

        etapa = 0;

      }

      else {

        mostrar("RESPONDA", "SIM OU NAO");

      }
    }

    // ETAPA 2
    else if (etapa == 2) {

      mostrar("ENTENDI.", "INFORMACAO RECEBIDA.");

      etapa = 0;
    }

  }
}
