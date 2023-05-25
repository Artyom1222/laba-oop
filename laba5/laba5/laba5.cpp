#include <iostream>
#include <windows.h>
#include <conio.h>
#include "Figure.h"

using namespace std;

string checkMaterial(char);
void infoFig(char);

Shar shar(5, "m");
Prisma prisma(5, 20, "m");
Parallelepiped parallelepiped(5, 20, 25, "m");
Cube cube(5, "m");
Piramida piramida(5, 20, "m");
Conus conus(5, 20, "m");
Cylindr cylindr(5, 20, "m");
PrismaInscribedRectilimealTriangular pirt(5, 20);

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    bool proov = false;

    int a, b, h;//для принятия новых значений usera
    char fig='0';//какая фигура создана пользователем
    string m;
    while (1) {
        cout << "Операции:" << endl;
        cout << "1.Удаление и создание новой фигуры" << endl;
        cout << "2.Узнать информацию о фигуре" << endl;
        cout << "3.Объединение" << endl;
        cout << "0.Завершить" << endl;
        switch (_getch())
        {
        case '1':
            system("cls");
            cout << "Что хотите создать?" << endl;
            cout << "1.Шар" << endl;
            cout << "2.Призму" << endl;
            cout << "3.Параллелепипед" << endl;
            cout << "4.Куб" << endl;
            cout << "5.Пирамида" << endl;
            cout << "6.Конус" << endl;
            cout << "7.Цилиндр" << endl;
            cout << "8.ПРямая призма, основание которой правильный треугольник" << endl;
            switch (_getch())
            {
            case '1':
                system("cls");
                fig = '1';
                cout << "Введите радиус" << endl;
                cin >> a;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                shar.setInfo(a, m);//функция класса(один из которых мы запрогали в файле Figure.h), которая обновляет значения класса
                break;

            case '2':
                system("cls");
                fig = '2';
                cout << "Введите высоту" << endl;
                cin >> h;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                prisma.setInfo(h, m);
                break;

            case '3':
                system("cls");
                fig = '3';
                cout << "Введите высоту" << endl;
                cin >> h;
                cout << "Введите сторону А" << endl;
                cin >> a;
                cout << "Введите сторону B" << endl;
                cin >> b;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                parallelepiped.setInfo(h, a, b, m);
                break;

            case '4':
                system("cls");
                fig = '4';
                cout << "Введите сторону" << endl;
                cin >> a;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                cube.setInfo(a, m);
                break;

            case '5':
                system("cls");
                fig = '5';
                cout << "Введите сторону" << endl;
                cin >> a;
                cout << "Введите высоту" << endl;
                cin >> h;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                piramida.setInfo(h, a, m);
                break;

            case '6':
                system("cls");
                fig = '6';
                cout << "Введите радиус" << endl;
                cin >> a;
                cout << "Введите высота" << endl;
                cin >> h;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                conus.setInfo(h, a, m);
                break;

            case '7':
                system("cls");
                fig = '7';
                cout << "Введите радиус" << endl;
                cin >> a;
                cout << "Введите высоту" << endl;
                cin >> h;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                cylindr.setInfo(h, a, m);
                break;

            case '8':
                system("cls");
                fig = '1';
                cout << "Введите сторону" << endl;
                cin >> a;
                cout << "Введите высоту" << endl;
                cin >> a;
                cout << "Выберите материал" << endl;
                cout << "1.Метал" << endl;
                cout << "2.Дерево" << endl;
                cout << "3.Пластик" << endl;
                cout << "4.Картон" << endl;
                m = checkMaterial(_getch());
                pirt.setInfo(h, a, m);
                break;

            default:
                cout << "Такого пункта нет" << endl;
                break;
            }
            break;

        case '2':
            cout << "Информация о фигуре" << endl;
            switch (fig)
            {
            case '1':
                system("cls");
                cout << shar.type << endl;
                cout << " Материал: " << shar.material << endl;
                cout << " Радиус: " << shar.getRadius() << endl;
                cout << " Площадь: " << shar.getSFull() << endl;
                cout << " Объем: " << shar.getV() << endl;
                cout << " Вес: " << shar.getP(shar.material) << endl;
                break;

            case '2':
                system("cls");
                cout << prisma.type << endl;
                cout << " Материал: " << prisma.material << endl;
                cout << " Высота: " << prisma.getHigh() << endl;
                cout << " Сторона: " << prisma.getSide() << endl;
                cout << " Площадь боковая: " << prisma.getSBok() << endl;
                cout << " Площадь основания: " << prisma.getSOsn() << endl;
                cout << " Площадь: " << prisma.getSFull() << endl;
                cout << " Объем: " << prisma.getV() << endl;
                cout << " Вес: " << prisma.getP(prisma.material) << endl;
                break;

            case '3':
                system("cls");
                cout << parallelepiped.type << endl;
                cout << " Материал: " << parallelepiped.material << endl;
                cout << " Высота: " << parallelepiped.getHigh() << endl;
                cout << " Сторона 1: " << parallelepiped.getA() << endl;
                cout << " Сторона 2: " << parallelepiped.getB() << endl;
                cout << " Площадь боковая: " << parallelepiped.getSBok() << endl;
                cout << " Площадь основания: " << parallelepiped.getSOsn() << endl;
                cout << " Площадь: " << parallelepiped.getSFull() << endl;
                cout << " Объем: " << parallelepiped.getV() << endl;
                cout << " Вес: " << parallelepiped.getP(parallelepiped.material) << endl;
                break;

            case '4':
                system("cls");
                cout << cube.type << endl;
                cout << " Материал: " << cube.material << endl;
                cout << " Cторона: " << cube.getSide() << endl;
                cout << " Площадь основания: " << cube.getSOsn() << endl;
                cout << " Площадь: " << cube.getSFull() << endl;
                cout << " Объем: " << cube.getV() << endl;
                cout << " Вес: " << cube.getP(cube.material) << endl;
                break;

            case '5':
                system("cls");
                cout << piramida.type << endl;
                cout << " Материал: " << piramida.material << endl;
                cout << " Высота: " << piramida.getHigh() << endl;
                cout << " Сторона: " << piramida.getSide() << endl;
                cout << " Площадь основания: " << piramida.getSOsn() << endl;
                cout << " Площадь боковая: " << piramida.getSBok() << endl;
                cout << " Площадь: " << piramida.getSFull() << endl;
                cout << " Объем: " << piramida.getV() << endl;
                cout << " Вес: " << piramida.getP(piramida.material) << endl;
                break;

            case '6':
                system("cls");
                cout << conus.type << endl;
                cout << " Материал: " << conus.material << endl;
                cout << " Радиус: " << conus.getRadius() << endl;
                cout << " Высота: " << conus.getHigh() << endl;
                cout << " Площадь основания: " << conus.getSOsn() << endl;
                cout << " Площадь боковая: " << conus.getSBok() << endl;
                cout << " Площадь: " << conus.getSFull() << endl;
                cout << " Объем: " << conus.getV() << endl;
                cout << " Вес: " << conus.getP(conus.material) << endl;
                break;

            case '7':
                system("cls");
                cout << cylindr.type << endl;
                cout << " Материал: " << cylindr.material << endl;
                cout << " Радиус: " << cylindr.getRadius() << endl;
                cout << " Площадь основания: " << cylindr.getSOsn() << endl;
                cout << " Площадь боковая: " << cylindr.getSBok() << endl;
                cout << " Площадь: " << cylindr.getSFull() << endl;
                cout << " Объем: " << cylindr.getV() << endl;
                cout << " Вес: " << cylindr.getP(cylindr.material) << endl;
                break;

            case '8':
                system("cls");
                cout << pirt.type << endl;
                cout << " Материал: " << pirt.material << endl;
                cout << " Высота: " << pirt.getHigh() << endl;
                cout << " Cторона: " << pirt.getSide() << endl;
                cout << " Площадь основания: " << pirt.getSOsn() << endl;
                cout << " Площадь боковая: " << pirt.getSBok() << endl;
                cout << " Площадь: " << pirt.getSFull() << endl;
                cout << " Объем: " << pirt.getV() << endl;
                cout << " Вес: " << pirt.getP("Метал") << endl;
                break;
            default:
                cout << "Фигура не создана" << endl;
                break;
            }
            break;

        case '3':
            if (fig!='0') {
                infoFig(fig);
            }
            else {
                cout << "Ошибка" << endl;
            }
            break;

        case '0':
            return 0;
            break;

        default:
            system("cls");
            cout << "Такого пункта нет. Выберите другой" << endl;
            break;
        }
    }
}

string checkMaterial(char user) {
    switch (user)
    {
    case '1':
        return "Метал";
        break;

    case '2':
        return "Дерево";
        break;

    case '3':
        return "Пластик";
        break;

    case '4':
        return "Картон";
        break;

    default:
        return "Метал";
        break;
    }
}

void infoFig(char figureFromUser) {
    system("cls");
    int figureConst;
    cout << "С какой фигурой объеденить?" << endl;
    cout << "1.Шар" << endl;
    cout << "2.Призму" << endl;
    cout << "3.Параллелепипед" << endl;
    cout << "4.Куб" << endl;
    cout << "5.Пирамида" << endl;
    cout << "6.Конус" << endl;
    cout << "7.Цилиндр" << endl;
    cout << "8.ПРямая призма, основание которой правильный треугольник" << endl;
    while (1) {
        cin >> figureConst;
        if (figureConst > 8 or figureConst < 1) {
            cout << "Повторите попытку" << endl;
        }
        else {
            break;
        }
    }
    switch (figureConst)
    {
    case 1:
        cout << shar.getV() + 8 * rand();
        break;
    case 2:
        cout << prisma.getV() + 7 * rand();
        break;
    case 3:
        cout << parallelepiped.getV() + 6 * rand();
        break;
    case 4:
        cout << cube.getV() + 5 * rand();
        break;
    case 5:
        cout << piramida.getV() + 4 * rand();
        break;
    case 6:
        cout << conus.getV() + 3 * rand();
        break;
    case 7:
        cout << cylindr.getV() + 2 * rand();
        break;
    case 8:
        cout << pirt.getV() + rand();
        break;
    default:
        break;
    }
    return;
}