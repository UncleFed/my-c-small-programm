// Тестовое задание на позицию C++ разработчика
// Задание нацелено на оценку уровня владения языком программирования, математического анализа
// или вычислительной геометрии и способности разобраться в новом материале при необходимости.
// Пожалуйста, внимательно прочтите все обязательные требования! Вы также можете выполнить
// дополнительные задания (под «звездочкой»), это может стать Вашим преимуществом перед другими
// кандидатами.
// Ответ следует направить на адрес jobs@cadexchanger.com, в виде ссылки на проект на github,
// который должен включать исходный код (*.h, *.cpp), а также проектные файлы.

#include <iostream>
#include <algorithm>
#include <vector>
#include <time.h>
#include <iomanip>
#include <cmath>

using namespace std;

#include "curves.h" 

void printData(Circle *cur, double t)
{
    vector <double> wv;
    wv = cur->getPoint(t);
    cout << "Point on T = " << t << " : x = " << wv[0] << " : y = " << wv[1] << " : z = " << wv[2] << endl;
    wv = cur->getFirstDer(t);
    cout << "First Der on T = " << t << " : x = " << wv[0] << " : y = " << wv[1] << " : z = " << wv[2] << endl;
}

bool fcmp(Circle first, Circle second) 
{
    return first.a < second.a;
}

int main() {

// 2. Заполните контейнер (например, вектор или список) объектов этих типов, созданных случайным образом, с помощью
//    случайных параметров.
// 3. Выведите координаты точек и производные всех кривых в контейнере при t=PI/4.
// 4. Заполните второй контейнер, который будет содержать только круги из первого контейнера. Убедитесь, что
//    второй контейнер разделяет (т.е. не клонирует) круги первого, например. через указатели.

    vector <Circle *> cont1(100);
    vector <Circle *> cont2;

    srand(time(NULL));  // Генерирует случайное число, используя текущие дату и время как параметр

    int t, num_of_cyrcles = 0;
    double rx, ry, st;
    Circle wc;
    Ellipse we;
    Helix wh;

    cout << fixed << setprecision(2) << endl;

    for (int i = 0; i < 100; i++) {
        t = rand() % 3;
        switch (t) {
            case 0:    // Circle
                rx = (rand() % 100 + 15) / 10.0;
                wc = Circle(rx);
                cont2.push_back(&wc);   // копируется указатель на объект, я так думаю 
                cont1[i] = &wc;
                cout << "Circle rx = " << rx << endl;
                printData(&wc, PI/4);
                break;
            case 1:    // Ellipse
                rx = (rand() % 100 + 15) / 10.0;
                ry = (rand() % 100 + 15) / 10.0;
                we = Ellipse(rx, ry);
                cont1[i] = &we;
                cout << "Ellipse rx = " << rx << " ry = " << ry << endl;
                printData(&we, PI/4);
                break;  
            case 2:    // Helix
                rx = (rand() % 100 + 15) / 10.0;
                st = (rand() % 100 + 15) / 20.0;
                wh = Helix(rx, st);
                cont1[i] = &wh;
                cout << "Helix rx = " << rx << " step = " << st << endl;
                printData(&wh, PI/4);
        }
    }

// 5. Отсортируйте второй контейнер в порядке возрастания радиусов кругов. То есть первый элемент имеет
//    наименьший радиус, последний – наибольший.
// 6. Вычислите общую сумму радиусов всех кривых во втором контейнере.
    
    sort(cont2.begin(), cont2.end(), fcmp);
    
    double tsum = 0; 
    for (int i = 0; i < cont2.size(); i++) {
        tsum += cont2[i].a;
        // cout << i << " Circle rx = " << cont2[i].a << endl;
    }
    cout << " Total sum of R in container 2 = " << tsum << endl;
}

