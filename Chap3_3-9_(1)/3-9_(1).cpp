#include <iostream>
using namespace std;

class Oval // 하나의 클래스 정의만 사용해야 한다.
{
private:
    // !! 타원의 너비와 높이를 저장하는 멤버 변수 !!
    int width;
    int height;

public: // 선언부와 구현부를 분리하려다가 Oval이라는 클래스가 중복 선언되어서 오류가 발생함. 그래서 public으로 선언부와 구현부를 같이 써줌.
    // !! 기본 생성자: 너비와 높이를 1로 초기화 !!
    Oval() 
    {
        width = height = 1;
    }

    // !! 매개변수 생성자: 주어진 값으로 너비와 높이를 초기화 !!
    Oval(int w, int h) 
    {
        width = w;
        height = h;
    }

    // !! 소멸자: 객체가 삭제될 때 호출됨 (현재 상태 출력) !!
    // 소멸자의 문법 규칙: ~클래스이름() { //소멸될 때 할 작업)}
    // 생성자와 이름이 똑같으면 혼동될 수 있으니 ~를 붙여준다. 반환형 없음! 매개변수 없음! 자동 호출됨!

    ~Oval()
    {
        cout << "Oval 소멸 : width = " << width
            << ", height = " << height << endl;
    }

    // 너비와 높이를 설정하는 함수
    void set(int w, int h) 
    {
        width = w;
        height = h;
    }

    // 너비를 반환하는 함수
    int getWidth() 
    {
        return width;
    }

    // 높이를 반환하는 함수
    int getHeight() 
    {
        return height;
    }

    // 현재 타원의 정보를 출력하는 함수
    void show() 
    {
        cout << "width = " << width
            << ", height = " << height << endl;
    }
};

int main() 
{
    // 기본 생성자 호출하기 -> width = 1, height = 1
    Oval a;

    // 매개변수 생성자 호출하기 -> width = 3, height = 4
    Oval b(3, 4);

    // a의 값을 변경하기 -> width = 10, height = 20
    a.set(10, 20);

    // a의 상태 출력
    a.show(); 

    // b의 너비와 높이 출력
    cout << b.getWidth() << "," << b.getHeight() << endl;

    return 0;  
}
