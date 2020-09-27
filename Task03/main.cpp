//Курс: "Объектно-ориентированное программирование".
//Студент: Александр Юнин
//Выполнение Практического задания к уроку 3.

#include <iostream>
#include <iomanip>

using namespace std;
//Код_1.1 для задачи 1 ************************************************** Код_1.1 для задачи 1

class Figure{
public:
    Figure() {}
    virtual void area() = 0;
};

class Parallelogram : public Figure{
protected:
    int AB;
    int BC;
    int AH;
public:
    Parallelogram(int a, int b, int h) : AB(a), BC(b), AH(h) {}
    void area() override{
        int Ar;
        Ar = BC * AH;
        cout << "Area Parallelogram " << Ar << endl;
    };

};

class Circle : public Figure{
private:
    int R;
public:
    Circle(int r) : R(r){}
    void area() override{
        int Ar;
        Ar = 3.14 * R *R;
        cout << "Area Circle " << Ar << endl;
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(int a, int b) : Parallelogram(a, b, a){}
    void area() override{
        int Ar;
        Ar = AB * BC;
        cout << "Area Rectangle " << Ar << endl;
    }
};

class Square : public Parallelogram{
public:
    Square(int a) : Parallelogram(a, a, a){}
    void area() override{
        int Ar;
        Ar = AB * AB;
        cout << "Area Square " << Ar << endl;
    }
};

class Rhombus : public Parallelogram{
public:
    Rhombus(int a, int h) : Parallelogram(a, a, h){}
    void area() override{
        int Ar;
        Ar = AB * AH;
        cout << "Area Rhombus " << Ar << endl;
    }
};

void Area(Figure* figure){
    figure->area();
}

//Конец кода_1.1 для задачи 1 ******************************************* Конец кода_1.1 для задачи 1

//Код_2.1 для задачи 2 ************************************************** Код_2.1 для задачи 2

class Car{
protected:
    string company;
    string model;
public:
    Car(string c, string m) : company(c), model(m){
        cout << "Car " << company << " " << model << endl;
    }
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(string c, string m) : Car(c, m){
        cout << "PassengerCar " << company << " " << model << endl;
    }
};

class Bus : virtual public Car{
public:
    Bus(string c, string m) : Car(c, m){
        cout << "Bus " << company << " " << model << endl;
    }
};

class Minivan : public PassengerCar, public Bus{
public:
    Minivan(string c, string m) : Car(c, m), PassengerCar(c, m), Bus(c, m){
        cout << "Minivan " << company << " " << model << endl;
    }
};

//Конец кода_2.1 для задачи 2 ******************************************* Конец кода_2.1 для задачи 2

//Код_3.1 для задачи 3 ************************************************** Код_3.1 для задачи 3

class Fraction{
private:
    int up;
    int down;
public:
    Fraction(int u, int d) {
        if(d == 0) {
            cout << "Знаменатель дроби не должен быть равен нулю!" << endl;
            up = 1;
            down = 1;
        } else {
            up = u;
            down = d;
        }
    }
int getUp() const {
    return up;
    }
int getDown() const {
    return down;
}
void getPrint() const {
    cout << up << "/" << down << endl;
    }
    ~Fraction(){}
};

Fraction operator+ (const Fraction &fr1, const Fraction &fr2) {
    int u, d;
    int u1 = fr1.getUp();
    int d1 = fr1.getDown();
    int u2 = fr2.getUp();
    int d2 = fr2.getDown();

    if(d1 == d2){
        d = d1;
        u = u1 + u2;
        return Fraction(u, d);
    } else {
        d = d1 * d2;
        u = (u1 * d2) + (u2 * d1);
        return Fraction(u, d);
    }
}

//Аналогично перегружаются остальные операторы

//Конец кода_3.1 для задачи 3 ******************************************* Конец кода_3.1 для задачи 3

//Код_4.1 для задачи 4 ************************************************** Код_4.1 для задачи 4

class Card{
private:
    enum Mast{ C2, C3, C4, C5, C6, C7, C8, C9, C10, CJ, CQ, CK, CA };
    enum Value{ v1 = 1, v2, v3, v4, v5, v6, v7, v8, v9, v10 };
    bool m_flip;
    Mast m_mast;
    Value m_value;
public:
    Card() : m_flip(0) {}
    void Flip(){
        if(m_flip == 0)
            m_flip = 1;
        else
            m_flip = 0;
    }
    int getValue(){ return m_value; }
};



//Конец кода_4.1 для задачи 4 ******************************************* Конец кода_4.1 для задачи 4


int main()
{
//Код_1.2 для задачи 1 ************************************************** Код_1.2 для задачи 1

Figure* parallelogram = new Parallelogram(4, 5, 3);
Figure* circle = new Circle(10);
Figure* rectangle = new Rectangle(2, 5);
Figure* square = new Square(6);
Figure* rhombus = new Rhombus(6, 4);
Area(parallelogram);
Area(circle);
Area(rectangle);
Area(square);
Area(rhombus);

//Конец кода_1.2 для задачи 1 ******************************************* Конец кода_1.2 для задачи 1

//Код_2.2 для задачи 2 ************************************************** Код_2.2 для задачи 2

Car car("ГАЗ", "Ока");
PassengerCar passengerCar("ГАЗ", "Волга");
Bus bus("ГАЗ", "ПАЗ");
Minivan minivan("Toyota", "Estima");

//Конец кода_2.2 для задачи 2 ******************************************* Конец кода_2.2 для задачи 2

//Код_3.2 для задачи 3 ************************************************** Код_3.2 для задачи 3

Fraction fr1(1, 3);
Fraction fr2(2, 5);
fr1.getPrint();
fr2.getPrint();
Fraction fr3 = fr1 + fr2;
fr3.getPrint();

//Конец кода_3.2 для задачи 3 ******************************************* Конец кода_3.2 для задачи 3

return 0;
}
