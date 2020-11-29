#define STEP_PIN 7
#define DIR_PIN 8
#define EN_PIN 9

//миллисекнд на шаг - 
//этой константой можно регулировать скорость вращения
#define STEP_MILLIS 20
//количество шагов, которое мотор будет делать
#define STEPS 200

void setup()
{
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);
  pinMode(EN_PIN, OUTPUT);

}

void loop()
{
  //подача напряжения на enable драйвера
  digitalWrite(EN_PIN, HIGH);
  //выбор направления
  digitalWrite(DIR_PIN, HIGH);

  //в цикле включается и выключается пин драйвера, отвечающий за шаги,
  //столько раз, сколько записано в константе
  for (int i = 0; i < STEPS; i++)
  {
    digitalWrite(STEP_PIN, HIGH);
    delay(STEP_MILLIS);

    digitalWrite(STEP_PIN, LOW);
    delay(STEP_MILLIS);
  }

  //режим удержания вала
  analogWrite(EN_PIN, 100);
  delay(3000);
  //изменение направления
  digitalWrite(DIR_PIN, LOW);
  digitalWrite(EN_PIN, HIGH);

  for (int i = 0; i < STEPS; i++)
  {
    digitalWrite(STEP_PIN, HIGH);
    delay(STEP_MILLIS);

    digitalWrite(STEP_PIN, LOW);
    delay(STEP_MILLIS);
  }

  delay(3000);
  digitalWrite(EN_PIN, LOW);


}



