#include <iostream>
#include <string>
using namespace std;

class Shape {
protected:
    string name;   //도형 이름
    int width;     //너비
    int height;    //높이

public:
    //생성자
    Shape(string n = "", int w = 0, int h = 0) {
        name = n;
        width = w;
        height = h;
    }

    //가상 함수: 도형 넓이 반환 (각 도형에서 구현)
    virtual double getArea() { return 0; }

    //이름 반환
    string getName() { return name; }
};

//타원형 클래스
class Oval : public Shape {
public:
    Oval(string name, int w, int h) : Shape(name, w, h) {}

    //타원의 넓이: π × 반지름1 × 반지름2
    double getArea() override {
        return 3.14 * width * height;
    }
};

class Rect : public Shape {
public:
    Rect(string name, int w, int h) : Shape(name, w, h) {}

    //사각형 넓이: 가로 × 세로
    double getArea() override {
        return width * height;
    }
};

class Triangular : public Shape {
public:
    Triangular(string name, int w, int h) : Shape(name, w, h) {}

    //삼각형 넓이: (가로 × 세로) / 2
    double getArea() override {
        return width * height / 2;
    }
};

int main() {
    //Shape 포인터 배열 생성
    Shape* p[3];

    //각각의 도형 객체 생성 후 배열에 저장
    p[0] = new Oval("빈대떡", 10, 20);
    p[1] = new Rect("찰떡", 30, 40);
    p[2] = new Triangular("토스트", 30, 40);

    //각 도형의 이름과 넓이 출력
    for (int i = 0; i < 3; i++) {
        cout << p[i]->getName() << " 넓이는 " << p[i]->getArea() << endl;
    }

    //할당된 메모리 해제
    for (int i = 0; i < 3; i++) {
        delete p[i];
    }

    return 0;
}
