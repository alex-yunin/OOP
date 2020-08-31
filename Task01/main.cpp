//Курс: "Объектно-ориентированное программирование".
//Студент: Александр Юнин
//Выполнение Практического задания к первому уроку.


#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdint>

using namespace std;

//Код_1.1 для задачи 1 ************************************************** Код_1.1 для задачи 1

class Power{
private:
    double Power1;
    double Power2;
public:
    Power() : Power1(1), Power2(1){
cout << "работает конструктор" << endl;
    }
void setPower(){
    double p1;
    double p2;
    cout << "Введите два вещественных числа:\n" << endl;
    scanf("%lf\n", &p1);
    scanf("%lf", &p2);
    while ((((p1 < 0) & ((-1) < p2)) & ((p1 < 0) & (p2 < 1))) | ((p1 == 0) & (p2 < 0))){
        cout << "Эти числа не подходят, повторите ввод:\n" << endl;
        scanf("%lf\n", &p1);
        scanf("%lf", &p2);
    }
        Power1 = p1;
        Power2 = p2;
    }
    void setPower1(double p1){
        Power1 = p1;
    }
    void setPower2(double p2){
        Power2 = p2;
    }
    void calculate(){
    cout << "Результать возведения числа " << Power1 << " в степень " << Power2 << "\nравен: "
         << pow(Power1, Power2) << endl;
    }
    ~Power(){
        cout << "работает диструктор" << endl;
    }
};

//Конец кода_1.1 для задачи 1 ******************************************* Конец кода_1.1 для задачи 1

//Код_2.1 для задачи 2 ************************************************** Код_2.1 для задачи 2

class RGBA{
private:
    std::uint8_t m_red = 0;
    std::uint8_t m_green = 0;
    std::uint8_t m_blue = 0;
    std::uint8_t m_alpha = 255;
public:
    RGBA(std::uint8_t r, std::uint8_t g, std::uint8_t b, std::uint8_t a) : m_red(r), m_green(g), m_blue(b), m_alpha(a) {
    cout << "Работает конструктор" << endl;
    }
    void getPrint(){
        cout << m_red << ", " <<m_green << ", " << m_blue << ", " << m_alpha << endl;
    }
    ~RGBA(){
    cout << "Работает деструктор" << endl;
    }
};

//Конец кода_2.1 для задачи 2 ******************************************* Конец кода_2.1 для задачи 2

//Код_3.1 для задачи 3 ************************************************** Код_3.1 для задачи 3

class Stack{
private:
    int S = 10;
    int stack[10];
public:
    Stack(){
        cout << "Работает конструктор" << endl;
    }
    void reset(){
        int i;
        for(i = 0; i < S; i++){
            stack[i] = 0;
        }
         S = 0;
//         stack[S] = stack[S];
    }
    void push(int a){
        if(S == 10){
            cout << "false" << endl;
        } else {
            int i = 0;
            while(i < S) {
                i++;
            }
//            stack[S] = stack[s+1];
            S = S + 1;
            stack[i] = a;
        }
    }
    void pop(){
//        int k = S;
        if(S == 0){
            cout << "stack пуст!" << endl;
        } else {
            stack[S] = 0;
            S = S - 1;
        }
    }
    void print(){
        int i;
//        cout << " " << endl;
        for(i = 0; i < S; i++){
            printf(" %d ", stack[i]);
        }
        printf("\n");
    }
    ~Stack(){
        cout << "Работает деструктор" << endl;
    }
};

//Конец кода_3.1 для задачи 3 ******************************************* Конец кода_3.1 для задачи 3

int main()
{

//Код_1.2 для задачи 1 ************************************************** Код_1.2 для задачи 1

    Power newPower;
    newPower.setPower();
    newPower.calculate();

//Конец кода_1.2 для задачи 1 ******************************************* Конец кода_1.2 для задачи 1

//Код_2.2 для задачи 2 ************************************************** Код_2.2 для задачи 2

    RGBA newRGBA(68, 2, 3, 254);
    newRGBA.getPrint();

//Конец кода_2.2 для задачи 2 ******************************************* Конец кода_2.2 для задачи 2

//Код_3.2 для задачи 3 ************************************************** Код_3.2 для задачи 3

    Stack stack;
    stack.reset();
    stack.print();

    stack.push(3);
    stack.push(7);
    stack.push(5);
    stack.print();

    stack.pop();
    stack.print();

    stack.pop();
    stack.pop();
    stack.print();

//Конец кода_3.2 для задачи 3 ******************************************* Конец кода_3.2 для задачи 3

    return 0;
}
