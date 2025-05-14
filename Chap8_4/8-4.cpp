#include <iostream>
#include <string>
using namespace std;

// Point 클래스
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

// ColorPoint 클래스
class ColorPoint : public Point {
    string color;
public:
    // 기본 생성자: (0,0), "BLACK"
    ColorPoint() : Point(0, 0) {
        color = "BLACK";
    }

    // 좌표만 받는 생성자: 색상은 기본값 BLACK
    ColorPoint(int x, int y) : Point(x, y) {
        color = "BLACK";
    }

    // 좌표 + 색상 받는 생성자
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
        cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
    }
};

// main 함수
int main() {
    ColorPoint zeroPoint;       // 기본 생성자 사용: (0,0) + BLACK
    zeroPoint.show();

    ColorPoint cp(5, 5);        // 위치만 지정, 색상은 기본값 BLACK
    cp.setPoint(10, 20);        // 위치 변경
    cp.setColor("BLUE");        // 색상 변경
    cp.show();                  

    return 0;
}
