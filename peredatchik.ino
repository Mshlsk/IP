*
Победа над nRF24L01: на три шага ближе, передатчик
https://habr.com/ru/post/476716/
*/

#include <SPI.h>
#include <RF24.h>
RF24 radio(40, 53); // порты D9, D10: CSN CE
const uint32_t pipe1 = 123456789; // адрес рабочей трубы;
const uint32_t pipe2 = 987654321; // адрес рабочей трубы;
byte data;

void setup() {
  Serial.begin(115200);
  Serial.println("TransmitterTester ON");

  radio.begin();                // инициализация
  delay(2000);
  radio.setDataRate(RF24_1MBPS); // скорость обмена данными RF24_1MBPS или RF24_2MBPS
  radio.setCRCLength(RF24_CRC_16); // размер контрольной суммы 8 bit или 16 bit
  radio.setPALevel(RF24_PA_MAX); // уровень питания усилителя RF24_PA_MIN, RF24_PA_LOW, RF24_PA_HIGH and RF24_PA_MAX
  radio.setChannel(59);         // установка канала
  radio.setAutoAck(false);       // автоответ
  radio.powerUp();               // включение или пониженное потребление powerDown - powerUp
  radio.stopListening();  //радиоэфир не слушаем, только передача
  radio.openWritingPipe(pipe2);   // открыть трубу на отправку
}

void loop() {
  data = 109;
  radio.write(&data, 1);
  Serial.println("data= " + String(data));
}