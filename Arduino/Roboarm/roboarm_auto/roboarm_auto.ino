#include <Servo.h> 
 
Servo middle, fwd, up, claw ;  // creating 4 "servo objects"

int N = 1; // number of times we want the robot to move
int counter = 0; // will increase by 1 after every loop
int pos = 0; // position of servo
 
void setup() // attach servos to pins and set initial position

{
  Serial.begin(9600); // initialize serial connection
  
  // attaching servos to pins
  middle.attach(6);  // rotation
  fwd.attach(9);  // left servo, forward movement, should be same as "right"
  up.attach(10);  // right servo, forward movement, should be same as "left"
  claw.attach(11);  // claw

  // roboarm initial position
  middle.write(94);
  fwd.write(100);
  up.write(100);
  claw.write(94);

  // starting and ending position: middle 94, fwd 100, up 100, claw 94
  // grabbing position: middle 125, fwd 145, up 145, claw 120
  // transportation position: middle --, fwd 80, up 160, claw 94
  // leaving position: middle 60, fwd 150, up 145, claw 120
  
  // status
  Serial.println("Roboarm ready");
  
  delay(2000); // wait 2 seconds
} 
 
void loop() // turn left, extend the arm and pick up the piece
 
{ 
  if (counter < N) // N times the robot will move
 {
    
    // turn left
    for (pos = 94; pos <= 125; pos += 1) {
      middle.write(pos);
      delay(15);
    }
    
    delay(1000);

    // open claw
    for (pos = 94; pos <= 120; pos += 1) {
      claw.write(pos);
      delay(15);
    }

    delay(1000);

    // move up
    for (pos = 100; pos <= 145; pos += 1) {
      up.write(pos);
      delay(15);
    }

    delay(1000);

    // move fwd
    for (pos = 100; pos <= 145; pos += 1) {
      fwd.write(pos);
      delay(15);
    }
    
    delay(1000);

    // close claw and pick up the object
    for (pos = 120; pos >= 94; pos -= 1) {
      claw.write(pos);
      delay(15);
    }
    
    delay(1000);

    // move up to transportation pos
    for (pos = 145; pos <= 160; pos += 1) {
      up.write(pos);
      delay(15);
    }
    
    delay(1000);

    // retract arm
    for (pos = 145; pos >= 80; pos -= 1) {
      fwd.write(pos);
      delay(15);
    }
    
    delay(1000);

    // turn right to the leaving pos
    for (pos = 130; pos >= 60; pos -= 1) {
      middle.write(pos);
      delay(15);
    }

    // move down
    for (pos = 160; pos >= 150; pos -= 1) {
      up.write(pos);
      delay(15);
    }

    delay(1000);

    // move fwd
    for (pos = 80; pos <= 140; pos += 1) {
      fwd.write(pos);
      delay(15);
    }

    delay(1000);

    // open claw and drop object
    for (pos = 94; pos <= 120; pos += 1) {
      claw.write(pos);
      delay(15);
    }

    delay(1000);

    // move down to initial
    for (pos = 150; pos >= 100; pos -= 1) {
      up.write(pos);
      delay(15);
    }
    
    delay(1000);

    // retract arm
    for (pos = 140; pos >= 100; pos -= 1) {
      fwd.write(pos);
      delay(15);
    }
    
    delay(1000);

    // close claw
    for (pos = 120; pos >= 94; pos -= 1) {
      claw.write(pos);
      delay(15);
    }
    
    delay(1000);

    // turn left
    for (pos = 60; pos <= 94; pos += 1) {
      middle.write(pos);
      delay(15);
    }

    
    
    counter++; // increase counter by 1
 }
  
}
