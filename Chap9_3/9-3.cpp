#include <iostream>
#include <string>
using namespace std;

//x~y���� ���ϴ� ���� ���� ����
class LoopAdder {
    string name;   //���� �̸�
    int x, y, sum; //���۰�, ����, �� ����
    void read();   //����� �Է� �޴� �Լ�
    void write();  //��� ��� �Լ�

protected:
    //���� �̸� �ʱ�ȭ
    LoopAdder(string name = "") { this->name = name; }

    //�Է°� x, y�� �����ϴ� getter �Լ�
    int getX() { return x; }
    int getY() { return y; }

    //���� ���� �Լ�: �ڽ� Ŭ�������� ���� ����
    virtual int calculate() = 0;

public:
    //���� �Լ�: �Է¹ް� ����ϰ� ���
    void run();
};

//����ڷκ��� �� �� �Է¹ޱ�
void LoopAdder::read() {
    cout << name << " : " << endl;
    cout << "ó�� ������ �ι�° ������ ���մϴ�. �� ���� �Է��ϼ��� >> ";
    cin >> x >> y;
}

// ��� ��� ���
void LoopAdder::write() {
    cout << x << "���� " << y << "������ �� = " << sum << " �Դϴ�" << endl;
}

//���� �帧�� �Է� ��� ���
void LoopAdder::run() {
    read();               //�Է� �ް�
    sum = calculate();    //�ڽ� Ŭ������ ��� �Լ� ����
    write();              //��� ���
}

//������ for������ ���ϴ� �ڽ� Ŭ���� ����
class ForLoopAdder : public LoopAdder {
public:
    //������: ���� �̸� ����
    ForLoopAdder(string name) : LoopAdder(name) {}

    //x���� y���� for������ �� ���
    int calculate() override {
        int total = 0;
        for (int i = getX(); i <= getY(); i++) {
            total += i;
        }
        return total;
    }
};

int main() {
    ForLoopAdder forLoop("For Loop"); //���� �̸��� �����Ͽ� ��ü ����
    forLoop.run(); //����
    return 0;
}
