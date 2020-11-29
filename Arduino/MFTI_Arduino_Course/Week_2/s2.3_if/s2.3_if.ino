#define LED_PIN 13
#define ANALOG_IN A0

void setup() {
  pinMode(LED_PIN, OUTPUT);
}

void loop() {
  //в скобках после ключевого слова if описано условие
  //условие - это логическое выражение, которое может быть истинным или ложным
  if(analogRead(ANALOG_IN) > 512)
  {
    //внутри фигурных скобок - те действия,
    //которые выполнятся, если условие при if истинно
    digitalWrite(LED_PIN, HIGH);
  }
  //после else можно описать действия, 
  //которые следует выполнить, если условие при if ложно
  else
  {
    digitalWrite(LED_PIN, LOW);
  }
    
  //попробуйте другие условия: if(digitalRead(DIGITAL_IN) == HIGH),
  //сравните с if(digitalRead(DIGITAL_IN)) 
  
  //digitalRead() возвращает логическое значение, 
  //т.е. его не обязательно сравнивать с HIGH или LOW
    
}
