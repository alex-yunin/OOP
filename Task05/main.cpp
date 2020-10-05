//Курс: "Объектно-ориентированное программирование".
//Студент: Александр Юнин
//Выполнение Практического задания к уроку 5.

#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

//Код_1.1 для задачи 1 ************************************************** Код_1.1 для задачи 1

template <class T>
class Pair1{
private:
    T m_first;
    T m_second;
public:
    Pair1(T f, T s) : m_first(f), m_second(s) {}
    ~Pair1(){}
    T first() const { return m_first; }
    T second() const { return m_second; }
};

//Конец кода_1.1 для задачи 1 ******************************************* Конец кода_1.1 для задачи 1

//Код_2.1 для задачи 2 ************************************************** Код_2.1 для задачи 2

template <class T, class U>
class Pair{
protected:
    T m_first;
    U m_second;
public:
    Pair(T f, U s) : m_first(f), m_second(s) {}
    ~Pair(){}
    T first() const { return m_first; }
    U second() const { return m_second; }
};

//Конец кода_2.1 для задачи 2 ******************************************* Конец кода_2.1 для задачи 2

//Код_3.1 для задачи 3 ************************************************** Код_3.1 для задачи 3

template <class U>
class Pair<string, U>{
protected:
    string m_first;
    U m_second;
public:
    Pair(string f, U s) : m_first(f), m_second(s){}
    ~Pair(){}
    string first() const { return m_first; }
    U second() const { return m_second; }
};
template <class K>
class StringValuePair : public Pair<string, K>{
public:
    StringValuePair(string f, K s) : Pair<string, K>(f, s) {}
};

//Конец кода_3.1 для задачи 3 ******************************************* Конец кода_3.1 для задачи 3

//Код_4.1 для задачи 4 ************************************************** Код_4.1 для задачи 4

//класс кард******************************************
class Card{
public:
    enum rank { ACE = 1, TWO, THREE, FOUR, FIVE, SIX, SEVEN, EIGHT, NINE, TEN, JACK, QUEEN, KING };
    enum suit { CLUBS, DIAMONDS, HEARTS, SPADES };

    Card(rank r = ACE, suit s = SPADES, bool ifu = true);
    int GetValue() const;
    void Flip();

private:
    rank m_Rank;
    suit m_Suit;
    bool m_IsFaceUp;
};

Card::Card(rank r, suit s, bool ifu) : m_Rank(r), m_Suit(s), m_IsFaceUp(ifu){}

int Card::GetValue() const {
    int value = 0;
    if (m_IsFaceUp){
        value = m_Rank;
        if (value > 10){
            value = 10;
        }
    }
    return value;
}

void Card::Flip(){
    m_IsFaceUp = !(m_IsFaceUp);
}
//клас кард********************************************* конец

//класс хенд********************************************
class Hand{
public:
    Hand();
    // виртуальный деструктор
    virtual ~Hand();

    // добавляет карту в руку
    void Add(Card* pCard);

    // очищает руку от карт
    void Clear();

    //получает сумму очков карт в руке, присваивая тузу значение 1 или 11 в зависимости от ситуации
    int GetTotal() const;

protected:
    vector<Card*> m_Cards;
};

Hand::Hand(){
    m_Cards.reserve(7);
}
// деструктор по-прежнему виртуальный
// это уже можно не обозначать
Hand::~Hand(){
    Clear();
}

void Hand::Add(Card* pCard){
    m_Cards.push_back(pCard);
}

void Hand::Clear(){
    // проходит по вектору, освобождая всю память в куче
    vector<Card*>::iterator iter = m_Cards.begin();
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
        delete *iter;
        *iter = 0;
    }
    // очищает вектор указателей
    m_Cards.clear();
}

int Hand::GetTotal() const{
    // если карт в руке нет, возвращает значение 0
    if (m_Cards.empty()){
        return 0;
    }

    //если первая карта имеет значение 0, то она лежит рубашкой вверх:
    // вернуть значение 0
    if (m_Cards[0]->GetValue() == 0){
        return 0;
    }

    // находит сумму очков всех карт, каждый туз дает 1 очко
    int total = 0;
    vector<Card*>::const_iterator iter;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
        total += (*iter)->GetValue();
    }

    // определяет, держит ли рука туз
    bool containsAce = false;
    for (iter = m_Cards.begin(); iter != m_Cards.end(); ++iter){
        if ((*iter)->GetValue() == Card::ACE){
            containsAce = true;
        }
    }

    // если рука держит туз и сумма довольно маленькая, туз дает 11 очков
    if (containsAce && total <= 11){
        // добавляем только 10 очков, поскольку мы уже добавили за каждый туз по одному очку
        total += 10;
    }

    return total;
}
//класс хенд ***************************************** конец

//класс ЖенерикПлеер**********************************
class GenericPlayer : public Hand{
protected:
    string name;
public:
    GenericPlayer(){};
    virtual ~GenericPlayer(){};
    virtual void IsHitting();
    bool IsBoosted();
    void Bust();
};

bool GenericPlayer::IsBoosted(){
    if(GetTotal() > 21)
        return true;
    return false;
}
void GenericPlayer::Bust(){
    if(IsBoosted() == true)
        cout << name << "Boosted" << endl;
    return;
}
//класс ЖенерикПлеер********************************** конец


//Конец кода_4.1 для задачи 4 ******************************************* Конец кода_4.1 для задачи 4


int main()
{
//Код_1.2 для задачи 1 ************************************************** Код_1.2 для задачи 1

    Pair1<int> p1(6, 9);
    cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

    const Pair1<double> p2(3.4, 7.8);
    cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

//Конец кода_1.2 для задачи 1 ******************************************* Конец кода_1.2 для задачи 1

//Код_2.2 для задачи 2 ************************************************** Код_2.2 для задачи 2

    Pair<int, double> pr1(6, 7.8);
    cout << "Pair: " << pr1.first() << ' ' << pr1.second() << '\n';

    const Pair<double, int> pr2(3.4, 5);
    cout << "Pair: " << pr2.first() << ' ' << pr2.second() << '\n';

//Конец кода_2.2 для задачи 2 ******************************************* Конец кода_2.2 для задачи 2

//Код_3.2 для задачи 3 ************************************************** Код_3.2 для задачи 3

    StringValuePair<int> svp("Amazing", 7);
    std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

//Конец кода_3.2 для задачи 3 ******************************************* Конец кода_3.2 для задачи 3

//Код_4.2 для задачи 4 ************************************************** Код_4.2 для задачи 4


//Конец кода_4.2 для задачи 4 ******************************************* Конец кода_4.2 для задачи 4

    return 0;
}
