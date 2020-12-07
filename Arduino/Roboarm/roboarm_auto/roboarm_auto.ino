#include <Servo.h> 
 
Servo middle, left, right, claw ;  // creating 4 "servo objects"

int N = 1; // number of times we want the robot to move
int counter = 0; // will increase by 1 after every loop
int pos = 0; // position of servo
 
void setup() // attach servos to pins and set initial position

{
  Serial.begin(9600); // initialize serial connection
  
  // attaching servos to pins
  middle.attach(9);  // rotation
  left.attach(6);  // left servo, forward movement, should be same as "right"
  right.attach(5);  // right servo, forward movement, should be same as "left"
  claw.attach(3);  // claw

  // roboarm initial position
  middle.write(90);
  left.write(100);
  right.write(100);
  claw.write(60);
  
  // status
  Serial.println("Roboarm ready");
  
  delay(2000); // wait 2 seconds
} 
 
void loop() // turn left, extend the arm and pick up the piece
 
{ 
  if (counter < N) // N times the robot will move
 {
    
    // turn left
    for (pos = 90; pos <= 150; pos += 1) {
      middle.write(pos);
      delay(15);
    }
    
    delay(1000);

    // open claw
    for (pos = 60; pos <= 140; pos += 1) {
      claw.write(pos);
      delay(15);
    }

    delay(1000);

    // extend arm
    for (pos = 100; pos <= 150; pos += 1) {
      left.write(pos);
      right.write(pos);
      delay(15);
    }
    
    delay(1000);

    // close claw and pick up the object
    for (pos = 140; pos >= 70; pos -= 1) {
      claw.write(pos);
      delay(15);
    }
    
    delay(1000);

    // retract arm: split them!!!!
    for (pos = 150; pos >= 100; pos -= 1) {
      left.write(pos);
      right.write(pos);
      delay(15);
    }
    
    delay(1000);

    // turn right to the middle position
    for (pos = 150; pos >= 90; pos -= 1) {
      middle.write(pos);
      delay(15);
    }
    
    counter++; // increase counter by 1
 }
  
}
