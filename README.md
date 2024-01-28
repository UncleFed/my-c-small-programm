# my-c-small-programm
for cadexchanger.com

Тестовое задание на позицию C++ разработчика

Задание нацелено на оценку уровня владения языком программирования, математического анализа
или вычислительной геометрии и способности разобраться в новом материале при необходимости.
Задание составлено на английском языке, т.к. большая часть технической информации в будущем
будет доступна именно на нем.
Пожалуйста, внимательно прочтите все обязательные требования! Вы также можете выполнить
дополнительные задания (под «звездочкой»), это может стать Вашим преимуществом перед другими
кандидатами.
Ответ следует направить на адрес jobs@cadexchanger.com, в виде ссылки на проект на github,
который должен включать исходный код (*.h, *.cpp), а также проектные файлы.
-----------------------------------------------

Design a small program in C++ that would implement support of 3D curves hierarchy.
Разработайте небольшую программу на C++, реализующую поддержку иерархии 3D-кривых.

1. Support a few types of 3D geometric curves – circles, ellipses and 3D helixes. (Simplified
definitions are below). Each curve should be able to return a 3D point and a first derivative (3D
vector) per parameter t along the curve.
   Поддержка нескольких типов 3D-геометрических кривых — кругов, эллипсов и 3D-спиралей. (Упрощенные
определения ниже). Каждая кривая должна иметь возможность возвращать трехмерную точку и первую производную (3D
вектор) по параметру t вдоль кривой.

2. Populate a container (e.g. vector or list) of objects of these types created in random manner with
random parameters.
   Заполните контейнер (например, вектор или список) объектов этих типов, созданных случайным образом, с помощью
случайных параметров.

3. Print coordinates of points and derivatives of all curves in the container at t=PI/4.
   Вывести координаты точек и производные всех кривых в контейнере при t=PI/4.

4. Populate a second container that would contain only circles from the first container. Make sure the
second container shares (i.e. not clones) circles of the first one, e.g. via pointers.
   Заполните второй контейнер, который будет содержать только круги из первого контейнера. Убедитесь, что
второй контейнер разделяет (т.е. не клонирует) круги первого, например. через указатели.

5. Sort the second container in the ascending order of circles’ radii. That is, the first element has the
smallest radius, the last - the greatest.
   Отсортируйте второй контейнер в порядке возрастания радиусов кругов. То есть первый элемент имеет
наименьший радиус, последний – наибольший.

6. Compute the total sum of radii of all curves in the second container.
   Вычислите общую сумму радиусов всех кривых во втором контейнере.

(*) Additional optional requirements:
    Дополнительные необязательные требования:

7. Split implementation into a library of curves (.dll or .so) and executable which uses API of this
library.
   Разделите реализацию на библиотеку кривых (.dll или .so) и исполняемый файл, который использует API этой
библиотеки.

8. Implement computation of the total sum of radii using parallel computations (e.g. OpenMP or Intel
TBB library).
   Реализуйте вычисление общей суммы радиусов с помощью параллельных вычислений (например, OpenMP или Intel TBB 
library).


Requirements to the implementation:

1. The implementation must use virtual methods.
   Реализация должна использовать виртуальные методы.

2. Has neither explicit memory deallocation nor memory leaks.
   Не должно быть ни явного освобождения памяти, ни утечек памяти.

3. Curves must be physically correct (e.g. radii must be positive).
   Кривые должны быть физически правильными (например, радиусы должны быть положительными).

4. Containers and sorting must be implemented using STL (C++ Standard Template Library).
   Контейнеры и сортировка должны быть реализованы с использованием STL (стандартная библиотека шаблонов C++).

5. The implementation may use constructs of C++11 or higher.
   Реализация может использовать конструкции C++11 или выше.

6. The code must compile with any compiler of your choice (gcc, Visual C++, etc).
   Код должен скомпилироваться любым компилятором по вашему выбору (gcc, Visual C++ и т. д.).

Curve definitions:

- All curves are parametrically defined, i.e. a point is calculated using some C(t) formula.
- Circle is planar in the plane XoY (i.e. all Z-coordinates are 0) and is defined by its radius.
- Ellipse is planar in the plane XoY and is defined by its two radii, along X and Y axes.
- Helix is spatial and is defined by its radius and step (see the figure below). It takes 2 * PI in
parametric space to make a round, i.e. any point on helix satisfies the condition C(t + 2*PI) = C(t) +
{0, 0, step}.
