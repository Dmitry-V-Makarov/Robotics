#define LED1 2
#define LED10 11
#define LED_ON 2

#define TEMP_SENS_PIN A0
#define LIGHT_SENS_PIN A1

#define BUZZER_PIN 13
#define BUTTON_PIN 12

//определение порогового значения 
//для сигнализации о повышении температуры
#define THRESHOLD 170

//переменные для хранения показаний датчиков
int temperature = 0;
int lightness = 0;

//переменная для временного хранения значения,
//полученного с одного из датчиков, 
//которое будет использовано для расчета количества зажигаемых светодиодов
int countLeds = 0;

boolean previous = true;
boolean trigger = false;

void setup() {
  for(int i= LED1; i <= LED10; i++)
    pinMode(i, OUTPUT);
  
  pinMode(BUZZER_PIN, OUTPUT);
  pinMode(BUTTON_PIN, INPUT);
  
  Serial.begin(9600);
  //однократно выводимая подсказка о том, 
  //каким символом можно запросить параметры среды
  Serial.println("t for temperature, l for lightness");
}

void loop() {
  temperature = analogRead(TEMP_SENS_PIN);
  lightness = analogRead(LIGHT_SENS_PIN);
  
  if (Serial.available() > 0)
  {
    char mode = Serial.read();
    //проверка пришедшего символа на равенство строчной t
    //ИЛИ (||) заглавной T
    if(mode == 't' || mode == 'T')
    {
      Serial.print("Temperature: ");
      Serial.print("\t");
      Serial.println(temperature);
    }
    if(mode == 'l' || mode == 'L')
    {
      Serial.print("Lightness: ");
      Serial.print("\t");
      Serial.println(lightness);
    }
  }
  
  
  boolean current = digitalRead(BUTTON_PIN);
  if(!current && previous)
    trigger = !trigger;
 
  previous = current;
  
  //в зависимости от истинности trigger
  //в countLeds запишется или значение с датчика температуры
  //или значение с датчика освещенности
  if(trigger)
    countLeds = temperature;
  else 
    countLeds = lightness;
    
  int lastLed = map(countLeds, 0, 800, 2, 11); //initially set at 500
  
  for(int i = LED1; i <= lastLed; i+=1)
  {
    digitalWrite(i, HIGH);
    delay(LED_ON);
    digitalWrite(i, LOW);
  }
  
  //генерация звукового сигнала
  //в случае превышения температурой порогового значения
  if(temperature > THRESHOLD)
    noTone(BUZZER_PIN);
    // tone(BUZZER_PIN, 2000, 1000);
  //(единственная инструкция в if, так же как в for, 
  //может не заключаться в фигурные скобки)
}
