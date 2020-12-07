///////////////////////////////////////////// 
//        RemoteXY include library         // 
///////////////////////////////////////////// 

// RemoteXY select connection mode and include library 
#define REMOTEXY_MODE__SOFTSERIAL
#include <SoftwareSerial.h>

#include <RemoteXY.h>

// RemoteXY connection settings 
#define REMOTEXY_SERIAL_RX 12
#define REMOTEXY_SERIAL_TX 13
#define REMOTEXY_SERIAL_SPEED 9600 

// RemoteXY configurate  
#pragma pack(push, 1)
uint8_t RemoteXY_CONF[] =
  { 255,1,0,0,0,11,0,10,13,1,
  4,32,39,14,12,68,2,26 };
  
// this structure defines all the variables and events of your control interface 
struct {

    // input variables
  int8_t slider_base; // =-100..100 slider position 

    // other variable
  uint8_t connect_flag;  // =1 if wire connected, else =0 

} RemoteXY;
#pragma pack(pop) 

///////////////////////////////////////////// 
//           END RemoteXY include          // 
///////////////////////////////////////////// 

#include <Servo.h>  

Servo servo_base; 


void setup()  
{ 
  RemoteXY_Init ();  
     
  // TODO you setup code 
  myservo.attach(9); 
  RemoteXY.slider_base = 50; 
   
} 

void loop()  
{  
  RemoteXY_Handler (); 

  // TODO you loop code 
  // use the RemoteXY structure for data transfer 

  int ms = RemoteXY.slider_base*20+500; 
  servo_base.writeMicroseconds(ms); 

}
