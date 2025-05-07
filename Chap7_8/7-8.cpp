#include <iostream>
using namespace std;

class Circle {
    int radius; // ���� ������

public:
    // ������: �⺻�� 0���� �����ص� �ǰ�, ���ϴ� �� ���� ���� ����
    Circle(int radius = 0) { this->radius = radius; }

    // ���� ++ ������ �����ε� (ex: ++a)
    Circle& operator++() {
        radius++;         // ������ ���� ������Ŵ
        return *this;     // �ڱ� �ڽ��� ��ȯ (���� ȣ�� ����)
    }

    // ���� ++ ������ �����ε� (ex: a++)
    Circle operator++(int) {
        Circle temp = *this; // ���� �� ����
        radius++;            // ���� ������ ����
        return temp;         // ���� �� �� ��ȯ
    }

    // ������ ��� �Լ�
    void show() {
        cout << "radius = " << radius << " �� ��" << endl;
    }
};

int main() {
    Circle a(5), b(4);   // ������ 5, 4¥�� Circle ����

    ++a;   // ���� ����: �������� ���� ���� �� a = 6
    b = a++; // ���� ����: b�� a�� ���� ��(6) �����ϰ� a�� 7��

    a.show(); 
    b.show();

    return 0;
}
// operator<< ...��ü�� cout << ���·� ����� �� �ֵ��� ������ִ� ������ �����ε�
// operator++() ...���� ����. ���� ���� ������Ű��, ����� �ڱ� �ڽ��� ��ȯ��
// operator++(int) ...���� ����. �ӽ� ���纻�� ���� ��ȯ�ϰ�, �� �Ŀ� ���� ������Ŵ
// friend ...Ŭ���� �ܺ� �Լ��� private ����� ������ �� �ֵ��� ����ϴ� Ű����(�׳� �ݺ��ܿ��)
