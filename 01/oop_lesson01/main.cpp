#include <iostream>
#include <iomanip>

using namespace std;

//***********************************************************************************
//struct Date{
//    int day;
//    int month;
//    int year;
//};

//void printDate(Date date){
//    cout << date.day << "." << date.month << "." << date.year << endl;
//}

//int main()
//{
//    Date today;
//    today.day = 27;
//    today.month = 8;
//    today.year = 2020;
//    printDate(today);

//    return 0;
//}

//*************************************************************************************
//class Date{
//private:

//public:
//    //члены класса:
//    int day;//поле
//    int month;//поле
//    int year;//поле
//    void printDate(){ //метод
//        cout << day << "." << month << "." << year << endl;
//    }
//};



//int main()
//{
//    Date today;//Объект или экземпляр класса (переменная today класса Date)
//    today.day = 27;//полям присвоили значения
//    today.month = 8;
//    today.year = 2020;
//    today.printDate();//вызвали метод вывода даты на экран

//    Date newYear;

//    return 0;
//}

//****************************************************************************************************

//Инкапсуляция (скрытие данных):

//class Date{
//    //члены класса:
//private:
//    int day;//поле
//    int month;//поле
//    int year;//поле
//public:
//    void printDate(){ //метод
//        cout << day << "." << month << "." << year << endl;
//    }
//    void setDate(int d, int m, int y){ //метод
//        day = d;
//        month = m;
//        year = y;
//    }
//};



//int main()
//{
//    Date today;//Объект или экземпляр класса (переменная today класса Date)
//    today.setDate(27, 8, 2020);
//    today.printDate();//вызвали метод вывода даты на экран


//    return 0;
//}

//****************************************************************************************

//class Date{
//    //члены класса:
//private:
//    int day;//поле
//    int month;//поле
//    int year;//поле
//public:
//    void printDate(){ //метод
//        cout << day << "." << month << "." << year << endl;
//    }
//создание сет методов (как изменить значение только одного поля?):

//        void setDate(int d, int m, int y){ //метод
//        day = d;
//        month = m;
//        year = y;
//    }
//    void setDay(int d){
//        day = d;
//    }
//    void setMonth(int m){
//        month = m;
//    }
//    void setYear(int y){
//        year = y;
//    }
//    //Получить возможность смотреть значения полей, методы гет возвращают значение полей:

//    int getDay(){
//        return  day;
//    }
//    int getMonth(){
//        return month;
//    }
//    int getYear(){
//        return year;
//    }
//};



//int main()
//{
//    Date today;//Объект или экземпляр класса (переменная today класса Date)
//    today.setDate(27, 8, 2020);
//    today.printDate();
//    cout << today.getYear() << endl;
//    today.setDay(28);
//    today.printDate();//вызвали метод вывода даты на экран

//    return 0;
//}

//***********************************************************************************************

//конструкторы. Это специальный тип метода, который автоматически будет вызываться при создании объекта этого класса.
//имя конструктора должно совпадать с именем класса. Они не имеют типа возврата.

//class Date{
//    //члены класса:
//private:
//    int day;//поле
//    int month;//поле
//    int year;//поле
//public:
//    Date(){//конструктор без параметров, по умолчанию. Конструкторы всегда в паблике.
//        day = 1;
//        month = 1;
//        year = 2000;
//    }
//    Date(int d, int m, int y){//конструктор с параметрами
//        day = d;
//        month = m;
//        year = y;
//    }
//    void printDate(){ //метод
//        cout << day << "." << month << "." << year << endl;
//    }
//создание сет методов (как изменить значение только одного поля?):

//        void setDate(int d, int m, int y){ //метод
//        day = d;
//        month = m;
//        year = y;
//    }
//    void setDay(int d){
//        day = d;
//    }
//    void setMonth(int m){
//        month = m;
//    }
//    void setYear(int y){
//        year = y;
//    }
//    //Получить возможность смотреть значения полей, методы гет возвращают значение полей:

//    int getDay(){
//        return  day;
//    }
//    int getMonth(){
//        return month;
//    }
//    int getYear(){
//        return year;
//    }
//};



//int main()
//{
//    Date today;//Объект или экземпляр класса (переменная today класса Date)
//    today.setDate(27, 8, 2020);
//    today.printDate();
//    cout << today.getYear() << endl;
//    today.setDay(28);
//    today.printDate();//вызвали метод вывода даты на экран

//    Date newYear;//при создании этого объекта вызывается конструктор поумолчанию
//    newYear.printDate();

//    Date vacation(1, 6, 2021);//при создании этого объекта вызывается конструктор с параметрами
//    vacation.printDate();
//    return 0;
//}

//*********************************************************************************

//конструктор не может присвоить значение параметру, если он константа.
//методы не могут присваивать значения константам, но, конструкторы могут это делать (один раз, при создании объекта).
//Чтобы конструктор мог присваивать порвоначальное значение константе нужно использовать список инициализации:

//class Date{
//    //члены класса:
//private:
//    int day;//поле
//    int month;//поле
//    const int year;//поле
//public:
//    Date() : year(2000) {
//        day = 1;
//        month = 1;
//    }
//};

//для нескольких констант:

//class Date{
//    //члены класса:
//private:
//    int day;//поле
//    int month;//поле
//    const int year;//поле
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    }

//    void printDate(){ //метод
//        cout << day << "." << month << "." << year << endl;
//    }
//};

//int main()
//{
//    Date newYear;//при создании этого объекта вызывается конструктор поумолчанию
//    newYear.printDate();
//    Date vacation(1, 6, 2021);//при создании этого объекта вызывается конструктор с параметрами
//    vacation.printDate();
//    return 0;
//}

//****************************************************************************************

//Деструкторы. - Этот метод автоматически вызывается при удалении объектов этого класса.
//он должен иметь тоже имя что и класс, со знаком "тильда" (~) в самом начале.
//не может принимать аргументы, у него всегда ноль параметров.
//не имеет типа возврата.
//Внутри одного класса создаётся тлько один диструктор.

class Date{
    //члены класса:
private:
    int day;//поле
    int month;//поле
    int year;//поле
public:
    Date() : day(1), month(1), year(2000) {//со списком инициализации.
    }
    // Для конструктора с параметрами:

    Date(int d, int m, int y) : day(d), month(m), year(y) {
    }

    void printDate(){ //метод
        cout << day << "." << month << "." << year << endl;
    }

    ~Date(){
        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
    }
};

int main()
{
    Date newYear;//при создании этого объекта вызывается конструктор поумолчанию
    newYear.printDate();
    Date vacation(1, 6, 2021);//при создании этого объекта вызывается конструктор с параметрами
    vacation.printDate();
    return 0;//Диструктор отработает после завершения функции main
}
