/****************************************************/
/* Aula - Enviando Mensagens [display OLED]         */
/* Programação do projeto enviando mensagens.       */
/* Ao transferir o código abaixo para seu Arduino,  */
/* será possível, através do monitor  serial do     */
/* Arduino IDE, enviar mensagens de texto para o    */
/* display OLED.                                    */
/****************************************************/

// Inclusão das bibliotecas.
#include <Adafruit_BusIO_Register.h> 
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

/* Variável para armazenar a mensagem.              */
String msg;
/* Variável para controlar a linha do display.      */
int linha;
/* Cria o objeto de controle para o display OLED.   */
Adafruit_SSD1306 display(128, 64);

/* Início das configurações.                        */
void setup() {
  Serial.begin(9600);
  /* Tempo que o Arduino utilizará para “ler” os    */
  /* caracteres armazenados na string msg. Se este  */
  /* tempo for curto para a quantidade de caracteres*/ 
  /* a ser processado, a mensagem será enviada incompleta.*/
  Serial.setTimeout(500);
  /* Inicializa o display OLED com o endereço 0x3C. */
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  /* Limpa o display.                               */
  display.clearDisplay();
  tela_inicial();
}

void loop() {
  /* Verifica dados disponíveis na porta serial.   */
  if (Serial.available()) {
    /* Lê o próximo caractere da porta serial.     */
    msg = Serial.readString();
    /* Se o caractere for %, limpa o display.      */
    if (msg == "%") {
      display.clearDisplay();
      linha = 0;
    }
    /* Se o caractere for >, pula linha no display.*/
    else if (msg == ">") { 
      linha += 8;
    }
    else {
      display.setCursor(0, linha);
      display.print(msg);
      
    }
  }
  display.display();
}

void tela_inicial() {
  display.drawRect(0, 0, 128, 64, 1);
  display.drawFastHLine(0, 14, 128, WHITE);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(4, 4);
  display.print("ESCREVA SUA MENSAGEM");
  display.setCursor((128 - 6 * 8) / 2, 20);
  display.setTextSize(1);
  display.print("Aten");
  display.write(135); 
  display.write(97); 
  display.setCursor(70, 20); 
  display.write(126); 
  display.write(111); 
  display.write(19); 
  display.setCursor(4, 30); 
  display.setTextSize(1); 
  display.print(" Utilize o comando % para nova mensagem e > para nova linha.");
  display.display();
  linha = 0;
}
