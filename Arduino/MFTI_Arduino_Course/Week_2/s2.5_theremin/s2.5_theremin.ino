#define BUZZER_PIN 8
#define PHOTO_SENS A0

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

}

void loop() {
  //генерация сигнала на BUZZER_PIN
  //с частотой, равной значению, полученному на аналоговом входе, и умноженному на 4
  //продолжительностью 10 миллисекунд
  tone(BUZZER_PIN, analogRead(PHOTO_SENS) * 4, 10);
  
  //если в tone() опустить третий параметр,
  //прекратить сигнал можно с помощью noTone(BUZZER_PIN);
}
