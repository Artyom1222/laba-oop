#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class ComplexNumber {
private:
    double x, y;
public:
    ComplexNumber(double xUser, double yUser) {
        y = yUser;
        x = xUser;
    }

    void print() {
        cout << x << ", " << y;
    }

    ComplexNumber operator+(ComplexNumber sec){
        ComplexNumber out(x+sec.x,y+sec.y);
        return out;
    }

    ComplexNumber operator-(ComplexNumber sec) {
        ComplexNumber out(x - sec.x, y - sec.y);
        return out;
    }

    ComplexNumber operator*(ComplexNumber sec) {
        ComplexNumber out(x * sec.x, y * sec.y);
        return out;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    double newX, newY;
    ComplexNumber first(2, 2), second(5, 5), operation(0,0);
    while (true)
    {
        cout << "Первое число: " << endl;
        first.print(); cout << endl;
        cout << "Второе число: " << endl;
        second.print(); cout << endl <<endl;
        cout << "Операции" << endl;
        cout << "1. Поменять 1ое число" << endl;
        cout << "2. Поменять 2ое число" << endl;
        cout << "3. Сложить" << endl;
        cout << "4. Умножить" << endl;
        cout << "5. Вычесть" << endl;
        cout << "0. Закончить" << endl;
        switch (_getch()) {
        case '1':
            system("cls");
            cout << "Введите действительную и мнимую части" << endl;
            cin >> newX >> newY;
            first = ComplexNumber(newX,newY);
            system("cls");
            break;

        case '2':
            system("cls");
            cout << "Введите действительную и мнимую части" << endl;
            cin >> newX >> newY;
            second = ComplexNumber(newX, newY);
            system("cls");
            break;

        case '3':
            system("cls");
            operation = first + second;
            first.print(); cout << '+'; second.print(); cout << '='; operation.print(); cout << endl;
            break;

        case '4':
            system("cls");
            operation = first * second;
            first.print(); cout << '*'; second.print(); cout << '='; operation.print(); cout << endl;
            break;

        case '5':
            system("cls");
            operation = first - second;
            first.print(); cout << '-'; second.print(); cout << '='; operation.print(); cout << endl;
            break;

        case '0':
            return 0;
            break;
        default:
            system("cls");
            break;
        }
    }
}
