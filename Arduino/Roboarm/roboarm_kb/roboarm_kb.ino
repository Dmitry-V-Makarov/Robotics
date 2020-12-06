#include <Servo.h> 
 
Servo middle, left, right, claw ;  // creates 4 "servo objects"

int val; // initial value of input
int pos_m = 90;
int pos_f1 = 100;
int pos_f2 = 100;
int pos_c = 60;
 
void setup() 
{ 
  Serial.begin(9600);
  middle.attach(8);  // attaches the servo on pin 11 to the middle object
  left.attach(9);  // attaches the servo on pin 10 to the left object
  right.attach(10);  // attaches the servo on pin 9 to the right object
  claw.attach(11);  // attaches the servo on pin 6 to the claw object

  middle.write(90); // sets the servo position according to the value(degrees)
  left.write(100); // does the same
  right.write(100); // and again
  claw.write(60); // yes you've guessed it
} 
 
void loop() 
{
  if (Serial.available()) // if serial value is available 
  {
    val = Serial.read();// then read the serial value

    // middle
    if (val == 'a') //if value input is equals to d
    {
      pos_m += 1; //than position of servo motor increases by 1 ( anti clockwise)
      middle.write(pos_m);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
     }
    if (val == 'f') 
    {
      pos_m -= 1; //than position of servo motor decreases by 1 (clockwise)
      middle.write(pos_m);// the servo will move according to position 
      delay(15);//delay for the servo to get to the position
    }

    // joint 1
    if (val == 'w') //if value input is equals to d
    {
      pos_f1 += 1; //than position of servo motor increases by 1 ( anti clockwise)
      left.write(pos_f1); // does the same
      delay(15);//delay for the servo to get to the position
     }
    if (val == 's') //if value input is equals to a
    {
      pos_f1 -= 1; //than position of servo motor decreases by 1 (clockwise)
      left.write(pos_f1); // does the same
      delay(15);//delay for the servo to get to the position
    }

    // joint 2
    if (val == 'e') //if value input is equals to d
    {
      pos_f2 += 1; //than position of servo motor increases by 1 ( anti clockwise)
      right.write(pos_f2);
      delay(15);//delay for the servo to get to the position
     }
    if (val == 'd') //if value input is equals to a
    {
      pos_f2 -= 1; //than position of servo motor decreases by 1 (clockwise)
      right.write(pos_f2);
      delay(15);//delay for the servo to get to the position
    }

    // claw
    if (val == 'z') //if value input is equals to d
    {
      pos_c += 1; //than position of servo motor increases by 1 ( anti clockwise)
      claw.write(pos_c);
      delay(15);//delay for the servo to get to the position
     }
    if (val == 'c') //if value input is equals to a
    {
      pos_c -= 1; //than position of servo motor decreases by 1 (clockwise)
      claw.write(pos_c);
      delay(15);//delay for the servo to get to the position
    }
  }
}
