#define DATA_PIN    13
#define LATCH_PIN   12
#define CLOCK_PIN   11

#define BUZZER_PIN 8

byte d0 = 0b01111101;
byte d1 = 0b00100100;
byte d2 = 0b01111010;
byte d3 = 0b01110110;
byte d4 = 0b00100111;
byte d5 = 0b01010111;
byte d6 = 0b01011111;
byte d7 = 0b01100100;
byte d8 = 0b01111111;
byte d9 = 0b01110111;


void setup()
{
  pinMode(DATA_PIN, OUTPUT);
  pinMode(CLOCK_PIN, OUTPUT);
  pinMode(LATCH_PIN, OUTPUT);

  Serial.begin(9600);
}

void loop()
{
  if (Serial.available() > 0)
  {
    //вывод сообщения в порт для того, чтобы убедиться, 
    //что в буфере были обнаружены данные
    Serial.println("got data");
    char digit = Serial.read();

    if (digit == '0')
    {
      //генерация звука для индикации считывания символа 0
      tone(BUZZER_PIN, 3000, 1000);
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d0);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '1')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d1);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '2')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d2);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '3')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d3);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '4')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d4);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '5')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d5);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '6')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d6);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '7')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d7);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '8')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d8);
      digitalWrite(LATCH_PIN, HIGH);
    }
    else if (digit == '9')
    {
      digitalWrite(LATCH_PIN, LOW);
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d9);
      digitalWrite(LATCH_PIN, HIGH);
    }
    
  }
  //вывод сообщения в порт для фиксации того факта,
  //что выполнение программы доходит до этого места
  Serial.println("end of loop");
}



