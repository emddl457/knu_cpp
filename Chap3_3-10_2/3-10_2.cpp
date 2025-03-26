#include <iostream>
#include "3-10_2.h"
using namespace std;

// (1)에서는 선언+구현을 한 파일에 모두 작성하였으나!
// 이번에는 선언과 구현을 분리하여 작성하므로 (1)과는 다르게 작성한다.
// (2)는 선언(헤더)과 구현(.cpp)을 나누기 때문에, 아래처럼 '클래스이름::함수이름' 형태로 구현해야 한다.
void Add::setValue(int x, int y) { a = x; b = y; } // 두 정수 값을 멤버 변수 a, b에 저장!
int Add::calculate() { return a + b; } // 두 정수의 합을 반환!

void Sub::setValue(int x, int y) { a = x; b = y; }
int Sub::calculate() { return a - b; }

void Mul::setValue(int x, int y) { a = x; b = y; }
int Mul::calculate() { return a * b; }

void Div::setValue(int x, int y) { a = x; b = y; }
int Div::calculate() 
{
    if (b == 0) {
        cout << "0으로 나눌 수 없습니다." << endl;
        return 0;
    }
    return a / b;
}

int main() // 연산 별로 객체 생성
{
    Add a;
    Sub s;
    Mul m;
    Div d;

    while (true) 
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
// 이렇게 하면 3-10_2.cpp 파일에서는 3-10_2.h 파일을 include하여 사용할 수 있다.