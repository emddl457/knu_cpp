#include <iostream>
using namespace std;

// 추상 클래스: 공통 인터페이스 제공
class AbstractGate {
protected:
    bool x, y; // 두 입력 값

public:
    // 두 입력 값을 설정
    void set(bool x, bool y) {
        this->x = x;
        this->y = y;
    }

    //연산 함수: 자식 클래스가 반드시 구현해야 함
    virtual bool operation() = 0;
};

//AND 게이트: 둘 다 true일 때만 true
class ANDGate : public AbstractGate {
public:
    bool operation() override {
        return x && y;
    }
};

//OR 게이트: 둘 중 하나라도 true면 true
class ORGate : public AbstractGate {
public:
    bool operation() override {
        return x || y;
    }
};

//XOR 게이트: 두 값이 다를 때 true
class XORGate : public AbstractGate {
public:
    bool operation() override {
        return x != y;
    }
};

int main() {
    //각각의 게이트 객체 생성
    ANDGate andGate;
    ORGate orGate;
    XORGate xorGate;

    //입력값 설정
    andGate.set(true, false);
    orGate.set(true, false);
    xorGate.set(true, false);

    //불린 값 출력 시 true/false 문자열로 보이게 설정
    cout.setf(ios::boolalpha);

    cout << andGate.operation() << endl; 
    cout << orGate.operation() << endl;  
    cout << xorGate.operation() << endl; 

    return 0;
}
