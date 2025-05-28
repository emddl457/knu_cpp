#include <iostream>
using namespace std;

// 추상 클래스 Comparable
class Comparable {
public:
    virtual bool operator>(Comparable& op2) = 0;
    virtual bool operator<(Comparable& op2) = 0;
    virtual bool operator==(Comparable& op2) = 0;
};

// Circle 클래스는 Comparable을 상속
class Circle : public Comparable {
    int radius;
public:
    Circle(int radius = 1) { this->radius = radius; }
    int getRadius() const { return radius; }

    // 비교 연산자 구현
    bool operator>(Comparable& op2) override {
        Circle& c = dynamic_cast<Circle&>(op2);
        return this->radius > c.radius;
    }

    bool operator<(Comparable& op2) override {
        Circle& c = dynamic_cast<Circle&>(op2);
        return this->radius < c.radius;
    }

    bool operator==(Comparable& op2) override {
        Circle& c = dynamic_cast<Circle&>(op2);
        return this->radius == c.radius;
    }
};

// 일반 타입용 bigger 함수
template <typename T>
T bigger_value(T a, T b) {
    return (a > b) ? a : b;
}

// Comparable 포인터용 bigger 함수
template <typename T>
T bigger_ptr(T a, T b) {
    return (*a > *b) ? a : b;
}

int main() {
    // 일반 타입 비교
    int a = 20, b = 50;
    int c = bigger_value(a, b);
    cout << "20과 50 중 큰 값은 " << c << endl;

    // Circle 비교
    Circle* waffle = new Circle(10);
    Circle* pizza = new Circle(20);
    Circle* y = bigger_ptr(waffle, pizza);
    cout << "waffle과 pizza 중 큰 것의 반지름은 " << y->getRadius() << endl;

    delete waffle;
    delete pizza;

    return 0;
}
