#include <iostream>
#include <string>
using namespace std;

// 기본 클래스 Point
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

// 파생 클래스 ColorPoint: 색상을 가진 점
class ColorPoint : public Point {
    string color;
public:
    // 생성자: x, y 좌표 + 색상 입력
    ColorPoint(int x, int y, string color) : Point(x, y) {
        this->color = color;
    }

    // 좌표 변경 함수: 부모 클래스의 move() 호출
    void setPoint(int x, int y) {
        move(x, y);  // protected니까 자식에서 호출 가능
    }

    // 색상 변경 함수
    void setColor(string color) {
        this->color = color;
    }

    // 정보 출력 함수
    void show() {
        cout << color << "색으로 (" << getX() << "," << getY() << ")에 위치한 점입니다." << endl;
    }
};

// main 함수
int main() {
    ColorPoint cp(5, 5, "RED");  // 초기 위치와 색상 설정
    cp.setPoint(10, 20);         // 좌표 이동
    cp.setColor("BLUE");         // 색상 변경
    cp.show();                   // 출력

    return 0;
}
