#include <iostream>
#include <string>
using namespace std;

// �⺻ Ŭ���� Point
class Point {
    int x, y;
public:
    Point(int x, int y) {
        this->x = x;
        this->y = y;
    }

    int getX() { return x; }
    int getY() { return y; }

protected:
    void move(int x, int y) {
        this->x = x;
        this->y = y;
    }
};

// �Ļ� Ŭ���� ColorPoint: ������ ���� ��
class ColorPoint : public Point {
    string color;
public:
    // ������: x, y ��ǥ + ���� �Է�
    ColorPoint(int x, int y, string color) : Point(x, y) {
        this->color = color;
    }

    // ��ǥ ���� �Լ�: �θ� Ŭ������ move() ȣ��
    void setPoint(int x, int y) {
        move(x, y);  // protected�ϱ� �ڽĿ��� ȣ�� ����
    }

    // ���� ���� �Լ�
    void setColor(string color) {
        this->color = color;
    }

    // ���� ��� �Լ�
    void show() {
        cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
    }
};

// main �Լ�
int main() {
    ColorPoint cp(5, 5, "RED");  // �ʱ� ��ġ�� ���� ����
    cp.setPoint(10, 20);         // ��ǥ �̵�
    cp.setColor("BLUE");         // ���� ����
    cp.show();                   // ���

    return 0;
}
