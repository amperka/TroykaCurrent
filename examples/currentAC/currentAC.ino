// библиотека для работы с датчиком тока (Troyka-модуль)
#include <TroykaCurrent.h>

// создаём объект для работы с датчиком тока
// и передаём ему номер пина выходного сигнала
ACS712 sensorCurrent(A0);

void setup()
{
  // открываем последовательный порт
  Serial.begin(9600);
}

void loop()
{
  // вывод показателей сенсора для переменного тока
  Serial.print("Current is ");
  Serial.print(sensorCurrent.readCurrentAC());
  Serial.println(" A");
  delay(100);
}
