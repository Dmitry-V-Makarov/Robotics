
// OPTION 1

#define HANDLE A4 // вход потенциометра, only some pins support PWM
#define LED 10 // вход светодиода

int val; // вводим переменную val

void setup() {
  //объявляем режим работы пинов
  pinMode(HANDLE,INPUT);
  pinMode(LED,OUTPUT);
}
void loop() {
  //принимаем сигнал от потенциометра и передаём на светодиод 
  val = analogRead(HANDLE);
  val = map(val, 0, 1023, 0, 255); //меняем диапазон
  analogWrite(LED, val);
  delay(15);
}


// OPTION 2

/* int ledPin = 10;
int analogPin = 4;
int val = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  val = analogRead(analogPin);
  analogWrite(ledPin, val / 4);
} */
