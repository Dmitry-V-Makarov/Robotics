#define LED1 2
#define LED10 11
#define LED_ON 2

//пин, с которого будет считываться аналоговый сигнал
#define ANALOG_IN A0

void setup() {
  for(int i= LED1; i <= LED10; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  //сохранение в переменную результата работы map(), 
  //которая вернет значение, считанное с аналогового входа, 
  //и пропорционально отмасштабированное из диапазона 0-1023 в диапазон 2-11
  int lastLed = map(analogRead(ANALOG_IN), 0, 1023, 2, 11);
  
  //попробуйте сделать выходной диапазон выходной диапазон 11-2!
  
  //включение и выключение светодиодов на ножках 
  //от начальной до вычисленной выше конечной
  for(int i = LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }

}
