// 10번-(1)의 풀이
#include <iostream>
using namespace std;

class Add 
{
    int a, b; // 두 수를 저장할 멤버 변수 만들기
public:
    void setValue(int x, int y) { a = x; b = y; }  // 외부에서 a, b 값을 설정하는 함수
    int calculate() { return a + b; } // 덧셈 결과를 반환
};

class Sub // 빼기도 위의 덧셈과 같이..
{ 
    int a, b;
public:
    void setValue(int x, int y) { a = x; b = y; }
    int calculate() { return a - b; }
};

class Mul // 곱하기
{ 
    int a, b;
public:
    void setValue(int x, int y) { a = x; b = y; } // 중괄호는  함수의 실제 실행 내용을 나타냄
	int calculate() { return a * b; } //반환형이 없으면 컴파일 오류가 발생함.
};

class Div // 나누기
{ 
    int a, b;
public:
    void setValue(int x, int y) { a = x; b = y; }
    int calculate() 
    {
        if (b == 0) // 나누는 수가 0일 때의 오류 방지!!
        { 
            cout << "0으로 나눌 수 없습니다." << endl;
            return 0;
        }
        return a / b;
    }
};

int main() // 각각의 연산을 담당하는 클래스 객체 4개 만들기
{ 
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (true) //무한 루프. 사용자에게 두 수를 입력받고 프로그램은 계속 반복되게 함.
    { 
        int x, y;
        char op;
        cout << "두 정수와 연산자를 입력하세요>> ";
        cin >> x >> y >> op;

        if (op == '+') { a.setValue(x, y); cout << a.calculate() << endl; }
        else if (op == '-') { s.setValue(x, y); cout << s.calculate() << endl; }
        else if (op == '*') { m.setValue(x, y); cout << m.calculate() << endl; }
        else if (op == '/') { d.setValue(x, y); cout << d.calculate() << endl; }
        else cout << "지원하지 않는 연산자입니다." << endl;
    }

    return 0;
}
