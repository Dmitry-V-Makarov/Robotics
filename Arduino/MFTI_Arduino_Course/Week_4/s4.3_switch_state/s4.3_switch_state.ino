//заготовка скетча, включающая обработку состояний и переходов между ними

//состояниям (которые хранятся в виде чисел) даны имена
#define STATE_STANDBY 0
#define STATE_WATERING 1
#define STATE_NOWATER 2
#define STATE_SENDPAGE 3

//создана переменная для хранения состояний
int state = STATE_STANDBY;
//создана переменная для храниения информации о наличии воды
boolean gotWater;

void setup() {
  

}

void loop() {
  //проверяется переменная, в которой хранится состояние
  switch (state)
  {
    //в случае, если состояние - режим ожидания
    case STATE_STANDBY:
      //проверяется наличие воды, 
      //т.е. далее необходимо создать такую функцию
      checkWater();
      //если пришел запрос на принудительный полив
      //и одновременно вода есть - переход в состояние "полив", 
      //т.е. присвоение переменной state соответствующего значения;
      //нужна функция, проверяющая запросы, которая может сообщить разные ответы
      if (webRequest() == 1 && gotWater)
        state = STATE_WATERING;
      //если запроса на полив не пришло,
      //проверяется запрос данных,
      //если он пришел - переход в состояние "отправка"
      else if (webRequest() == 2)
        state = STATE_SENDPAGE;
      //проверяется наступление условий для полива по датчикам,
      //если они наступили и есть вода - переход в "полив"
      //нужна функция проверки наступления условий 
      if(checkClimate() && gotWater)
        state = STATE_WATERING;
      //если воды нет (значение сохранится в переменную при вызове checkWater())
      //перейти в состояние "нет воды"
      if(!gotWater)
        state = STATE_NOWATER;
      //выход из switch
      break;

    case STATE_WATERING:
        //в состоянии полива его нужно осуществить,
        //будет создана соответствующая функция
        watering();
        //по ее выполнении переход в состояние ожидания
        state = STATE_STANDBY;
      break;

    case STATE_NOWATER:
      //если обнаружено отсутствие воды,
      //должна быть сигнализация, нужна соответствующая функция
      alarm();
      //после сигнализации проверяется запрос на отправку данных;
      //переход в соответствующее состояние, если он пришел
      //лучше дать вариантам ответов функции webRequest() понятные имена
      if(webRequest() == WEB_CLIMATE_REQUEST)
        state = STATE_SENDPAGE;
      //проверка воды, переход в ожидание, если она появилась
      else if(checkWater())
        state = STATE_STANDBY;
      break;

    case STATE_SENDPAGE:
      //нужна функция для отправки страницы
      sendPage();
      //после отправки переход в ожидание
      state = STATE_STANDBY;
      break;
    //в других случаях может потребоваться описание действий,
    //которые выполнятся, если ни один case не сработал
    //default:
    //break;
  }
}
