#include <iostream>
using namespace std;

class Circle {
    int radius; // 원의 반지름

public:
    // 생성자: 반지름 초기화. 기본값 0
    Circle(int radius = 0) { this->radius = radius; }

    // 반지름 출력 함수
    void show() {
        cout << "radius = " << radius << " 인 원" << endl;
    }

    // + 연산자 오버로딩 (int + Circle 형태 지원)
    // int가 왼쪽에 오는 형태이므로 멤버 함수로는 불가 → friend 함수로 구현
    friend Circle operator+(int value, Circle c) {
        // 반지름에 value를 더한 새로운 Circle 반환
        return Circle(c.radius + value);
    }
};

int main() {
    Circle a(5), b(4);

    b = 1 + a;   // b = operator+(1, a); 가 호출됨

    a.show();    
    b.show();   

    return 0;
}
