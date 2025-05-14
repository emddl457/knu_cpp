#include <iostream>
#include <string>
using namespace std;

// Circle 클래스
class Circle {
    int radius;
public:
    Circle(int radius = 0) { this->radius = radius; }
    int getRadius() { return radius; }
    void setRadius(int radius) { this->radius = radius; }
    double getArea() { return 3.14 * radius * radius; }
};

// NamedCircle 클래스 (Circle을 상속)
class NamedCircle : public Circle {
    string name;
public:
    // 디폴트 생성자
    NamedCircle() : Circle(0), name("") {}

    // 매개변수 있는 생성자
    NamedCircle(int r, string n) : Circle(r), name(n) {}

    string getName() { return name; }

    void setName(string n) { name = n; }

    void show() {
        cout << getRadius() << "인 " << name << endl;
    }
};

// main 함수
int main() {
    NamedCircle pizza[5];  // 피자 배열 선언

    // 사용자 입력
    cout << "5 개의 정수 반지름과 원의 이름을 입력하세요" << endl;
    for (int i = 0; i < 5; i++) {
        int r;
        string name;
        cout << i + 1 << ">> ";
        cin >> r >> name;
        pizza[i] = NamedCircle(r, name);
    }

    // 가장 큰 피자 찾기
    int maxIndex = 0;
    for (int i = 1; i < 5; i++) {
        if (pizza[i].getArea() > pizza[maxIndex].getArea()) {
            maxIndex = i;
        }
    }

    // 결과 출력
    cout << "가장 면적이 큰 피자는 " << pizza[maxIndex].getName() << "입니다" << endl;

    return 0;
}
