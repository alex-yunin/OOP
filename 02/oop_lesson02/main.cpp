#include <iostream>
#include <iomanip>

using namespace std;

//*********************************************************************************

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    }

//    void setDate(int d, int m, int y){
//    day = d;
//    month = m;
//    year = y;
//    }
//    void setDay(int d) {
//        day = d;
//    }
//    void setMonth(int m){
//        month = m;
//    }
//    void setYear(int y){
//        year = y;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
//    }
//};

//int main()
//{
//    const Date today(31,8,2020);
//    //    today.setDay(1);
//    today.printDate();
//    today.getDay();

//************************************************************************************************
// определение метода вне класса

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    }

//    void setDate(int d, int m, int y);
//    void setDay(int d) {
//        day = d;
//    }
//    void setMonth(int m){
//        month = m;
//    }
//    void setYear(int y){
//        year = y;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
//    }
//};

//void Date::setDate(int d, int m, int y){
//day = d;
//month = m;
//year = y;
//}

//  //void NewDate::setDate(int d, int m, int y){//реализация этого метода в другом классе
//  //day = d;
//  //month = m;
//  //year = y;
//  //}

//int main()
//{
//    const Date today(31,8,2020);
//  //    today.setDay(1);
//    today.printDate();

    //***********************************************************************************************
// скрытый указатель this

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    }

//    void setDate(int d, int m, int y);
//    void setDay(int day) {//void setDay(Date* Const this, int d) { - скрытый указатель this (так представляет метод компилятор)
// //      day = d;
//        this->day = day;// так можно испльзовать указатель, просто day = day - не работает в данном случае
//    }
//    Date& setMonth(int m){
//        month = m;
//        return *this;
//    }
//    Date& setYear(int y){
//        year = y;
//        return *this;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
//    }
//};

//void Date::setDate(int d, int m, int y){
//day = d;
//month = m;
//year = y;
//}

// //void NewDate::setDate(int d, int m, int y){//реализация этого метода в другом классе
// //day = d;
// //month = m;
// //year = y;
// //}

//int main()
//{
//    Date today(31,8,2020);
//    today.setDay(1);// setDay(&today, 1); - компилятор так вызывает метод (указатель, значение присваиваемое)
//    today.setMonth(9).setYear(2021);// чтобы так в цепочку написать вызов сет-методов,
//    //они должны возвращать сам объект: return *this; и void меняем на Date&
//    today.printDate();

//*********************************************************************************************************
//статическая переменная

//int x = 0;//глобальная переменная

//void func(){
// //    int x = 0;// если записать так, то 3 раза вызвав функцию: func(); мы получим три еденицы (1  1  1)
//    static int x = 0;// а так, получим: 1  2  3    (эта строчка работает только при первом вызове функции func() )
//    x++;
// //    (::x)++;//Пишем так, если мы хотим обратиться из функции к глобальной преременной x, но,
// //   глобальная переменная должна быть объявлена выше функции func(), тогда получится
//    cout << x << endl;
//}



//int main()
//{
//func();// статическая переменна не удаляется после вызова функции, она сохраняется и удалится тлько по завершению main
//func();
//func();
//cout << x << endl;// видно, что меняется статическая переменная, в функции func(), а глобальная не изменилась

//***********************************************************************************************************************
//Статические поля (в public)

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    n++;
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    n++;
//    }

//    void setDate(int d, int m, int y);
//    void setDay(int day) {//void setDay(Date* Const this, int d) { - скрытый указатель this (так представляет метод компилятор)
// //      day = d;
//        this->day = day;// так можно испльзовать указатель, просто day = day - не работает в данном случае
//    }
//    Date& setMonth(int m){
//        month = m;
//        return *this;
//    }
//    Date& setYear(int y){
//        year = y;
//        return *this;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
//        n--;
//    }
//    static int n;
//};

//void Date::setDate(int d, int m, int y){
//day = d;
//month = m;
//year = y;
//}

//int Date::n = 0;


//int main()
//{
//cout << Date::n << endl;
//Date date1;
//cout << date1.n << endl;//не важно как мы её вызываем Date::n, date1.n, date2.n - так как она общая для всего класса
//Date date2;
//Date::n = 1000;// ей можно присвоить значение так как она находится в pablic, её нужно помещать в private
//cout << date2.n << endl;

//******************************************************************************************************

//Статические поля (в private)

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//    static int n;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    n++;
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    n++;
//    }

//    void setDate(int d, int m, int y);
//    void setDay(int day) {//void setDay(Date* Const this, int d) { - скрытый указатель this (так представляет метод компилятор)
// //      day = d;
//        this->day = day;// так можно испльзовать указатель, просто day = day - не работает в данном случае
//    }
//    Date& setMonth(int m){
//        month = m;
//        return *this;
//    }
//    Date& setYear(int y){
//        year = y;
//        return *this;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "Date was Deleted" << endl;//Добавили строчку, чтобы видеть когда работал диструктор.
//        n--;
//    }
//    static int getNumber(){
//        return n;
//    }
//};

//void Date::setDate(int d, int m, int y){
//day = d;
//month = m;
//year = y;
//}

//int Date::n = 0;


//int main()
//{
//cout << Date::getNumber() << endl;
//Date date1;
//cout << date1.getNumber() << endl;//не важно как мы её вызываем Date::n, date1.n, date2.n - так как она общая для всего класса
//Date date2;
//cout << date2.getNumber() << endl;

//*************************************************************************************************************************

//class Time{
//private:
//    int m, h;
//public:
//    Time(){
//        cout << "ctor Time" << endl;
//    }
//    ~Time(){
//        cout << "Dtor Time" << endl;
//    }
//};

//class Date{
//private:
//    int day;
//    int month;
//    int year;
//    Time time;//внутри класса Date создадим поле типа Time
//    static int n;
//public:
//    Date() : day(1), month(1), year(2000) {//со списком инициализации.
//    cout << "ctor Date" << endl;
//    n++;
//    }
//    // Для конструктора с параметрами:

//    Date(int d, int m, int y) : day(d), month(m), year(y) {
//    cout << "ctor Date" << endl;
//    n++;
//    }

//    void setDate(int d, int m, int y);
//    void setDay(int day) {//void setDay(Date* Const this, int d) { - скрытый указатель this (так представляет метод компилятор)
// //      day = d;
//        this->day = day;// так можно испльзовать указатель, просто day = day - не работает в данном случае
//    }
//    Date& setMonth(int m){
//        month = m;
//        return *this;
//    }
//    Date& setYear(int y){
//        year = y;
//        return *this;
//    }
//    int getDay() const {
//        return day;
//    }
//    int getMonth() const {
//        return month;
//    }
//    int getYear() const {
//        return year;
//    }

//    void printDate() const { //метод
//        cout << day << "." << month << "." << year << endl;
//    }

//    ~Date(){
//        cout << "dtor Date" << endl;
//        n--;
//    }
//    static int getNumber(){
//        return n;
//    }
//};

//void Date::setDate(int d, int m, int y){
//day = d;
//month = m;
//year = y;
//}

//int Date::n = 0;


//int main()
//{

//Date date1;

//********************************************************************************************
//Наследование

//class Human{
//    protected://эти члены доступны не только внутри класса, но и в классе-наследнике
//    string name;
//    int age;
//public:
//    Human(string n, int a) : name(n), age(a) {

//    }
//    string getName() const {
//        return name;
//    }
//    int getAge() const {
//        return age;
//    }
//};
//class Employee : public Human{// пишем public, а значит все публичные методы наследуются как публичные
// //    (будут также публичными в дочернем классе)
//private:
//    int wage;
//public:
//    Employee(string n, int a, int w) : Human(n, a), wage(w) {

//    }
//    int getWage() const {
//        return wage;
//    }
//    void print(){
//        cout << name << " " << age << " " << wage << endl;
//    }
//};

//int main()
//{

//Employee worker("Ivan", 30, 50000);
//worker.print();

//****************************************************************************************************
//дружественные функции

class Cat{
private:
    int age;
public:
    Cat(int a){
        age = a;
    }
    void print() const {
        cout << age << endl;
    }
    friend void resetAge(Cat &cat);
};
void resetAge(Cat& cat){
    cat.age = 0;
}

int main()
{

Cat cat(5);
resetAge(cat);
cat.print();

return 0;
}
