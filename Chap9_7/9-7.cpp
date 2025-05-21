#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;   //���� �̸�
    int width;     //�ʺ�
    int height;    //����

public:
    //������
    Shape(string n = "", int w = 0, int h = 0) {
        name = n;
        width = w;
        height = h;
    }

    //���� �Լ�: ���� ���� ��ȯ (�� �������� ����)
    virtual double getArea() { return 0; }

    //�̸� ��ȯ
    string getName() { return name; }
};

//Ÿ���� Ŭ����
class Oval : public Shape {
public:
    Oval(string name, int w, int h) : Shape(name, w, h) {}

    //Ÿ���� ����: �� �� ������1 �� ������2
    double getArea() override {
        return 3.14 * width * height;
    }
};

class Rect : public Shape {
public:
    Rect(string name, int w, int h) : Shape(name, w, h) {}

    //�簢�� ����: ���� �� ����
    double getArea() override {
        return width * height;
    }
};

class Triangular : public Shape {
public:
    Triangular(string name, int w, int h) : Shape(name, w, h) {}

    //�ﰢ�� ����: (���� �� ����) / 2
    double getArea() override {
        return width * height / 2;
    }
};

int main() {
    //Shape ������ �迭 ����
    Shape* p[3];

    //������ ���� ��ü ���� �� �迭�� ����
    p[0] = new Oval("��붱", 10, 20);
    p[1] = new Rect("����", 30, 40);
    p[2] = new Triangular("�佺Ʈ", 30, 40);

    //�� ������ �̸��� ���� ���
    for (int i = 0; i < 3; i++) {
        cout << p[i]->getName() << " ���̴� " << p[i]->getArea() << endl;
    }

    //�Ҵ�� �޸� ����
    for (int i = 0; i < 3; i++) {
        delete p[i];
    }

    return 0;
}
