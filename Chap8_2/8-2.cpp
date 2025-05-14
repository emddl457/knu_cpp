#include <iostream>
#include <string>
using namespace std;

// Circle Ŭ����
class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

// NamedCircle Ŭ���� (Circle�� ���)
class NamedCircle : public Circle {
    string name;
public:
    // ����Ʈ ������
    NamedCircle() : Circle(0), name("") {}

    // �Ű����� �ִ� ������
    NamedCircle(int r, string n) : Circle(r), name(n) {}

    string getName() { return name; }

    void setName(string n) { name = n; }

    void show() {
        cout << getRadius() << "�� " << name << endl;
    }
};

// main �Լ�
int main() {
    NamedCircle pizza[5];  // ���� �迭 ����

    // ����� �Է�
    cout << "5 ���� ���� �������� ���� �̸��� �Է��ϼ���" << endl;
    for (int i = 0; i < 5; i++) {
        int r;
        string name;
        cout << i + 1 << ">> ";
        cin >> r >> name;
        pizza[i] = NamedCircle(r, name);
    }

    // ���� ū ���� ã��
    int maxIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (pizza[i].getArea() > pizza[maxIndex].getArea()) {
            maxIndex = i;
        }
    }

    // ��� ���
    cout << "���� ������ ū ���ڴ� " << pizza[maxIndex].getName() << "�Դϴ�" << endl;

    return 0;
}
