#include <iostream>
using namespace std;

// 📦 Stack 클래스 선언: 정수를 저장하는 스택 구조 구현
class Stack {
    int data[100];  // 최대 100개까지 저장 가능한 정수 배열
    int top;        // 스택의 맨 위 요소가 위치하는 인덱스

public:
    Stack() { top = -1; }  // 생성자: 비어있는 상태로 초기화 (top = -1)

    // push 연산자 오버로딩: stack << 10; 처럼 쓰기 위해
    Stack& operator<<(int value) {
        if (top < 99) data[++top] = value;  // top을 1 증가시키고 배열에 저장
        return *this;  // 연쇄적으로 << 계속 가능하게 하기 위해 자기 자신 반환
    }

    // pop 연산자 오버로딩: stack >> x; 처럼 쓰기 위해
    Stack& operator>>(int& value) {
        if (top >= 0) value = data[top--];  // top 위치의 값 꺼낸 후 top 감소
        return *this;  // 자기 자신 반환
    }

    // !stack → 스택이 비었는지 확인하는 연산자 오버로딩
    bool operator!() {
        return top == -1;  // top이 -1이면 비어있음 (true 반환)
    }
};

int main() {
    Stack stack;  // Stack 객체 생성

    // 스택에 값을 넣기 (push). 3 → 5 → 10 순서로 들어감
    stack << 3 << 5 << 10;

    while (true) {
        if (!stack) break;  // 스택이 비었으면 반복 종료 (! 연산자 오버로딩)

        int x;
        stack >> x;         // 스택에서 값을 꺼내서 x에 저장 (pop)
        cout << x << " ";   // 꺼낸 값을 출력
    }

    cout << endl;

    return 0;
}
