#include <iostream>
#include <string>
#include <sstream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Date {
public:
    enum day { ПОН = 1, ВТР = 2, СРД = 3, ЧТВ = 4, ПТН = 5, СУБ = 6, ВСК = 7};

    Date(int dayUser) {
        if (dayUser >= 1 and dayUser <= 7) {
            dayNum = dayUser;
            dayName = static_cast<day>(dayUser);
        }
        
    }
    friend ostream& operator<<(ostream& os, const Date& _date) {
        switch (_date.dayName) {
        case 1:
            os << "ПОН";
            break;
        case 2:
            os << "ВТР";
            break;
        case 3:
            os << "СРД";
            break;
        case 4:
            os << "ЧТВ";
            break;
        case 5:
            os << "ПТН";
            break;
        case 6:
            os << "СУБ";
            break;
        case 7:
            os << "ВСК";
            break;
        }
        return os;
    }

    void setDay(int dayUser) {
        if (dayUser <= 7 and dayUser >= 1) {
            dayNum = dayUser;
            dayName = static_cast<day>(dayUser);
        }
        else {
            cout << "Ошибка" << endl;
        }
    }

    Date& operator++() {
        ++dayNum;
        if (dayNum == 8)
            dayNum = 1;
        dayName = static_cast<day>(dayNum);
        return *this;
    }

    Date operator++(int) {
        Date result = *this;
        ++(*this);
        return result;
    }

    Date& operator--() {
        --dayNum;
        if (dayNum == 0)
            dayNum = 7;
        dayName = static_cast<day>(dayNum);
        return *this;
    }

    Date operator--(int) {
        Date result = *this;
        --(*this);
        return result;
    }
private:
    day dayName;
    int dayNum;
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Date day(Date::ПОН);
    while (true)
    {
        cout << "Ваша дата: " << day << endl;
        cout << "Операции" << endl;
        cout << "1. Добавить день" << endl;
        cout << "2. Отнять день" << endl;
        cout << "0. Завершить" << endl;
        switch (_getch())
        {
        case '1':
            system("cls");
            day++;
            break;

        case '2':
            system("cls");
            day--;
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