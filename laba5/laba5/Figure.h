#include <string>
#include <cmath>

using namespace std;

class Figure {
private:
    double sOsn, sBok, sFull, v, p;
public:
    string type, material;
    Figure(string t, string m) {
        type = t;
        material = m;
    }
    virtual double getSOsn() = 0;
    virtual double getSBok() = 0;
    virtual double getSFull() = 0;
    virtual double getV() = 0;
    virtual double getP(string) = 0;
    //virtual void setInfo(int,string)=0;
};

class Shar : public Figure {
private:
    double radius;
public:
    Shar(double r, string m) : Figure("Shar", m) {//запрашиваем родителя(класс Figure), 
        //чтобы дал нам доступ к своему конструктору, чтобы присвоить тип фигуры(те шар) и материал фигуры(который выберит пользователь)
        radius = r;

    }
    double getRadius() {
        return radius;
    }
    void setInfo(double rUser, string mUser) {
        radius = rUser;
        Figure::material = mUser;
        return;
    }
    double getP(string m) {
        if (m == "Метал")
            return ((4 / 3) * 3.14 * radius * radius * radius) * 7.8;
        else if (m == "Дерево")
            return ((4 / 3) * 3.14 * radius * radius * radius) * 0.69;
        else if (m == "Пластик")
            return ((4 / 3) * 3.14 * radius * radius * radius) * 0.47;
        else if (m == "Картон")
            return ((4 / 3) * 3.14 * radius * radius * radius) * 0.2;
    }
    double getSFull() {
        return 4 * 3.14 * radius * radius;
    }
    double getV() {
        return (4 / 3) * 3.14 * radius * radius * radius;
    }

    double getSOsn() {
        return 0;
    }
    double getSBok() {
        return 0;
    }
};

class Prisma : public Figure {
private:
    double high, sideA;
public:
    Prisma(double h, double sA, string m) : Figure("Prisma", m) {
        high = h;
        sideA = sA;
    }
    double getP(string m) {
        if (m == "Метал")
            return (sideA * sideA * high) * 7.8;
        else if (m == "Дерево")
            return (sideA * sideA * high) * 0.69;
        else if (m == "Пластик")
            return (sideA * sideA * high) * 0.47;
        else if (m == "Картон")
            return (sideA * sideA * high) * 0.2;
    }
    double getSOsn() {
        return sideA * sideA;
    }
    double getHigh() {
        return high;
    }
    double getSide() {
        return sideA;
    }
    double getSBok() {
        return 4 * sideA * high;
    }
    double getSFull() {
        return (sideA * sideA) + (4 * sideA * high);
    }
    double getV() {
        return sideA * sideA * high;
    }
    void setInfo(double hUser, string mUser) {
        high = hUser;
        Figure::material = mUser;
    }
};

class Parallelepiped : public Figure {
private:
    double high, sideA, sideB;
public:
    Parallelepiped(double h, double sA, double sB, string m) : Figure("Parallelepiped", m) {
        high = h;
        sideA = sA;
        sideB - sB;
    }
    void setInfo(double hUser, double aUser, double bUser, string mUser) {
        high = hUser;
        sideA = aUser;
        sideB = bUser;
        Figure::material = mUser;
    }
    double getHigh() {
        return high;
    }
    double getA() {
        return sideA;
    }
    double getB() {
        return sideB;
    }
    double getSOsn() {
        return sideA * sideB;
    }
    double getSBok() {
        return 2 * high * (sideA + sideB);
    }
    double getSFull() {
        return 2 * (sideA * sideB) + (2 * high * (sideA + sideB));
    }
    double getP(string m) {
        if (m == "Метал")
            return (sideA * sideB * high) * 7.8;
        else if (m == "Дерево")
            return (sideA * sideB * high) * 0.69;
        else if (m == "Пластик")
            return (sideA * sideB * high) * 0.47;
        else if (m == "Картон")
            return (sideA * sideB * high) * 0.2;
    }
    double getV() {
        return sideA * sideB * high;
    }
};

class Cube : public Figure {
private:
    double side;
public:
    Cube(double s, string m) : Figure("Cube", m) {
        side = s;
    }
    void setInfo(double sUser, string mUser) {
        side = sUser;
        Figure::material = mUser;
    }
    double getSide() {
        return side;
    }
    double getSOsn() {
        return side * side;
    }

    double getSBok() {
        return 0;
    }

    double getSFull() {
        return 4 * (side * side);
    }
    double getP(string m) {
        if (m == "Метал")
            return (side * side * side) * 7.8;
        else if (m == "Дерево")
            return (side * side * side) * 0.69;
        else if (m == "Пластик")
            return (side * side * side) * 0.47;
        else if (m == "Картон")
            return (side * side * side) * 0.2;
    }
    double getV() {
        return side * side * side;
    }
};

class Piramida : public Figure {
private:
    double high, sideA;
public:
    Piramida(double h, double sA, string m) : Figure("Piramida", m) {
        high = h;
        sideA = sA;
    }
    void setInfo(double hUser, double aUser, string mUser) {
        high = hUser;
        sideA = aUser;
        Figure::material = mUser;
    }
    double getHigh() {
        return high;
    }
    double getSide() {
        return sideA;
    }
    double getSBok() {
        return (3 / 2) * sideA * high;
    }
    double getSOsn() {
        return (3 / 2) * sideA * high;
    }
    double getSFull() {
        return (sideA / 4) * ((sideA * sqrt(3)) + (6 * high));
    }
    double getP(string m) {
        if (m == "Метал")
            return ((sideA * sideA) / (4 * sqrt(3))) * 7.8;
        else if (m == "Дерево")
            return ((sideA * sideA) / (4 * sqrt(3))) * 0.69;
        else if (m == "Пластик")
            return ((sideA * sideA) / (4 * sqrt(3))) * 0.47;
        else if (m == "Картон")
            return ((sideA * sideA) / (4 * sqrt(3))) * 0.2;
    }
    double getV() {
        return (sideA * sideA) / (4 * sqrt(3));
    }
};

class Conus : public Figure {
private:
    double radius, high;
public:
    Conus(double r, double h, string m) : Figure("Conus", m) {
        radius = r;
        high = h;
    }
    void setInfo(double hUser, double rUser, string mUser) {
        high = hUser;
        radius = rUser;
        Figure::material = mUser;
    }
    double getRadius() {
        return radius;
    }
    double getHigh() {
        return high;
    }
    double getSOsn() {
        return 3.14 * radius * radius;
    }

    double getSBok() {
        return 3.14 * radius * sqrt((radius * radius) + (high * high));
    }

    double getSFull() {
        return (3.14 * radius * radius) + (3.14 * radius * sqrt((radius * radius) + (high * high)));
    }
    double getP(string m) {
        if (m == "Метал")
            return ((1 / 3) * 3.14 * radius * radius * high) * 7.8;
        else if (m == "Дерево")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.69;
        else if (m == "Пластик")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.47;
        else if (m == "Картон")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.2;
    }
    double getV() {
        return (1 / 3) * 3.14 * radius * radius * high;
    }
};

class Cylindr : public Figure {
private:
    double radius, high;
public:
    Cylindr(double r, double h, string m) : Figure("Cylindr", m) {
        radius = r;
        high = h;
    }
    void setInfo(double hUser, double rUser, string mUser) {
        high = hUser;
        radius = rUser;
        Figure::material = mUser;
    }
    double getRadius() {
        return radius;
    }
    double getHigh() {
        return high;
    }
    double getSOsn() {
        return 3.14 * radius * radius;
    }

    double getSBok() {
        return 3.14 * radius * sqrt((radius * radius) + (high * high));
    }

    double getSFull() {
        return (3.14 * radius * radius) + (3.14 * radius * sqrt((radius * radius) + (high * high)));
    }
    double getP(string m) {
        if (m == "Метал")
            return ((1 / 3) * 3.14 * radius * radius * high) * 7.8;
        else if (m == "Дерево")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.69;
        else if (m == "Пластик")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.47;
        else if (m == "Картон")
            return ((1 / 3) * 3.14 * radius * radius * high) * 0.2;
    }
    double getV() {
        return (1 / 3) * 3.14 * radius * radius * high;
    }
};

class PrismaInscribedRectilimealTriangular : public Figure
{
private:
    double high, side;
public:
    PrismaInscribedRectilimealTriangular(double h, double s) :Figure("PrismaInscribedRectilimealTriangular", "Metallic") {
        high = h;
        side = s;
    }
    double getSide() {
        return side;
    }
    double getHigh() {
        return high;
    }
    void setInfo(double hUser, double aUser, string mUser) {
        high = hUser;
        side = aUser;
        Figure::material = mUser;
    }
    double getSOsn() {
        return side * side * sqrt(3 / 4);
    }

    double getSBok() {
        return 3 * side * high;
    }

    double getSFull() {
        return 2 * (side * side * sqrt(3 / 4)) + (3 * side * high);
    }
    double getP(string m) {
        if (m == "Метал")
            return (side * side * high) * 7.8;
        else if (m == "Дерево")
            return (side * side * high) * 0.69;
        else if (m == "Пластик")
            return (side * side * high) * 0.47;
        else if (m == "Картон")
            return (side * side * high) * 0.2;
    }
    double getV() {
        return side * side * high;
    }
};