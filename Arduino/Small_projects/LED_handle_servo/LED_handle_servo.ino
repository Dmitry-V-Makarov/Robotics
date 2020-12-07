#define HANDLE A0
#define LED 9 // only some pins support PWM

#include <Servo.h>
Servo myservo;

int val;
int serv;
int sig;


void setup() {
  // set pins tp input/output
  pinMode(HANDLE, INPUT);
  pinMode(LED, OUTPUT);

  // attach servo to pin
  myservo.attach(11);

}

void loop() {
  // read analog signal from handle
  val = analogRead(HANDLE);

  // map handle to servo and set servo
  serv = map(val, 0, 1023, 0, 180);
  myservo.write(serv);

  // map handle to LED and set LED
  sig = map(val, 0, 1023, 0, 255);
  analogWrite(LED, sig);
  
  delay(15);

}
