#include <iostream>
using namespace std;

//�������� ������ BaseArray Ŭ����
class BaseArray {
private:
    int capacity;  //�迭�� �ִ� �뷮
    int* mem;      //�������� �Ҵ�� �迭
protected:
    BaseArray(int capacity = 100) {
        this->capacity = capacity;
        mem = new int[capacity];  //������ ũ��� ���� �迭 ����
    }

    ~BaseArray() { delete[] mem; }  //�Ҹ��ڿ��� �޸� ����

    void put(int index, int val) { mem[index] = val; }  //�迭 �� ����
    int get(int index) { return mem[index]; }           //�迭 �� ��ȯ
    int getCapacity() { return capacity; }              //�迭 �뷮 ��ȯ
};

//���� �ڷᱸ��ó�� �����ϴ� MyStack Ŭ���� (BaseArray ���)
class MyStack : public BaseArray {
    int top;  //������ ���� ��� ���� (���� push�� ��ġ)
public:
    MyStack(int capacity) : BaseArray(capacity) {
        top = 0; //���� ó������ ��� ���� (top�� 0���� ����)
    }

    // ���ÿ� �����͸� �����ϴ� �Լ�
    void push(int n) {
        if (top < getCapacity()) {    //�뷮 �ʰ��� �ƴ� ��츸 ����
            put(top, n);              //top ��ġ�� �� ����
            top++;                    //top 1 ����
        }
    }

    //���ÿ��� �����͸� ������ �Լ� (���� �ֱ� ��)
    int pop() {
        if (top == 0) return -1; //������ ��������� -1 ��ȯ
        top--; //top ���� ��
        return get(top); //���ҵ� ��ġ�� �� ��ȯ
    }

    // ���� ���ÿ� ���� ��� ���� ��ȯ
    int length() { return top; }

    // ���� ��ü �뷮 ��ȯ
    int capacity() { return getCapacity(); }
};

// ���� �Լ�
int main() {
    MyStack mStack(100);  // �뷮 100¥�� ���� ��ü ����
    int n;

    cout << "���ÿ� ������ 5���� ������ �Է��϶�>> ";
    for (int i = 0; i < 5; i++) {
        cin >> n;               
        mStack.push(n);        
    }

    // ���� ���� ���
    cout << "���ÿ뷮: " << mStack.capacity() << ", ����ũ��: " << mStack.length() << endl;

    cout << "������ ��� ���Ҹ� ���Ͽ� ����Ѵ�>> ";
    while (mStack.length() != 0) {
        cout << mStack.pop() << " ";  // �ϳ��� ������ ���
    }

    cout << endl << "������ ���� ũ�� : " << mStack.length() << endl;

    return 0;
}
