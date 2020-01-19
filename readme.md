# digitalWriteAVR
Библиотека для более удобного использования портов в микроконтроллерах AVR

## Использование
`#include "WFast.h"`

...
* `pinMode`(PB4, `OUTPUT`);
* `digitalWrite`(PB4, `HIGH`);


Функции библиотеки
* `digitalWrite(pinNum, state)` (Запись состояния порта)
* `pinMode(pinNum, state)` (Определение порта ввод/вывод)
* `digitalRead(pinNum)` (Прочитать состояние порта)

Параметры
* `pinNum` - Номер порта (С0 - D7)
* `state` - Состояние порта. Принимает значения `HIGH` или `LOW`
* `mode` - Состояние порта. Принимает значение `INPUT` или `OUTPUT`

Для быстрого переключения портов были использованы макросы `define` вместо функций

## Адресация
* `PORTC` - C0, C1, C2, C3, C4, C5, C6, C7
* `PORTB` - B0, B1, B2, B3, B4, B5, B6, B7
* `PORTD` - D0, D1, D2, D3, D4, D5, D6, D7

