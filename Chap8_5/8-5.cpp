#include <iostream>
using namespace std;

// 문제에서 주어진 BaseArray 클래스
class BaseArray {
private:
    int capacity;  //배열의 최대 크기 (용량)
    int* mem;      //실제 데이터를 저장할 동적 배열
protected:
    BaseArray(int capacity = 100) {  //생성자: capacity만큼 메모리 할당
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }   //소멸자: 동적 메모리 해제

    //mem 배열에 index 위치에 val 저장
    void put(int index, int val) { mem[index] = val; }

    //index 위치의 값을 반환
    int get(int index) { return mem[index]; }

    //배열의 용량 반환
    int getCapacity() { return capacity; }
};

// BaseArray를 상속받아 큐처럼 동작하는 MyQueue 클래스
class MyQueue : public BaseArray {
    int front;  // 큐의 앞쪽 인덱스 (dequeue할 위치)
    int rear;   // 큐의 끝쪽 인덱스 (enqueue할 위치)
    int size;   // 현재 큐에 저장된 데이터 개수
public:
    MyQueue(int capacity) : BaseArray(capacity) {
        front = 0;  // 처음에는 앞도 0
        rear = 0;   // 끝도 0
        size = 0;   // 초기에는 큐가 비어 있음
    }

    // 큐에 데이터를 삽입하는 함수
    void enqueue(int n) {
        if (size < getCapacity()) { // 큐에 공간이 있을 때만 삽입
            put(rear, n);           // rear 위치에 값 저장
            rear = (rear + 1) % getCapacity(); // rear를 다음 위치로 이동 (원형 큐)
            size++;                            // 현재 크기 1 증가
        }
    }

    // 큐에서 데이터를 제거하고 반환하는 함수
    int dequeue() {
        if (size == 0) return -1;  // 비어있으면 -1 반환 (안전장치)
        int val = get(front);      // front 위치의 값을 가져옴
        front = (front + 1) % getCapacity(); // front를 다음 위치로 이동
        size--;  // 현재 크기 1 감소
        return val;
    }

    //현재 큐에 들어 있는 데이터 개수 반환
    int length() { return size; }

    //큐의 전체 용량 반환 (BaseArray의 getCapacity 호출)
    int capacity() { return getCapacity(); }
};

// 메인 함수
int main() {
    MyQueue mQ(100);  //큐 용량 100짜리 객체 생성
    int n;
    cout << "큐에 삽입할 5개의 정수를 입력하라>> ";

    //5개의 값을 입력받아 큐에 삽입
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }

    //큐의 상태 출력
    cout << "큐의 용량: " << mQ.capacity() << ", 큐의 크기: " << mQ.length() << endl;

    cout << "큐의 원소를 순서대로 제거하여 출력한다>> ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << " ";
    }

    //마지막으로 큐의 크기 출력 (0이 되어야 정상)
    cout << endl << "큐의 현재 크기: " << mQ.length() << endl;

    return 0;
}
