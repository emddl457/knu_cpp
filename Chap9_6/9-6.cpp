#include <iostream>
using namespace std;

//�߻� Ŭ����: ���� �������̽� ����
class AbstractStack {
public:
    //���ÿ� ���� n�� push. �� �� ������ false
    virtual bool push(int n) = 0;

    //���ÿ��� ���� �ϳ� pop. n�� ����. ��������� false
    virtual bool pop(int& n) = 0;

    //���� ���ÿ� ����� ���� ���� ��ȯ
    virtual int size() = 0;
};

//������ ���� ���� Ŭ����
class IntStack : public AbstractStack {
private:
    int data[100];   //���� ũ�� �迭�� ���� ���� (�ִ� 100��)
    int top;         //������ �ֻ�� �ε���

public:
    //������: ���� ����� ���·� ����
    IntStack() {
        top = -1;
    }

    //push: ���ÿ� n�� �߰�. �� ���� ����
    bool push(int n) override {
        if (top >= 99) return false;  //������ ���� á�� ���
        data[++top] = n;
        return true;
    }

    //pop: top�� �ִ� �� ������. ������� ����
    bool pop(int& n) override {
        if (top < 0) return false;  //������ ����� ���
        n = data[top--];
        return true;
    }

    //���� ���ÿ� ����ִ� ���� ��
    int size() override {
        return top + 1;
    }
};

int main() {
    IntStack stack;

    //���ÿ� �� 10, 20, 30�� push
    stack.push(10);
    stack.push(20);
    stack.push(30);

    cout << "���� ũ��: " << stack.size() << endl;

    int value;
    while (stack.pop(value)) {
        cout << "pop: " << value << endl;
    }

    cout << "������ ��� ��������ϴ�. ���� ũ��: " << stack.size() << endl;

    return 0;
}
