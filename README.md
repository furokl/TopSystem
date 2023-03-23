# TopSystem
<p align="right">
  <picture>
    <img alt="YOUR-ALT-TEXT" src="https://tadviser.ru/images/thumb/2/24/Топ_Системы_ЛОГО2.png/800px-Топ_Системы_ЛОГО2.png" width=200 height=50>
  </picture>
</p>

<details>
<summary>Техническое задание</summary>

<p>Необходимо привести пример программы или библиотеки на C++,<br> которая выводит на экран различные геометрические фигуры: круг, квадрат, треугольник, прямоугольник и т.п.<br>
Глубина проработки примера (количество фигур, параметры, методы) на Ваше усмотрение.<br> Программа не обязательно должна запускаться и работать (хотя это будет плюсом).</p>
<p>Моя реализация с самописными фигурами на консольном приложении С++</p>

```C++
TopSystem.cpp

class Graphics
class Controller
  class Shape
    class Triangle
    class Circle
    class Rectangle // TO DO
      class Point2D
      class Vector2D
``` 
</details>

<details>
<summary>Для сборки проекта при помощи cmake</summary>
  
```txt
cd "repository_path"\TopSystem
mkdir build
cd build
cmake -G "Visual Studio 17 2022" ..

Используйте cmake --help, чтобы отобразить список возможных платформ
```
</details>
