// Подключаем библиотеку для работы с дисплеем
#include <QuadDisplay2.h>
// создаём объект класса QuadDisplay и передаём номер пина CS
QuadDisplay qd(10);
// создаем объекты класса bute для хранения текущего значения Часов, Минут, Секунд
int hours = 0;
int minutes = 0;
int seconds = 0;
// создаем объект класса long для хранения счетчика
long lastTime = 0;

void setup() {
   // инициализация дисплея
  qd.begin();
  // инициализируем время
  setTime(__TIMESTAMP__);
}

void loop() {
  // как только разница между текущим временем и временем записанным в lastTime становится больше 1000 миллисекунд...
  while(millis()-lastTime > 1000) {
    //...обновляем  lastTime и добавляем к счетчику Секунд +1
    lastTime = millis();
    seconds++;
    // как только счетчик секунд достигнет 60, обнуляем его и добавляем к счетчику Минут +1...
    if (seconds >= 60) {
       seconds = 0;
       minutes++;
    }
    // ...тоже самое для Часов...
    if (minutes >= 60) {
       minutes = 0;
       hours++;
    }
    // ... и обнуляем счетчик Часов в конце дня
    if (hours >= 24) {
       hours = 0;
    }
  }
  // выводим время на дисплей
  qd.displayScore(hours, minutes, true);
}

// функция записи текущего времени в переменные

void setTime(const char* compileTimeStamp) 
{
    hours = ((compileTimeStamp[11] - '0') * 10
        + (compileTimeStamp[12] - '0'));

    minutes = ((compileTimeStamp[14] - '0') * 10
        + (compileTimeStamp[15] - '0'));

    seconds = ((compileTimeStamp[17] - '0') * 10
        + (compileTimeStamp[18] - '0'));
}
