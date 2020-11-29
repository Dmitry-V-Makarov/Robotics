import processing.serial.*;
Serial port;

float angle;
float distance;
String data = "";
int index = 0;
int xpos = 0;
int ypos = 0;

void setup()
{
  size (600,300);
  port = new Serial(this, "COM6", 9600);
  port.bufferUntil(';');
  background(255,255,255);
}

void draw()
{
  fill(255,0,0);
  noStroke();
  ellipse(xpos,ypos,3,3);

}

void serialEvent (Serial port)
{
  data = port.readStringUntil(';');
  data = data.substring(0, data.length() - 1);
  index = data.indexOf(':');
  angle = float(data.substring(0,index));
  distance = float(data.substring(index + 1, data.length())); 
  xpos = int(distance * cos(radians(angle)));
  ypos = int(distance * sin(radians(angle)));
  if (xpos > 300 || xpos < -300 || ypos > 300 || ypos < 0) 
  {
    xpos = 0;
    ypos = 0;
  }
  xpos = xpos + 300;
  ypos = 300 - ypos;
}

void mouseClicked()
{
  background(255,255,255);
}
