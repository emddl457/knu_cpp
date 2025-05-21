#include <iostream>
using namespace std;

// �߻� Ŭ����: ���� �������̽� ����
class AbstractGate {
protected:
    bool x, y; // �� �Է� ��

public:
    // �� �Է� ���� ����
    void set(bool x, bool y) {
        this->x = x;
        this->y = y;
    }

    //���� �Լ�: �ڽ� Ŭ������ �ݵ�� �����ؾ� ��
    virtual bool operation() = 0;
};

//AND ����Ʈ: �� �� true�� ���� true
class ANDGate : public AbstractGate {
public:
    bool operation() override {
        return x && y;
    }
};

//OR ����Ʈ: �� �� �ϳ��� true�� true
class ORGate : public AbstractGate {
public:
    bool operation() override {
        return x || y;
    }
};

//XOR ����Ʈ: �� ���� �ٸ� �� true
class XORGate : public AbstractGate {
public:
    bool operation() override {
        return x != y;
    }
};

int main() {
    //������ ����Ʈ ��ü ����
    ANDGate andGate;
    ORGate orGate;
    XORGate xorGate;

    //�Է°� ����
    andGate.set(true, false);
    orGate.set(true, false);
    xorGate.set(true, false);

    //�Ҹ� �� ��� �� true/false ���ڿ��� ���̰� ����
    cout.setf(ios::boolalpha);

    cout << andGate.operation() << endl; 
    cout << orGate.operation() << endl;  
    cout << xorGate.operation() << endl; 

    return 0;
}
