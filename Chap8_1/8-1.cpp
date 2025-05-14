#include <iostream>  
#include <string>   
using namespace std; 

// Circle 클래스 정의 (원의 반지름과 넓이를 다루는 클래스)
class Circle {
    int radius;  // 원의 반지름을 저장하는 멤버 변수
public:
    // 생성자: 객체를 만들 때 반지름 값을 설정 (기본값 0도 가능)
    Circle(int radius = 0) {
        this->radius = radius;  // 매개변수 radius를 멤버 변수 radius에 저장
    }

    // 반지름 값을 반환하는 함수
    int getRadius() {
        return radius;
    }

    // 반지름 값을 새로 설정하는 함수
    void setRadius(int radius) {
        this->radius = radius;
    }

    // 원의 넓이를 계산해서 반환하는 함수 (πr² 공식 사용)
    double getArea() {
        return 3.14 * radius * radius;
    }
};

// Circle 클래스를 상속받는 NamedCircle 클래스 정의
class NamedCircle : public Circle {
    string name;  // 원의 이름을 저장하는 멤버 변수
public:
    // 매개변수가 있는 생성자: 반지름과 이름을 전달받아 초기화
    NamedCircle(int r, string n) : Circle(r), name(n) {
        // Circle(r): 부모 클래스의 생성자 호출해서 반지름 설정
        // name(n): 전달받은 문자열 n을 멤버 변수 name에 저장
    }

    // 원의 정보(반지름과 이름)를 화면에 출력하는 함수
    void show() {
        // getRadius(): 부모 클래스(Circle)의 함수 사용해서 반지름 가져옴
        cout << "반지름이 " << getRadius() << "인 " << name << endl;
    }
};

// main 함수: 프로그램 실행 시작점
int main() {
    // NamedCircle 객체 생성: 반지름이 3이고 이름이 "waffle"인 원
    NamedCircle waffle(3, "waffle");

    // waffle 객체의 정보를 출력 (반지름과 이름)
    waffle.show();

    return 0; 
}