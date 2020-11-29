#define LED_PIN 13
#define BUTTON_PIN 7

//переменные для хранения логических значений
//в trigger будет храниться состояние светодиода (вкл/выкл)
boolean trigger = false;
//в previous будет храниться предыдущее состояние кнопки
boolean previous = false;

void setup() {
  pinMode(LED_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);  
}

void loop() {
  //текущее состояние кнопки будет записываться в current
  boolean current = digitalRead(BUTTON_PIN);
  //в случае, если одновременно в current хранится "истина",
  //и в previous хранится "ложь"
  //(т.е. инвертированное с помощью ! значение previous - истина)
  //в trigger будет записано его же инвертированное значение 
  if(current && !previous)
  {
    trigger = !trigger;
  }
  //в previous записывается значение current,
  //т.е. нынешнее текущее значение,
  //которое на следующей итерации loop() будет предыдущим
  previous = current;
  
  //запись trigger на LED_PIN, 
  //т.е. включение светодиода, если в trigger сейчас "истина"
  //и выключеие, если в trigger - "ложь" 
  digitalWrite(LED_PIN, trigger);
  
  //напоминание про операторы сравнения:
  // == проверка равенства
  // != проверка неравенства 
  // >  больше 
  // <  меньше
  // <= меньше или равно
  // >= больше или равно
}
