#include <QuadDisplay.h>
#include <Servo.h>

#define ECHO_PIN 8
#define TRIG_PIN 7

#define DISPLAY_PIN 2
#define SERVO_PIN 9

Servo scanner;

void setup() {
  pinMode(ECHO_PIN, INPUT);
  pinMode(TRIG_PIN, OUTPUT);
  
  pinMode(DISPLAY_PIN, OUTPUT);
  scanner.attach(SERVO_PIN);
  Serial.begin(9600);
}

void loop() {
  int distance;
  for(int i = 0; i < 180; i++)
  {
    scanner.write(i);
    distance = measure();
    displayInt(DISPLAY_PIN, distance);
    delay(200);
    
    //отправка данныйх в последовательный порт
    //для скетча на Processing, который будет строить карту
    //переводы строк не добавляются
    Serial.print(i);
    Serial.print(":");
    Serial.print(distance);
    Serial.print(";");
  }
  for(int i = 180; i > 0; i--)
  {
    scanner.write(i);
    distance = measure();
    displayInt(DISPLAY_PIN, distance);
    delay(200);
    
    Serial.print(i);
    Serial.print(":");
    Serial.print(distance);
    Serial.print(";");
  }
}

int measure()
{
  digitalWrite(TRIG_PIN, HIGH);
  digitalWrite(TRIG_PIN, LOW);
  int distance = pulseIn(ECHO_PIN, HIGH, 15000) / 50;

  return constrain(distance, 1, 300);
}
  
