exp
===
Простая многоагентная система.
Среда состоит из трёх объектов: дом, лес и колодец. Два агента, находящихся в этой среде работают, пребывая в соответствующих состояниях работы.

Особенности
-----------
- Мир легко дополняется новыми объектами при помощи LUA-скриптов
- Состояния могут быть отредактированы, т.к. существуют в виде скриптов
- Часть состояний существует в виде кода на языке C++. Состояния, написанные на C++ и на LUA не имеют отличий при использовании
- Агент выполняет действия над средой через интерфейс мира
- Агент может узнать доступные ему действия через интерфейс мира
- Агент может выполнить только доступные на локации действия