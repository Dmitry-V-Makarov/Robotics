void setup() {
  //порты, к которым подключены светодиоды - выходы
  pinMode(8, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(12, OUTPUT);

}

void loop() {
  //включаем напряжение на 8 выходе (туда подключен красный)
  digitalWrite(8, HIGH);
  //ждем, пока красный горит
  delay(3000);
  //включаем напряжение на 10 выходе (желтый)
  digitalWrite(10, HIGH);
  delay(1000);
  
  //выключаем 8 и 10, включаем 12 (зеленый)
  digitalWrite(8, LOW);
  digitalWrite(10, LOW);
  digitalWrite(12, HIGH);
  delay(3000);
  digitalWrite(12, LOW);
  
  //трижды включаем и выключаем зеленый
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  delay(500);
  digitalWrite(12, HIGH);
  delay(500);
  digitalWrite(12, LOW);
  
  //одинокий желтый
  digitalWrite(10, HIGH);
  delay(1000);
  digitalWrite(10, LOW); 

}
