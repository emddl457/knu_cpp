#include <iostream>  
#include <string>   
using namespace std; 

// Circle Ŭ���� ���� (���� �������� ���̸� �ٷ�� Ŭ����)
class Circle {
    int radius;  // ���� �������� �����ϴ� ��� ����
public:
    // ������: ��ü�� ���� �� ������ ���� ���� (�⺻�� 0�� ����)
    Circle(int radius = 0) {
        this->radius = radius;  // �Ű����� radius�� ��� ���� radius�� ����
    }

    // ������ ���� ��ȯ�ϴ� �Լ�
    int getRadius() {
        return radius;
    }

    // ������ ���� ���� �����ϴ� �Լ�
    void setRadius(int radius) {
        this->radius = radius;
    }

    // ���� ���̸� ����ؼ� ��ȯ�ϴ� �Լ� (��r�� ���� ���)
    double getArea() {
        return 3.14 * radius * radius;
    }
};

// Circle Ŭ������ ��ӹ޴� NamedCircle Ŭ���� ����
class NamedCircle : public Circle {
    string name;  // ���� �̸��� �����ϴ� ��� ����
public:
    // �Ű������� �ִ� ������: �������� �̸��� ���޹޾� �ʱ�ȭ
    NamedCircle(int r, string n) : Circle(r), name(n) {
        // Circle(r): �θ� Ŭ������ ������ ȣ���ؼ� ������ ����
        // name(n): ���޹��� ���ڿ� n�� ��� ���� name�� ����
    }

    // ���� ����(�������� �̸�)�� ȭ�鿡 ����ϴ� �Լ�
    void show() {
        // getRadius(): �θ� Ŭ����(Circle)�� �Լ� ����ؼ� ������ ������
        cout << "�������� " << getRadius() << "�� " << name << endl;
    }
};

// main �Լ�: ���α׷� ���� ������
int main() {
    // NamedCircle ��ü ����: �������� 3�̰� �̸��� "waffle"�� ��
    NamedCircle waffle(3, "waffle");

    // waffle ��ü�� ������ ��� (�������� �̸�)
    waffle.show();

    return 0; 
}