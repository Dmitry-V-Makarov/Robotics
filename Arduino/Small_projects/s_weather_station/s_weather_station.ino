#define BUTTON_PIN  8
#define LED_PIN  7
#define LIGHTNESS_PIN  A0
#define POT_PIN  A1
#define TEMP_PIN  A2

 
void setup()
{
  // открываем монитор Serial-порта
  Serial.begin(9600);
  
  // настраиваем пины в режим входа и выхода
  pinMode(BUTTON_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  
}
 
void loop()
{
  // считываем температуру и освещенность
  int lightness = analogRead(LIGHTNESS_PIN);
  int temperature = analogRead(TEMP_PIN);
  
  // выводим в Serial-порт температуру
  Serial.print("Освещенность: ");
  Serial.println(lightness);
  delay(50);
  Serial.print("Температура: ");
  Serial.println(temperature);
  Serial.println('\n');
  delay(2000);
  

  // считываем состояние пина кнопки
  int buttonState = !digitalRead(BUTTON_PIN);

  // если нажата кнопка, включаем LED
  if (buttonState == HIGH) {
    digitalWrite(LED_PIN, HIGH);
  }
  
  // если кнопка не нажата, выполняем условие ниже
  else {
    
    // считываем значение с потенциометра
  int threshold = analogRead(POT_PIN);
  // 
  boolean tooDark = (lightness < threshold);
  if (tooDark) {
    // ...включаем освещение
    digitalWrite(LED_PIN, HIGH);
  } else {
    // ...иначе свет не нужен — выключаем его
    digitalWrite(LED_PIN, LOW);
  }
  
  }
  
  
  
}
