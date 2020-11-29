//макроопределения только для пина первого светодиода из сборки
#define LED1 2
//и последнего
#define LED10 11
//длительность свечения каждого светодиода
#define LED_ON 200

void setup() {
  //конфигурация всех пинов со светодиодами
  for(int i= LED1; i <= LED10; i++)
    pinMode(i, OUTPUT);
}

void loop() {
  //поочередное включение всех ножек на LED_ON миллисекунд
  //начиная с LED1, заканчивая LED10
  for(int i = LED1; i <= LED10; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }

}
