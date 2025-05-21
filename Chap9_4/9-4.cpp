#include <iostream>
#include <string>
using namespace std;

//이미 주어진 LoopAdder 추상 클래스
class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();

protected:
    LoopAdder(string name = "") { this->name = name; }

    int getX() { return x; }
    int getY() { return y; }

    virtual int calculate() = 0; //자식 클래스가 직접 구현해야 하는 함수

public:
    void run();
};

void LoopAdder::read() {
    cout << name << " : " << endl;
    cout << "처음 수에서 두번째 수까지 더합니다. 두 수를 입력하세요 >> ";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << x << "에서 " << y << "까지의 합 = " << sum << " 입니다" << endl;
}

void LoopAdder::run() {
    read();              
    sum = calculate();   
    write();            
}

class WhileLoopAdder : public LoopAdder {
public:
    WhileLoopAdder(string name) : LoopAdder(name) {}

    int calculate() override {
        int total = 0;
        int i = getX();
        while (i <= getY()) {
            total += i;
            i++;
        }
        return total;
    }
};

class DoWhileLoopAdder : public LoopAdder {
public:
    DoWhileLoopAdder(string name) : LoopAdder(name) {}

    int calculate() override {
        int total = 0;
        int i = getX();
        do {
            total += i;
            i++;
        } while (i <= getY());
        return total;
    }
};

int main() {
    WhileLoopAdder whileLoop("While Loop");
    DoWhileLoopAdder doWhileLoop("Do while Loop");

    whileLoop.run();
    doWhileLoop.run();

    return 0;
}
