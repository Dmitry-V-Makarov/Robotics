#define RED_PIN 8
#define YELLOW_PIN 10
#define GREEN_PIN 12

//создаем переменные, в которых будет храниться время задержки для каждой фазы в миллисекундах
//int - тип данных, целые числа от -32768 до 32767
// = - оператор присваивания
int red_on = 3000;
int red_yellow_on = 1000;
int green_on = 3000;
int green_blink = 500;
int yellow_on = 1000;

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
  delay(red_on);
  //включаем напряжение на YELLOW_PIN выходе (желтый)
  digitalWrite(YELLOW_PIN, HIGH);
  delay(red_yellow_on);
  
  //выключаем RED_PIN и YELLOW_PIN, включаем GREEN_PIN (зеленый)
  digitalWrite(RED_PIN, LOW);
  digitalWrite(YELLOW_PIN, LOW);
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_on);
  digitalWrite(GREEN_PIN, LOW);
  
  //трижды включаем и выключаем зеленый
  delay(green_blink);
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_blink);
  digitalWrite(GREEN_PIN, LOW);
  delay(green_blink);
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_blink);
  digitalWrite(GREEN_PIN, LOW);
  delay(green_blink);
  digitalWrite(GREEN_PIN, HIGH);
  delay(green_blink);
  digitalWrite(GREEN_PIN, LOW);
  
  //одинокий желтый
  digitalWrite(YELLOW_PIN, HIGH);
  delay(yellow_on);
  digitalWrite(YELLOW_PIN, LOW); 

}
