#include <iostream>
#include <string>
using namespace std;

// Point Ŭ����
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

// ColorPoint Ŭ����
class ColorPoint : public Point {
    string color;
public:
    // �⺻ ������: (0,0), "BLACK"
    ColorPoint() : Point(0, 0) {
        color = "BLACK";
    }

    // ��ǥ�� �޴� ������: ������ �⺻�� BLACK
    ColorPoint(int x, int y) : Point(x, y) {
        color = "BLACK";
    }

    // ��ǥ + ���� �޴� ������
    ColorPoint(int x, int y, string color) : Point(x, y) {
        this->color = color;
    }

    void setPoint(int x, int y) {
        move(x, y);
    }

    void setColor(string color) {
        this->color = color;
    }

    void show() {
        cout << color << "������ (" << getX() << "," << getY() << ")�� ��ġ�� ���Դϴ�." << endl;
    }
};

// main �Լ�
int main() {
    ColorPoint zeroPoint;       // �⺻ ������ ���: (0,0) + BLACK
    zeroPoint.show();

    ColorPoint cp(5, 5);        // ��ġ�� ����, ������ �⺻�� BLACK
    cp.setPoint(10, 20);        // ��ġ ����
    cp.setColor("BLUE");        // ���� ����
    cp.show();                  

    return 0;
}
