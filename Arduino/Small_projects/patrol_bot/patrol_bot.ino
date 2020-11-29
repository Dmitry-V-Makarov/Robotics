// Включение библиотек
#include <QuadDisplay2.h>
#include <Servo.h>


// Раздел 1. Кнопка, светодиод, дисплей

// создаём объект класса QuadDisplay и передаём номер пина CS
QuadDisplay qd(9);

// define Button and LED pins
#define ButtonPin 10
#define LedPin 3

// change mode variables
int buttonState = 0;
int lastButtonState = 0;
int PushCounter = 1;


// Раздел 2. Сервопривод

// create servo object to control a servo
Servo myservo;

// переменные сервопривода
int pos = 0;    // variable to store the servo position
int ServoCounter = 0;


// Раздел 3. Моторы

// define motor pins
#define SPEED_1      5 
#define DIR_1        4
 
#define SPEED_2      6
#define DIR_2        7

// переменные моторов
int MotorCounter = 0;


// Раздел 4. УЗ-дальномер
#define ECHO_PIN 25
#define TRIG_PIN 23

// расстояние до препятствия или расстояние до объекта при патрулировании
int DistConstrain = 300;


void setup()
{

  // Раздел 1. Настройка режимов работы пинов
  
  // setup button
  pinMode(ButtonPin, INPUT);
  // setup LEDs
  pinMode(LedPin, OUTPUT);

  // настраиваем выводы платы 4, 5, 6, 7 (моторы) на вывод сигналов 
  for (int i = 4; i < 8; i++) {     
    pinMode(i, OUTPUT);
  }

  // инициализация дисплея
  qd.begin();


  // Раздел 2. Создание соединения по серийному порту

  // initialize serial connection
  Serial.begin(9600);
  
  // display idle mode (1) at start
  Serial.print("current mode: ");
  Serial.println(PushCounter);


  // Раздел 3. Сервопривод
  
  // attaches the servo on pin 8 to the servo object
  myservo.attach(8);


  // Раздел 4. УЗ-дальномер
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  
}


void loop()
{
  
  // PART 1. Change mode.
  
  // read the pushbutton input pin
  buttonState = !digitalRead(ButtonPin); // логика работы кнопки перевернута!
  
  // compare the buttonState to its previous state
  if (buttonState != lastButtonState) {
    
    // if the state has changed, increment the counter
    if (buttonState == HIGH) {
      // if the current state is HIGH, then the button went from off to on
      // Serial.println("on");
      
      // increment counter or back to 1
      if (PushCounter == 4) {
        PushCounter = 1;
      } else {
        PushCounter += 1;
      }
      
      // display mode
      Serial.print("current mode: ");
      Serial.println(PushCounter);

      
    } else {
      
      // if the current state is LOW, then the button went from on to off
      // Serial.println("off");
    }
    // delay a little bit to avoid debouncing
    delay(5); // Wait for 5 millisecond(s)
  }
  
  // save the current state as the last state, for
  // the next time through the loop
  lastButtonState = buttonState;
  
  
  // PART 2. Change behaviour when mode changes
  
  // IDLE MODE
  if (PushCounter == 1) {
    
    // установка в начальное положение (с учетом калибровки)
    myservo.write(70);

    // задаем расстояние до препятствия (в режиме 2) и расстояние до объекта (в режиме 3)

    // задаем ограничение с помощью потенциометра от 2 до 300 см
    int SensorValue = analogRead(A1);
    DistConstrain = map(SensorValue, 0, 1023, 2, 300);
    
    // попеременно выводим то ограничение дальномера, то текущий режим робота
    qd.displayInt(1);
    delay(1000);
    qd.displayInt(DistConstrain);
    delay(1000);

    // считывание показателя дальномера при условии, что цель меньше, чем на расстоянии в А1 см
    if (measure() < DistConstrain) {
      Serial.print(measure());
      Serial.println(" cm");
      delay(500);
    } else {
      Serial.println("Too far");
    }

  
    // AUTHONOMOUS MODE
    
    // В этом режиме робот должен двигаться прямо до приближения на опреределенное расстрояние к препятствию
    // После этого он должен начать поворот направо до тех пор, пока препятствие не исчезнет
    // После поворота направо продолжить движение и повторить тот же алгоритм
    // Робот самостоятельно останавливается через 1 минуту движения

    // Расстояние до объекта, при котором начинается поворот задается потенциометром и выводится на дисплей

  } else if (PushCounter == 2) {

    qd.displayInt(2);

    if (MotorCounter < 1) { // задаем продолжительность движения

      // 1. Движение вперед

      // устанавливаем направление моторов M1 и M2 в одну сторону
      digitalWrite(DIR_1, HIGH);
      digitalWrite(DIR_2, LOW);
      
      // медленно разгоняем моторы
      for (int i = 0; i <= 255; i++) {
        analogWrite(SPEED_1, i);
        analogWrite(SPEED_2, i);
        Serial.println(i);
        delay(20); // задаем ускорение задержкой
      }

      // 2. Движение назад
 
      // устанавливаем направление моторов M1 и M2 в другую сторону
      digitalWrite(DIR_1, LOW);
      digitalWrite(DIR_2, HIGH);
  
      // медленно тормозим мотор
      for (int i = 255; i >= 0; i--) {
        analogWrite(SPEED_1, i);
        analogWrite(SPEED_2, i);
        Serial.println(i);
        delay(20);
      }

      // 3. Вращение на месте
 
      MotorCounter = MotorCounter + 1;
    }
    
    
    // FOLLOW-THE-LINE MODE
  } else if (PushCounter == 3) {

    qd.displayInt(3);

    if (ServoCounter < 1) { // задаем частоту вращения
      
      // in steps of 1 degree
      for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);                       // waits ХХ ms for the servo to reach the position
    }
      for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
        myservo.write(pos);              // tell servo to go to position in variable 'pos'
        delay(20);                       // waits ХХ ms for the servo to reach the position
    }
      ServoCounter = ServoCounter + 1;
    }

    myservo.write(70);
    
    
    // SMARTPHONE MODE
  } else {
    
    qd.displayInt(4);
    
    digitalWrite(LedPin, HIGH);
    delay(500);
    digitalWrite(LedPin, LOW);
    delay(500);

    ServoCounter = 0;
    MotorCounter = 0;
    
  }
    
  
}

int measure()
{
  //отправка импульса на TRIG_PIN
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  //считывание на входе длительности импульса от дальномера
  //максимальное ожидание - 15000 микросекунд
  //полученное значение делится на коэффициент, определяющий
  //отношение длительности импульса и расстояния в сантиметрах
  //(проверьте, уточнятся ли показания при значениях константы 50, 54, 58)
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 58;

  //функция measure() вернет сохраненное в distance значение,
  //предварительно ограничив возможные значения диапазоном 1-300
  //с помощью constrain()
  //(в том случае, если pulseIn() за 15000 микросекунд не дождется импульса, 
  //она вернет 0, в этом случае constrain() вернет 1) 
  return constrain(distance, 1, 300);
  
}
