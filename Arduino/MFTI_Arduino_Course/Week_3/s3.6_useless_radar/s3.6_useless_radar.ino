#include <QuadDisplay.h>
//подключение стандартной библиотеки 
//для управления сервомоторами
#include <Servo.h>

#define ECHO_PIN 8
#define TRIG_PIN 7

#define DISPLAY_PIN 2
#define SERVO_PIN 9

//создание объекта для работы с сервомотором
Servo scanner;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  
  pinMode(DISPLAY_PIN, OUTPUT);
  //"подключение" сервомотора библиотечным методом attach()
  //pinMode() в данном случае не требуется
  scanner.attach(SERVO_PIN);
}

void loop() {
  //счетчик цикла пройдет все значения от 0 до 179 включительно
  for(int i = 0; i < 180; i++)
  {
    //библиотечный метод write() берет значение счетчика для
    //установки сервомотора в соответствующее положение
    scanner.write(i);
    //в каждом положении на дисплей выводится текущее измерение
    displayInt(DISPLAY_PIN, measure());
    delay(20);
  }
  //те же действия в цикле от 180 до 1
  for(int i = 180; i > 0; i--)
  {
    scanner.write(i);
    displayInt(DISPLAY_PIN, measure());
    delay(20);
  }
}

int measure()
{
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 50;

  return constrain(distance, 1, 300);
}
  
