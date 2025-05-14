#include <iostream>
using namespace std;

//문제에서 제공한 BaseArray 클래스
class BaseArray {
private:
    int capacity;  //배열의 최대 용량
    int* mem;      //동적으로 할당된 배열
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity;
        mem = new int[capacity];  //지정된 크기로 동적 배열 생성
    }

    ~BaseArray() { delete[] mem; }  //소멸자에서 메모리 해제

    void put(int index, int val) { mem[index] = val; }  //배열 값 설정
    int get(int index) { return mem[index]; }           //배열 값 반환
    int getCapacity() { return capacity; }              //배열 용량 반환
};

//스택 자료구조처럼 동작하는 MyStack 클래스 (BaseArray 상속)
class MyStack : public BaseArray {
    int top;  //스택의 현재 요소 개수 (다음 push할 위치)
public:
    MyStack(int capacity) : BaseArray(capacity) {
        top = 0; //스택 처음에는 비어 있음 (top은 0부터 시작)
    }

    // 스택에 데이터를 삽입하는 함수
    void push(int n) {
        if (top < getCapacity()) {    //용량 초과가 아닌 경우만 삽입
            put(top, n);              //top 위치에 값 저장
            top++;                    //top 1 증가
        }
    }

    //스택에서 데이터를 꺼내는 함수 (가장 최근 값)
    int pop() {
        if (top == 0) return -1; //스택이 비어있으면 -1 반환
        top--; //top 감소 후
        return get(top); //감소된 위치의 값 반환
    }

    // 현재 스택에 쌓인 요소 개수 반환
    int length() { return top; }

    // 스택 전체 용량 반환
    int capacity() { return getCapacity(); }
};

// 메인 함수
int main() {
    MyStack mStack(100);  // 용량 100짜리 스택 객체 생성
    int n;

    cout << "스택에 삽입할 5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;               
        mStack.push(n);        
    }

    // 현재 상태 출력
    cout << "스택용량: " << mStack.capacity() << ", 스택크기: " << mStack.length() << endl;

    cout << "스택의 모든 원소를 팝하여 출력한다>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << " ";  // 하나씩 꺼내서 출력
    }

    cout << endl << "스택의 현재 크기 : " << mStack.length() << endl;

    return 0;
}
