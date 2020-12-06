#define HANDLE A4
#define LED 10

#include <Servo.h>
Servo myservo;

int val;
int serv;
int sig;


void setup() {
  // put your setup code here, to run once:
  pinMode(HANDLE, INPUT);
  pinMode(LED, OUTPUT);
  myservo.attach(11);

}

void loop() {
  // put your main code here, to run repeatedly:

  val = analogRead(HANDLE);
  serv = map(val, 0, 1023, 0, 180);
  myservo.write(serv);
  sig = map(val, 0, 1023, 0, 255);
  analogWrite(LED, sig);
  delay(15);

}
