#include <iostream>
#include <string>  
using namespace std;

class Integer
{
private: // 객체 외부에서 직접 value에 접근하는 코드가 없으니 private만은 생략해도 안전하다!
    int value;  // 정수 값을 저장할 멤버 변수. get()이나 set() 함수로만 다루게 한다.

public:
    Integer(int value)
    {
        this->value = value;  // 멤버 변수와 매개변수 구분을 위해 this 사용(this->value는 클래스 안에 있는 value. value는 매개변수로 전달된 값.
    }

    Integer(string str) // 문자열로 객체를 만든다. Integer m("100"); 같이!
    {
        value = stoi(str);  // 문자열을 정수로 변환해 저장 (std::stoi 사용). stoi()는 "100"같은 문자열을 숫자 100으로 바꿔주는 함수이다.
    }

    // 이 함수는 클래스 내부에 저장된 value 값을 외부에서 읽을 수 있게 해준다.
    int get() const // (n.value  = 333; 이나 cout ? n.value; 처럼 직접 바꾸거나 직접 가져오지 않기.)
    {
        return value;
    }

    void set(int value) // 객체에 들어있는 값을 바꾸고 싶을 때 사용한다.
    {
        this->value = value; // n.set(10);은 n 객체의 내부 값을 10으로 바꿔준다.
    }

    bool isEven() const // int 자료형은 정수(10. 100), bool 자료형은 참/거짓 -> true or false.
        // isEven() 함수는 단순히 value 값을 읽기만 하지, 값을 바꾸지는 않는다.
        // 그래서 const를 붙여야 함수가 객체를 변경하지 않는다는 것을 보장하고 const 객체에도 사용할 수 있다.
        // 사실 const를 안 사용해도 되지만, 사용하는 것이 좋다. (컴파일러가 오류를 잡아줄 수 있기 때문)
        // 나는 이 함수에서 멤버 변수 안 건드릴게요! 하는 중. 그러나 객체 자체를 const로 선언했을 때, const 함수가 없으면 에러가 난다.
    {
        return value % 2 == 0; // 가진 숫자가 짝수인지 묻는다. 짝수면 true, 홀수면 false 반환!
    }
};

int main()
{
    Integer n(30);
    cout << n.get() << ' ';   // 30 출력
    n.set(50);
    cout << n.get() << ' ';   // 50 출력

    Integer m("300");         // 문자열을 정수로 변환
    cout << m.get() << ' ';   // 300 출력
    cout << m.isEven();       // 1 출력 (true)
}
