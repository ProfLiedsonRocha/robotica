//IFA - Itinerário de Inteligência Artificial e Tecnologias
//Aula 54 - Semáforo do Som para TEA

int sensorSom = A0;
int ledVerde = 9;
int ledAmarelo = 10;
int ledVermelho = 11;
int valorSom;

void setup() {
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  valorSom = analogRead(sensorSom);
  Serial.println(valorSom);

  if (valorSom < 300) { // som baixo
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
  } else if (valorSom < 600) { // som médio
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, HIGH);
    digitalWrite(ledVermelho, LOW);
  } else { // som alto
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH);
  }

  delay(100);
}
