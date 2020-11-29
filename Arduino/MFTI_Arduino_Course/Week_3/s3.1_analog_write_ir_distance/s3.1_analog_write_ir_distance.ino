#define LED_PIN 3
#define IR_DIST_SENS A1

void setup() {
  //не забудьте убедиться, что в мониторе порта
  //или в коде программы-визуализатора
  //выбрана та же скорость соединения, 115200
  Serial.begin(115200);
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  int distance = analogRead(IR_DIST_SENS);
   
  Serial.println(distance);
  //записываем "аналоговый" сингал (ШИМ),
  //передавая в analogWrite() номер пина
  //и значение 0-255, определяющее скважность ШИМ
  //(в данном случае это значение возвращает map())
  analogWrite(LED_PIN, map(distance,0,1023,0,255));
}
