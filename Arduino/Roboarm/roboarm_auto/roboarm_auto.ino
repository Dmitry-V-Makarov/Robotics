#include <Servo.h> 
 
Servo middle, left, right, claw ;  // creates 4 "servo objects"

int N = 1;
int runXTimes = 0;
int pos = 0;
 
void setup() 
{ 
  Serial.begin(9600);
  middle.attach(9);  // attaches the servo on pin 11 to the middle object
  left.attach(6);  // attaches the servo on pin 10 to the left object
  right.attach(5);  // attaches the servo on pin 9 to the right object
  claw.attach(3);  // attaches the servo on pin 6 to the claw object

  middle.write(90); // sets the servo position according to the value(degrees)
  left.write(100); // does the same
  right.write(100); // and again
  claw.write(60); // yes you've guessed it
  delay(2000); // doesn't constantly update the servos which can fry them
} 
 
void loop() 
{ 
  if (runXTimes < N)
 {
    // turn left, extend the arm and pick up the piece
    for (pos = 90; pos <= 150; pos += 1) {
    middle.write(pos);
    delay(15);
    }

    delay(1000);
    claw.write(150); // open claw
    delay(1000);
    
    for (pos = 100; pos <= 150; pos += 1) {
    left.write(pos);
    right.write(pos);
    delay(15);
    }
    delay(2000);
  
    claw.write(70);
    delay(1000);

    for (pos = 150; pos >= 100; pos -= 1) {
    left.write(pos);
    right.write(pos);
    delay(15);
  }
    
    delay(1000);

    for (pos = 150; pos >= 90; pos -= 1) {
    middle.write(pos);
    delay(15);
    }
    runXTimes++;
 }
  
}
