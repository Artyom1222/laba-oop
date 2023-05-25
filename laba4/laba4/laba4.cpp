#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Circle {
protected:
    double radius;
public:
    Circle(double radius) {
        this->radius = radius;
    }
    double getArea() {
        return radius * radius * 3.14;
    }
    double getRadius() {
        return radius;
    }
    virtual void info() {
        cout << "Радиус: " << radius << endl << endl;
        cout << "Площадь: " << getArea() << endl << endl;
    }
};

class Elips : public Circle {
protected:
    double sma;
public:
    Elips(double radius, double sma) : Circle(radius), sma(sma){}
    virtual void info() {
        cout << "Радиус: " << radius << endl;
        cout << "Вторая полуось: " << sma << endl << endl;
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Circle circle(2);
    Elips elips(3, 5);
    Circle* poli;
    double side1, side2;
    while (1) {
        cout << "Операции" << endl;
        cout << "1. Задать круг" << endl;
        cout << "2. Задать эллипс" << endl;
        cout << "3. Вывод параметров круга" << endl;
        cout << "4. Вывод параметров эллипса" << endl;
        cout << "5. Работа динамического полиморфизма" << endl;
        cout << "0. Закончить" << endl;
        switch (_getch())
        {
        case '1':
            system("cls");
            cout << "Введите радиус круга " << endl;
            cin >> side1;
            circle = Circle(side1);
            system("cls");
            break;

        case '2':
            system("cls");
            cout << "Введите радиус эллипса и значение второй полуоси " << endl;
            cin >> side1 >> side2;
            elips = Elips(side1, side2);
            system("cls");
            break;

        case '3':
            system("cls");
            cout << "Параметры вашего круга " << endl << endl;
            circle.info();
            break;

        case '4':
            system("cls");
            cout << "Параметры вашего эллипса " << endl << endl;
            elips.info();
            break;

        case '5':
            system("cls");
            cout << "Динамический полиморфизм" << endl;
            cout << "Круг///" << endl;
            poli = &circle;
            poli->info();
            cout << "Эллипс///" << endl;
            poli = &elips;
            poli->info();

            break;

        case '0':
            return 0;
            break;
        default:
            system("cls");
            break;
        }
    }

    return 0;
}
