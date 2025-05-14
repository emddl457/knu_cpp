#include <iostream>
using namespace std;

// �������� �־��� BaseArray Ŭ����
class BaseArray {
private:
    int capacity;  //�迭�� �ִ� ũ�� (�뷮)
    int* mem;      //���� �����͸� ������ ���� �迭
protected:
    BaseArray(int capacity = 100) {  //������: capacity��ŭ �޸� �Ҵ�
        this->capacity = capacity;
        mem = new int[capacity];
    }
    ~BaseArray() { delete[] mem; }   //�Ҹ���: ���� �޸� ����

    //mem �迭�� index ��ġ�� val ����
    void put(int index, int val) { mem[index] = val; }

    //index ��ġ�� ���� ��ȯ
    int get(int index) { return mem[index]; }

    //�迭�� �뷮 ��ȯ
    int getCapacity() { return capacity; }
};

// BaseArray�� ��ӹ޾� ťó�� �����ϴ� MyQueue Ŭ����
class MyQueue : public BaseArray {
    int front;  // ť�� ���� �ε��� (dequeue�� ��ġ)
    int rear;   // ť�� ���� �ε��� (enqueue�� ��ġ)
    int size;   // ���� ť�� ����� ������ ����
public:
    MyQueue(int capacity) : BaseArray(capacity) {
        front = 0;  // ó������ �յ� 0
        rear = 0;   // ���� 0
        size = 0;   // �ʱ⿡�� ť�� ��� ����
    }

    // ť�� �����͸� �����ϴ� �Լ�
    void enqueue(int n) {
        if (size < getCapacity()) { // ť�� ������ ���� ���� ����
            put(rear, n);           // rear ��ġ�� �� ����
            rear = (rear + 1) % getCapacity(); // rear�� ���� ��ġ�� �̵� (���� ť)
            size++;                            // ���� ũ�� 1 ����
        }
    }

    // ť���� �����͸� �����ϰ� ��ȯ�ϴ� �Լ�
    int dequeue() {
        if (size == 0) return -1;  // ��������� -1 ��ȯ (������ġ)
        int val = get(front);      // front ��ġ�� ���� ������
        front = (front + 1) % getCapacity(); // front�� ���� ��ġ�� �̵�
        size--;  // ���� ũ�� 1 ����
        return val;
    }

    //���� ť�� ��� �ִ� ������ ���� ��ȯ
    int length() { return size; }

    //ť�� ��ü �뷮 ��ȯ (BaseArray�� getCapacity ȣ��)
    int capacity() { return getCapacity(); }
};

// ���� �Լ�
int main() {
    MyQueue mQ(100);  //ť �뷮 100¥�� ��ü ����
    int n;
    cout << "ť�� ������ 5���� ������ �Է��϶�>> ";

    //5���� ���� �Է¹޾� ť�� ����
    for (int i = 0; i < 5; i++) {
        cin >> n;
        mQ.enqueue(n);
    }

    //ť�� ���� ���
    cout << "ť�� �뷮: " << mQ.capacity() << ", ť�� ũ��: " << mQ.length() << endl;

    cout << "ť�� ���Ҹ� ������� �����Ͽ� ����Ѵ�>> ";
    while (mQ.length() != 0) {
        cout << mQ.dequeue() << " ";
    }

    //���������� ť�� ũ�� ��� (0�� �Ǿ�� ����)
    cout << endl << "ť�� ���� ũ��: " << mQ.length() << endl;

    return 0;
}
