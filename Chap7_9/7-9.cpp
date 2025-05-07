#include <iostream>
using namespace std;

class Circle {
    int radius; // ���� ������

public:
    // ������: ������ �ʱ�ȭ. �⺻�� 0
    Circle(int radius = 0) { this->radius = radius; }

    // ������ ��� �Լ�
    void show() {
        cout << "radius = " << radius << " �� ��" << endl;
    }

    // + ������ �����ε� (int + Circle ���� ����)
    // int�� ���ʿ� ���� �����̹Ƿ� ��� �Լ��δ� �Ұ� �� friend �Լ��� ����
    friend Circle operator+(int value, Circle c) {
        // �������� value�� ���� ���ο� Circle ��ȯ
        return Circle(c.radius + value);
    }
};

int main() {
    Circle a(5), b(4);

    b = 1 + a;   // b = operator+(1, a); �� ȣ���

    a.show();    
    b.show();   

    return 0;
}
