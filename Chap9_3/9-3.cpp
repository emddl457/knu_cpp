#include <iostream>
#include <string>
using namespace std;

//x~y까지 더하는 루프 구조 정의
class LoopAdder {
    string name;   //루프 이름
    int x, y, sum; //시작값, 끝값, 합 저장
    void read();   //사용자 입력 받는 함수
    void write();  //결과 출력 함수

protected:
    //루프 이름 초기화
    LoopAdder(string name = "") { this->name = name; }

    //입력값 x, y에 접근하는 getter 함수
    int getX() { return x; }
    int getY() { return y; }

    //순수 가상 함수: 자식 클래스에서 직접 구현
    virtual int calculate() = 0;

public:
    //실행 함수: 입력받고 계산하고 출력
    void run();
};

//사용자로부터 두 수 입력받기
void LoopAdder::read() {
    cout << name << " : " << endl;
    cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
    cin >> x >> y;
}

// 계산 결과 출력
void LoopAdder::write() {
    cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

//실행 흐름은 입력 계산 출력
void LoopAdder::run() {
    read();               //입력 받고
    sum = calculate();    //자식 클래스의 계산 함수 실행
    write();              //결과 출력
}

//실제로 for문으로 더하는 자식 클래스 정의
class ForLoopAdder : public LoopAdder {
public:
    //생성자: 루프 이름 전달
    ForLoopAdder(string name) : LoopAdder(name) {}

    //x부터 y까지 for문으로 합 계산
    int calculate() override {
        int total = 0;
        for (int i = getX(); i <= getY(); i++) {
            total += i;
        }
        return total;
    }
};

int main() {
    ForLoopAdder forLoop("For Loop"); //루프 이름을 지정하여 객체 생성
    forLoop.run(); //실행
    return 0;
}
