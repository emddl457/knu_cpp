#include <iostream>
using namespace std;

class Circle {
    int radius; // 원의 반지름

public:
    // 생성자: 기본값 0으로 설정해도 되고, 원하는 값 넣을 수도 있음
    Circle(int radius = 0) { this->radius = radius; }

    // 전위 ++ 연산자 오버로딩 (ex: ++a)
    Circle& operator++() {
        radius++;         // 반지름 먼저 증가시킴
        return *this;     // 자기 자신을 반환 (연쇄 호출 가능)
    }

    // 후위 ++ 연산자 오버로딩 (ex: a++)
    Circle operator++(int) {
        Circle temp = *this; // 현재 값 저장
        radius++;            // 원본 반지름 증가
        return temp;         // 증가 전 값 반환
    }

    // 반지름 출력 함수
    void show() {
        cout << "radius = " << radius << " 인 원" << endl;
    }
};

int main() {
    Circle a(5), b(4);   // 반지름 5, 4짜리 Circle 생성

    ++a;   // 전위 증가: 반지름을 먼저 증가 → a = 6
    b = a++; // 후위 증가: b에 a의 이전 값(6) 저장하고 a는 7됨

    a.show(); 
    b.show();

    return 0;
}
// operator<< ...객체를 cout << 형태로 출력할 수 있도록 만들어주는 연산자 오버로딩
// operator++() ...전위 증가. 값을 먼저 증가시키고, 변경된 자기 자신을 반환함
// operator++(int) ...후위 증가. 임시 복사본을 먼저 반환하고, 그 후에 값을 증가시킴
// friend ...클래스 외부 함수가 private 멤버에 접근할 수 있도록 허용하는 키워드(그냥 반복외우기)
