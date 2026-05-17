/************************************************************/
/* Aula - Acelerômetro e giroscópio                      */
/* Programação do módulo acelerômetro e giroscópio MPU6050  */
/* que visa controlar três servomotores através da          */
/* rotação do módulo nas direções dos eixos X, Y e Z.       */
/* Também é impresso no monitor serial os valores dos       */
/* ângulos e temperatura do sensor.                         */
/************************************************************/
/* Link para download da biblioteca MPU6050 tockn.          */
/* https://github.com/Tockn/MPU6050_tockn                   */
/************************************************************/
/* Inclui as bibliotecas necessárias.                       */
#include <MPU6050_tockn.h>
#include <Servo.h>
#include <Wire.h>
/* Cria os objetos de controle para cada servomotor.        */
Servo servoX;
Servo servoY;
Servo servoZ;
/* Cria o objeto de controle do módulo MPU6050.             */
MPU6050 mpu6050(Wire);

void setup() {
  /* Inicia a comunicação serial com velocidade de 9600.    */
  Serial.begin(9600);
  /* Inicia a comunicação Wire(protocolo I2C).              */
  Wire.begin();
  /* Inicia o objeto de controle do módulo MPU6050.         */
  mpu6050.begin();
  /* Calibração automática do módulo MPU6050.               */
  /* O parâmetro true mostra a calibração no monitor serial.*/
  mpu6050.calcGyroOffsets(true);
  /* Atribui as portas de controle para cada servomotor.    */
  servoX.attach(3);
  servoY.attach(7);
  servoZ.attach(12);

}
void loop() {
  /* Atualiza a posição do módulo MPU6050.                  */
  mpu6050.update();
  /* Coleta os dados do módulo e armazena nas variáveis.    */
  int eixoX = mpu6050.getAngleX();
  int eixoY = mpu6050.getAngleY();
  int eixoZ = mpu6050.getAngleZ();
  float temp = mpu6050.getTemp();

  /* Mapeia os dados de -90 a 90 para valores de 0 a 180.   */
  int Xmapeado = map(eixoX, -90, 90, 0, 180);
  int Ymapeado = map(eixoY, -90, 90, 0, 180);
  int Zmapeado = map(eixoZ, -90, 90, 0, 180);

  /* Restringe os dados para valores de 0 a 180.            */
  int restritoX = constrain(Xmapeado, 0, 180);
  int restritoY = constrain(Ymapeado, 0, 180);
  int restritoZ = constrain(Zmapeado, 0, 180);

  /* Imprime os dados no monitor serial.                    */
  Serial.print("eixo X: " + String(restritoX) + "°\t");
  Serial.print("eixo Y: " + String(restritoY) + "°\t");
  Serial.print("eixo Z: " + String(restritoZ) + "°\t");
  Serial.print("Temp.: " + String(temp, 2) + "°C\n");

  /* Posiciona os servomotores.                             */
  servoX.write(restritoX);
  servoY.write(restritoY);
  servoZ.write(restritoZ);
}
/**********************************************************/
/* Obtendo outros dados do sensor MPU6050:                */
/*                                                        */
/* Aceleração no eixo X:  mpu6050.getAccX()               */
/* Aceleração no eixo Y:  mpu6050.getAccY()               */
/* Aceleração no eixo Z:  mpu6050.getAccZ()               */
/*                                                        */
/* Giro no eixo X: mpu6050.getGyroX()                     */
/* Giro no eixo Y: mpu6050.getGyroY()                     */
/* Giro no eixo Z: mpu6050.getGyroZ()                     */
/*                                                        */
/* Aceleração angular no eixo X:  mpu6050.getAccAngleX()  */
/* Aceleração angular no eixo Y:  mpu6050.getAccAngleY()  */
/* Aceleração angular no eixo Z:  mpu6050.getAccAngleZ()  */
/*                                                        */
/* Giro angular no eixo X: mpu6050.getGyroAngleX()        */
/* Giro angular no eixo Y: mpu6050.getGyroAngleY()        */
/* Giro angular no eixo Z: mpu6050.getGyroAngleZ()        */
/*                                                        */
/**********************************************************/
