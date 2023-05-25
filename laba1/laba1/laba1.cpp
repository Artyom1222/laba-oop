#include <iostream>
#include <windows.h>
#include <conio.h>

using namespace std;

class Account {
private:
    string surname, numCard, dateOpen;
    double percentCalc;
    double money;
public:
    Account(string surnameReg, string numCardReg, double moneyReg, double percentReg, string date) {
        surname = surnameReg;
        numCard = numCardReg;
        money = moneyReg;
        percentCalc = percentReg;
        dateOpen = date;
    }
    void print() {
        cout << "Фамилия: " << surname << endl;
        cout << "Номер карты: " << numCard << endl;
        cout << "Дата создания: " << dateOpen << endl;
        cout << "Процент начисления: " << percentCalc << endl;
        cout << "Рубли: " << money << endl <<endl;
    }
    void changePerson(string newPerson) {
        surname = newPerson;
        system("cls");
        cout << "Владелец сменен" << endl;
    }

    void takeMoney(double howMuch) {
        if (howMuch <= money) {
            money -= howMuch;
            system("cls");
            cout << "Сумма успешно снята" << endl;
        }
    }

    void newMoney(double howMuch) {
        money += howMuch*((percentCalc+100)/100);
        system("cls");
        cout << "Сумма успешно положена" << endl;
    }

    void newPerс(double newPer) {
        percentCalc = newPer;
    }
};

int main()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    Account acc("Kovalenko", "5446849", 1500, 50, "05.05.2023");
    double operation;
    string newSur;
    while (true)
    {
        acc.print();
        cout << "Операции" << endl;
        cout << "1. Сменить владельца" << endl;
        cout << "2. Вывести деньги" << endl;
        cout << "3. Положить деньги" << endl;
        cout << "4. Поменять процент" << endl;
        cout << "0. Завершить" << endl;
        switch (_getch())
        {
        case '1':
            system("cls");
            cout << "Введите владельца" << endl;
            cin >> newSur;
            acc.changePerson(newSur);
            break;

        case '2':
            system("cls");
            cout << "Введите сумму" << endl;
            cin >> operation;
            acc.takeMoney(operation);
            break;

        case '3':
            system("cls");
            cout << "Введите сумму" << endl;
            cin >> operation;
            acc.newMoney(operation);
            break;

        case '4':
            system("cls");
            cout << "Введите процент" << endl;
            cin >> operation;
            acc.newPerс(operation);
            break;

        case '0':
            return 0;
            break;
        default:
            break;
        }
    }
}
