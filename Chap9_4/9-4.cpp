#include <iostream>
#include <string>
using namespace std;

//�̹� �־��� LoopAdder �߻� Ŭ����
class LoopAdder {
    string name;
    int x, y, sum;
    void read();
    void write();

protected:
    LoopAdder(string name = "") { this->name = name; }

    int getX() { return x; }
    int getY() { return y; }

    virtual int calculate() = 0; //�ڽ� Ŭ������ ���� �����ؾ� �ϴ� �Լ�

public:
    void run();
};

void LoopAdder::read() {
    cout << name << " : " << endl;
    cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
    cin >> x >> y;
}

void LoopAdder::write() {
    cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
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
