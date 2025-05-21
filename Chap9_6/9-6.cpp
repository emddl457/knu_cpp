#include <iostream>
using namespace std;

//추상 클래스: 스택 인터페이스 정의
class AbstractStack {
public:
    //스택에 정수 n을 push. 꽉 차 있으면 false
    virtual bool push(int n) = 0;

    //스택에서 정수 하나 pop. n에 저장. 비어있으면 false
    virtual bool pop(int& n) = 0;

    //현재 스택에 저장된 정수 개수 반환
    virtual int size() = 0;
};

//정수형 스택 구현 클래스
class IntStack : public AbstractStack {
private:
    int data[100];   //고정 크기 배열로 스택 구성 (최대 100개)
    int top;         //스택의 최상단 인덱스

public:
    //생성자: 스택 비워진 상태로 시작
    IntStack() {
        top = -1;
    }

    //push: 스택에 n을 추가. 꽉 차면 실패
    bool push(int n) override {
        if (top >= 99) return false;  //스택이 가득 찼을 경우
        data[++top] = n;
        return true;
    }

    //pop: top에 있는 값 꺼내기. 비었으면 실패
    bool pop(int& n) override {
        if (top < 0) return false;  //스택이 비었을 경우
        n = data[top--];
        return true;
    }

    //현재 스택에 들어있는 원소 수
    int size() override {
        return top + 1;
    }
};

int main() {
    IntStack stack;

    //스택에 값 10, 20, 30을 push
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "스택 크기: " << stack.size() << endl;

    int value;
    while (stack.pop(value)) {
        cout << "pop: " << value << endl;
    }

    cout << "스택이 모두 비워졌습니다. 현재 크기: " << stack.size() << endl;

    return 0;
}
