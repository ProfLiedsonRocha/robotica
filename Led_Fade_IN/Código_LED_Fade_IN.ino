/* Efeito Fade-in em um LED usando um pino PWM. */
int pinoLed = 11;    /* Define o pino 11 como pino do LED. */
int incremento = 1; /* Incremento do brilho do LED. */
int brilho = 0;      /* Variável do brilho do LED. */
void setup() {
pinMode(pinoLed, OUTPUT); /* Define o pino do LED como
saída. */
}
void loop() {
/* Incrementa o brilho do LED de 0 a 255. */
for (brilho; brilho <= 256; brilho += incremento) {
   /* Ajusta a intensidade do brilho a cada incremento. */
   analogWrite(pinoLed, brilho);
   delay(100);
}
}
