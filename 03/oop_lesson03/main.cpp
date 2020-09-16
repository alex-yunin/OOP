#include <iostream>
#include <iomanip>

using namespace std;

//class Parent{
//    protected:
//    int age;
//public:
//    Parent(int a) : age(a) {}
//    void getAge() const {cout << "Parent: " << age << endl;}
//};

//class Child : public Parent{
//public:
//    Child(int a) : Parent(a) {}
//    void getAge() const {cout << "Child: " << age << endl;}
//};

//int main()
//{
//Child child(20);
//child.getAge();

//Child *pChild = &child; //создадим указатель
//pChild->getAge(); //с помощью указателя вызываем метод getAge()

//Child &rChild = child; //создадим ссылку
//rChild.getAge(); //по ссылке вызываем метод getAge()

// //при создании объекта дочернего класса, всегда, сначала создаётся объект родительского класса Parent
// //как вызвать метод getAge() из родительского класса Parent?
// //при помощи оператора расширения области видимости:

//child.Parent::getAge();

// //также можно создавать указатель и ссылку базового класса:

//Parent *pbChild = &child; //upcast или повышающее преобразование (преобразовали объект дочернего класса к типу базового)
//pbChild->getAge();

//Parent &rbChild = child; //upcast
//rbChild.getAge();

// //если преобразовывать объект базоваго класса к типу дочернего класса, то это downcast.
// //когда мы преобразовали объект дочернего класса к типу базового, то функциональность дочернего класса отпадает, её теряем
// //Объект урезается.

//return 0;
//}

//********************************************************************************************************

//class Parent{
//    protected:
//    int age;
//public:
//    Parent(int a) : age(a) {}
//    void getAge() const {cout << "Parent: " << age << endl;}
//};

//class Child : public Parent{
//private:
//    string name = "child";
//public:
//    Child(int a) : Parent(a) {}
//    void getAge() const {cout << "Child: " << age << endl;}
//    void getName() const {cout << name << endl;}
//};

//int main()
//{
//Child child(20);
//child.getAge();
//child.getName();

//Parent *pChild = &child;
//pChild->getAge();
// //pbChild->getName(); //компилятор выдаст ошибку, так как в Parent нет метода getName()

//Parent &rChild = child;
//rChild.getAge();

// //как же вызвать через указатель: pChild и ссылку: rChild метод getName(), ведь объект был изначально дочернего типа?
// //для этого существуют виртуальные функции


//return 0;
//}

//**************************************************************************************************
//виртуальные функции

//class Parent{
//    protected:
//    int age;
//public:
//    Parent(int a) : age(a) {}
//    virtual void getAge() const {cout << "Parent: " << age << endl;} //делаем метод getAge() виртуальным
//    //когда вызываем виртуальную функцию, то будет вызываться самый дочерний метод.
//    //все методы getAge() в данной иерархии сановятся виртуальными, хоть и в дочерних классах не подписано: virtual, но
//    // методы должны совпадать в имени должны совпадать типы возвращаемых значений - void везде, должны совпадать списки
//    //параметров, в данном случаи они пустые (), и должны совпадать доп настройки (везде const)
//};

//class Child : public Parent{
//private:
//    string name = "child";
//public:
//    Child(int a) : Parent(a) {}
//    void getAge() const override {cout << "Child: " << age << endl;} //можно пометить дочерний метод как override
//    //тем самым подтверждая, что этот метод переопределяет метод базового класса и в этом случаи, если
//    //в параметрах этого метода мы допустили ошибку (есть отличия и этот метод не может переопределять базовый метод)
//    //компилятор выдаст ошибку. Это как страховка, что всё правильно. Сам параметр не является обязательным, если
//    //всё правильно, то компилятор сам "поймёт" что данный метор переопределяет базовый.
//    void getName() const {cout << name << endl;}
//};

//int main()
//{
//Child child(20);
//child.getAge();
//child.getName();

//Parent *pChild = &child;
//pChild->getAge();
// //pbChild->getName(); //этот метод, попрежнему, вызвать не сможем
// //для этих, обрезанных (upcast) объектов мы можем вызывать только виртуальные методы и
// //они будут выхваны из самого дочернего класса.
// //другие методы, которые не являются виртуальными не буду доступны вообще для такого, обрезанного, объекта.

//Parent &rChild = child;
//rChild.getAge();



//return 0;
//}

//*************************************************************************************************
//сейчас виртуальный метод getAge() вызывается из дочернего класса.
//как вызывать метод getAge() при помощи указателя или ссылки из базового класса?

//class Parent{
//    protected:
//    int age;
//public:
//    Parent(int a) : age(a) {}
//    virtual void getAge() const {cout << "Parent: " << age << endl;}
//};

//class Child : public Parent{
//private:
//    string name = "child";
//public:
//    Child(int a) : Parent(a) {}
//    void getAge() const override {cout << "Child: " << age << endl;}
//    void getName() const {cout << name << endl;}
//};

//void Print(Parent* p){
//    p->getAge();
//}

//int main()
//{
//Child child(20);
//child.getAge();

//Parent *pChild = &child;
//pChild->Parent::getAge(); //с помощью оператора рашрирения области видимости


//Parent &rChild = child;
//rChild.getAge();

//Parent parent(40);
//Print(&child);
//Print(&parent);


//return 0;
//}

//***************************************************************************************************
//виртуальные диструкторы

//class Parent{
//    protected:
//    int age;
//public:
//    Parent(int a) : age(a) {}
//    virtual ~Parent(){}
//    virtual void getAge() const {cout << "Parent: " << age << endl;}
//};

//class Child : public Parent{
//private:
//    string name = "child";
//public:
//    Child(int a) : Parent(a) {}
//    ~Child() override {}
//    void getAge() const override {cout << "Child: " << age << endl;}
//    void getName() const {cout << name << endl;}
//};

//void Print(Parent* p){
//    p->getAge();
//}

//int main()
//{
//Parent *child = new Child(20);

//delete child;//в данном случаи, если диструктор не будет виртуальным, то данная операция не работает


//return 0;
//}

//********************************************************************************************************
//Абстрактные классы
//Чисто виртуальные функции

//class Animal{ //абстрактный класс
//public:
//    virtual void say() = 0;//чисто виртуальная функция абстрактного класса
//    //Объект абстрактного класса мы создать не можем, но указатель типа абстрактного класса мы создать можем
//    //и ссылку абтрактного типа создать можно
//};

//class Cat : public Animal{//Этот класс реализует чисто виртуальную функцию абстрактного класса
//public:
//    void say() override{
//        cout << "Meow" << endl;
//    }
//};

//class Dog : public Animal{
//public:
//    void say() override{
//        cout << "Woof" << endl;
//    }
//};

//void Say(Animal* animal){//функция принимает указатель типа Animal
//    animal->say();//вызывает метот из класса
//}

//int main()
//{
// //Animal a;//невозможно создать переменную абстрактного типа.
//Animal* cat = new Cat();
//Animal* dog = new Dog();
//Cat* cat2 = new Cat();//можно и так
//Say(cat);
//Say(dog);
//Say(cat2);
//return 0;
//}

//*****************************************************************************************************
//Интерфейсный класс
//у него нет переменных-членов (полей), все функции чисто виртуальные
//именование таких классов начинается с большой буквы "I"

//******************************************************************************************************
//Виртуальный базовый класс

//******************************************************************************************************
//Перегрузка операторов
//Операторы: унарные (&, |, ~, !), бинарные (+, -, >, &&), тернарный (?:)

//class Dollars{
//private:
//    int m_dollars;
//public:
//    Dollars(int dollar) : m_dollars(dollar){}
//    int getDollars() const { return m_dollars; }
//    friend Dollars operator+ (const Dollars &d1, const Dollars &d2);//дружественная функция
//    //дружественная функция имеет доступ к приватным полям класса
//};

//Dollars operator+ (const Dollars &d1, const Dollars &d2){//реализация дружественной функции
//    return Dollars(d1.m_dollars + d2.m_dollars);
//}

//int main()
//{
//Dollars dollar1(7);
//Dollars dollar2(9);
//Dollars dollar3 = dollar1 + dollar2;//В таком виде не получится, компилятор не знае как складывать эти объекты
// //нужно перегрузить оператор, сделаем это через дружественную функцию
//cout << dollar3.getDollars() << endl;

//return 0;
//}

//*******************************************************************************************************
//перегрузка оператора через обычную функцию

class Dollars{
private:
    int m_dollars;
public:
    Dollars(int dollar) : m_dollars(dollar){}
    int getDollars() const { return m_dollars; }
};

Dollars operator+ (const Dollars &d1, const Dollars &d2){//обычная функция не имеет доступ к приватным полям
    //используем getметод
    return Dollars(d1.getDollars() + d2.getDollars());
}

int main()
{
Dollars dollar1(7);
Dollars dollar2(9);
Dollars dollar3 = dollar1 + dollar2;//В таком виде не получится, компилятор не знае как складывать эти объекты
 //нужно перегрузить оператор, сделаем это через обычную функцию
cout << dollar3.getDollars() << endl;

return 0;
}
