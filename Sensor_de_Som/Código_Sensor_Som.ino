/*                     Sensor de som - digital             */
/************************************************************/
/* Definições dos pinos do sensor e do LED.                 */
#define pino_sensor 8
#define pino_LED 13

/* Variável booleana para controle do LED.                  */
boolean estado = LOW;   

void setup() {
  /* Configurações do modo de operação dos pinos/portas.    */
  pinMode(pino_sensor, INPUT);
  pinMode(pino_LED, OUTPUT);
  /* Inicia a comunicação serial com o computador.          */
  Serial.begin(9600);
}

void loop() {
  /* Armazena na variável som os dados do sensor.           */
  int som = digitalRead(pino_sensor);
  /* Imprime no monitor serial os dados da variável som.    */
  Serial.println(som);
  /* Se a variável som recebeu o pulso elétrico (som = 1),  */
  /* faça...                                                */
  if(som == 1){
  /* Altera o valor booleano da variável estado (Se for    */
  /* 0, muda para 1 e se for 1, muda para 0).              */
  estado = !estado;
  /* Envia para o pino do LED o valor booleano atual da    */
  /* variável estado (0 ou 1).                             */
  digitalWrite(pino_LED, estado);
  /* Pequena pausa para a nova leitura do Sensor.          */
  delay(300);
  }
}
