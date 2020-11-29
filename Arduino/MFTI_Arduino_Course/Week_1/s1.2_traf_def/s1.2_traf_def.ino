//макроопределения для номеров портов, к которым подклчаются светодиоды
//перед компиляцией все RED_PIN будут заменены на 8 и т.д.
#define RED_PIN 8
#define YELLOW_PIN 10
#define GREEN_PIN 12

void setup() {
  //порты, к которым подключены светодиоды - выходы
  pinMode(RED_PIN, OUTPUT);
  pinMode(YELLOW_PIN, OUTPUT);
  pinMode(GREEN_PIN, OUTPUT);

}

void loop() {
  //включаем напряжение на RED_PIN выходе (туда подключен красный)
  digitalWrite(RED_PIN, HIGH);
  //ждем, пока красный горит
  delay(3000);
  //включаем напряжение на YELLOW_PIN выходе (желтый)
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);
  
  //выключаем RED_PIN и YELLOW_PIN, включаем GREEN_PIN (зеленый)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(3000);
  digitalWrite(GREEN_PIN, LOW);
  
  //трижды включаем и выключаем зеленый
  delay(500);
  digitalWrite(GREEN_PIN, HIGH);
  delay(500);
  digitalWrite(GREEN_PIN, LOW);
  delay(500);
  digitalWrite(GREEN_PIN, HIGH);
  delay(500);
  digitalWrite(GREEN_PIN, LOW);
  delay(500);
  digitalWrite(GREEN_PIN, HIGH);
  delay(500);
  digitalWrite(GREEN_PIN, LOW);
  
  //одинокий желтый
  digitalWrite(YELLOW_PIN, HIGH);
  delay(1000);
  digitalWrite(YELLOW_PIN, LOW); 

}
