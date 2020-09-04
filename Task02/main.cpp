//Курс: "Объектно-ориентированное программирование".
//Студент: Александр Юнин
//Выполнение Практического задания к уроку 2.

#include <iostream>

using namespace std;

//Код_1.1 для задачи 1 ************************************************** Код_1.1 для задачи 1

class Person{
    protected:
    string name;
    int age;
    string gender;
    int weight;
public:
    Person(string n, int a, string g, int w) : name(n), age(a), gender(g), weight(w) {
    }
    void setName(string n){
        name = n;
    }
    void setAge(int a){
        age = a;
    }
    void setWeight(int w){
        weight = w;
    }
    void printPerson() const {
        cout << name << " " << age << " лет, пол: " << gender << ", вес: " << weight << " кг" << endl;
    }
    ~Person(){

    }
};

class Student : public Person{
private:
    int year;
    static int x;
public:
    Student(string n, int a, string g, int w, int y) : Person(n, a, g, w), year(y) {
    x++;
    }
    void setYear(int y){
        year = y;
    }
    void upYear(){
        year++;
    }
    void printYear() const {
        cout << "год обучения: " << year << endl;
    }
    static int getNumber(){
        return x;
    }
};
int Student::x = 0;

//Конец кода_1.1 для задачи 1 ******************************************* Конец кода_1.1 для задачи 1

//Код_2.1 для задачи 2 ************************************************** Код_2.1 для задачи 2

class Fruit{
private:
    string name;
    string color;
public:
    Fruit(string n, string c) : name(n), color(c) {
    }
    string getName() const {
        return name;
    }
    string getColor() const {
        return color;
    }
    void setRename(string n){
        name = n;
    }
};

class Apple : public Fruit{
public:
    Apple(string c) : Fruit("apple", c) {
    }
};

class Banana : public Fruit{
public:
    Banana() : Fruit("banana", "yellow") {
    }
};
class GrannySmith : public Apple{
public:
    GrannySmith() : Apple("green") {
        setRename("Granny Smith apple");
    }
};

//Конец кода_2.1 для задачи 2 ******************************************* Конец кода_2.1 для задачи 2

int main()
{

//Код_1.2 для задачи 1 ************************************************** Код_1.2 для задачи 1

    Student student1("Ivan", 19, "man", 75, 2020);
    Student student2("Olya", 18, "woman", 54, 2020);
    Student student3("Kolya", 20, "men", 80, 2020);
    cout << "Всего студентов: " << Student::getNumber() << endl;
    student2.upYear();
    student2.setAge(25);
    student2.printPerson();
    student2.printYear();

//Конец кода_1.2 для задачи 1 ******************************************* Конец кода_1.2 для задачи 1

//Код_2.2 для задачи 2 ************************************************** Код_2.2 для задачи 2

    Apple a("red");
    Banana b;
    GrannySmith c;

    std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
    std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
    std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

//Конец кода_2.2 для задачи 2 ******************************************* Конец кода_2.2 для задачи 2

    return 0;
}
