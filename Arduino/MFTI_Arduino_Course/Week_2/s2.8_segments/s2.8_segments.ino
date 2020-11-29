//пины, к которым подключен выходной сдвиговый регистр:
#define DATA_PIN    13
#define LATCH_PIN   12
#define CLOCK_PIN   11

//пин пьезодинамика
#define BUZZER_PIN 8

//переменные, в каждой из которых хранится один байт
//записанный побитно (после 0b) так, что каждый бит кодирует включение
//или выключение одного сегмента индикатора, 
//и комбинация включенных сегментов образует соответствующий символ-цифру
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
  //начало соединения на скорости 9600 бод
  Serial.begin(9600);
}

void loop()
{
  //проверка наличия данных в буфере
  if (Serial.available() > 0)
  {
    //запись считанного в буфере байта в переменную
    char digit = Serial.read();

    //проверка соответствия сохраненного символа символу 0 (не числу 0!)
    if (digit == '0')
    {
      //работа со сдвиговым регистром:
      //перед передачей данных установка LATCH_PIN в LOW
      digitalWrite(LATCH_PIN, LOW);
      //последовательная передача содержимого d0, 
      //начиная с младшего бита (LSBFIRS - least significant bit first) 
      //на DATA_PIN с синхронизацией передачи через CLOCK_PIN
      shiftOut(DATA_PIN, CLOCK_PIN, LSBFIRST, d0);
      //перевод LATCH_PIN в HIGH для установки ножек регистра 
      //в состояния, соответствующие переданным битам 
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

}



