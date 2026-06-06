/* Efeito Fade-Out em um LED usando um pino PWM. */
int pinoLed = 11;    /* Define o pino 11 como pino do LED. */
int decremento = 5; /* Decremento do brilho do LED. */
int brilho = 255;    /* Variável do brilho do LED. */
void setup() {
pinMode(pinoLed, OUTPUT); /* Define o pino do LED como saída.
*/
}
void loop() {
  /* Decrementa o brilho do LED de 255 a 0. */
for (brilho; brilho >= -1; brilho -= decremento) {
   /* Ajusta a intensidade do brilho a cada decremento. */
   analogWrite(pinoLed, brilho);
   delay(50);
}
}
