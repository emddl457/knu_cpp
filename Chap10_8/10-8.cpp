#include <iostream>
using namespace std;

// �߻� Ŭ���� Comparable
class Comparable {
public:
    virtual bool operator>(Comparable& op2) = 0;
    virtual bool operator<(Comparable& op2) = 0;
    virtual bool operator==(Comparable& op2) = 0;
};

// Circle Ŭ������ Comparable�� ���
class Circle : public Comparable {
    int radius;
public:
    Circle(int radius = 1) { this->radius = radius; }
    int getRadius() const { return radius; }

    // �� ������ ����
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

// �Ϲ� Ÿ�Կ� bigger �Լ�
template <typename T>
T bigger_value(T a, T b) {
    return (a > b) ? a : b;
}

// Comparable �����Ϳ� bigger �Լ�
template <typename T>
T bigger_ptr(T a, T b) {
    return (*a > *b) ? a : b;
}

int main() {
    // �Ϲ� Ÿ�� ��
    int a = 20, b = 50;
    int c = bigger_value(a, b);
    cout << "20�� 50 �� ū ���� " << c << endl;

    // Circle ��
    Circle* waffle = new Circle(10);
    Circle* pizza = new Circle(20);
    Circle* y = bigger_ptr(waffle, pizza);
    cout << "waffle�� pizza �� ū ���� �������� " << y->getRadius() << endl;

    delete waffle;
    delete pizza;

    return 0;
}
