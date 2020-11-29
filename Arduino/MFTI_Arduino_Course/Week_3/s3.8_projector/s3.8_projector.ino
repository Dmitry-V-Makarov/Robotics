#include <QuadDisplay.h>
//подключение стандартной библиотеки Wire для работы с I2C
//(с I2C здесь работает код из библиотеки Multiservo)
#include <Wire.h>
//подключение библиотеки для управление Multiservo Shield,
//которую можно найти через сайт производителя: https://github.com/amperka/Multiservo
#include <Multiservo.h>

#define ECHO_PIN 6
#define TRIG_PIN 7

#define DISPLAY_PIN 5
//в данном случае сервомоторы подключены
//к Multiservo Shield и здесь указываются пины этой платы расширения
#define SCAN_SERVO_PIN 9
#define PROJ_SERVO_PIN 8

//этот 8 пин - пин Arduino
#define PROJECTOR_PIN 8

//начало и конец диапазона сканирования (начальный и конечный угол для серво)
#define RANGE_START 20
#define RANGE_FINISH 150

//создаются объекты для работы с сервомоторами
Multiservo scanner_servo;
Multiservo projector_servo;

int closest_angle;
int distance;
//closest_dist будет нужна для сравнения текущего измерения
//с расстоянием до ближайшего объекта
//поскольку измерения у нас программно ограничены 300 сантиметрами,
//значение 500 позволит при первом сравнении в качестве точки отсчета
//взять расстояние, полученное при первом измерении,
//а дальнейшие измерения будут сравниваться с ним
int closest_dist = 500;

void setup() {
  //вызов библиотечного метода begin() для начала работы с I2C
  Wire.begin();
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);

  pinMode(DISPLAY_PIN, OUTPUT);

  pinMode(PROJECTOR_PIN, OUTPUT);
  //методы из библиотеки Multiservo такие же,
  //как в стандартной бибилиотеке Servo
  scanner_servo.attach(SCAN_SERVO_PIN);
  projector_servo.attach(PROJ_SERVO_PIN);

  Serial.begin(9600);
}

void loop() {

  for (int i = RANGE_START; i < RANGE_FINISH; i++)
  {
    scan(i);
  }
  
  for (int i = RANGE_FINISH; i > RANGE_START; i--)
  {
    scan(i);
  }
  closest_dist = 500;
}

int measure()
{
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 50;

  return constrain(distance, 1, 300);
}

//определение функции для измерений в каждом положении
//используется void, поскольку она не будет возвращать значений
//передается в нее угол для сервомотора с дальномером
void scan(int angle)
{
  scanner_servo.write(angle);
  distance = measure();
  displayInt(DISPLAY_PIN, distance);
  delay(50);
  
  //отладочный вывод в последовательный порт
  Serial.print(distance);
  Serial.print("\t");
  Serial.print(closest_dist);
  Serial.print("\t");
  Serial.println(angle);
  
  //сравнение текущего измерения с сохраненным расстоянием до ближайшего объекта
  //одновременно с которым проверяется неравенство текущего измерения 1 
  //(см. measure() - вероятнее всего 1 там будет, когда не удалось произвести измерение)
  if (closest_dist > distance && distance != 1)
  {
    //если текущее измерение дало значение
    //меньше сохраненного расстояния до ближайшего объекта
    //то оно будет сохранено как новое расстояние до ближайшего объекта
    closest_dist = distance;
    //а также будет сохранен текущее положение сервомотора с дальномером
    closest_angle = angle;
    //чтобы в такое же положение поставить сервомотор со светодиодом
    projector_servo.write(closest_angle);
  
    //включение и выключение светодиода в зависимости от того,
    //попадает ли какой-либо объект в диапазон измерений дальномера
    if (distance > 1)
      digitalWrite(PROJECTOR_PIN, HIGH);
    else
      digitalWrite(PROJECTOR_PIN, LOW);

  }

}
