#include <iostream>
using namespace std;

//BaseMemory Ŭ���� ����
class BaseMemory {
    char* mem;  //���� �����͸� �����ϴ� �迭
protected:
    //������: size ũ�⸸ŭ ���� �迭 ����
    BaseMemory(int size) { mem = new char[size]; }

    //�޸� ���ٿ� protected ����� ���ܵ�
    char read(int index) { return mem[index]; }
    void write(int index, char c) { mem[index] = c; } 
};

//�б� ���� �޸� ROM Ŭ���� (BaseMemory ���)
class ROM : public BaseMemory {
public:
    // �����ڿ��� �ʱⰪ ���ڿ� x�� mem �迭�� ����
    ROM(int size, char* x, int length) : BaseMemory(size) {
        for (int i = 0; i < length; i++) {
            write(i, x[i]);  //BaseMemory�� write()�� ����ؼ� �ʱ�ȭ
        }
    }

    //�ܺο��� ���� �� �ֵ��� ���� read �Լ� ����
    char read(int index) {
        return BaseMemory::read(index);  //protected read() ȣ��
    }
};

//�а� �� �� �ִ� �޸� RAM Ŭ���� (BaseMemory ���)
class RAM : public BaseMemory {
public:
    RAM(int size) : BaseMemory(size) {}  //������: size�� ����

    //�ܺο��� ���� �� �ֵ��� ���� read �Լ� ����
    char read(int index) {
        return BaseMemory::read(index);
    }

    //�ܺο��� �� �� �ֵ��� ���� write �Լ� ����
    void write(int index, char c) {
        BaseMemory::write(index, c);
    }
};

int main() {
    // ROM�� �� �ʱ� ���ڿ� �迭 (5����: "hello")
    char x[5] = { 'h', 'e', 'l', 'l', 'o' };

    // ROM ��ü ����: ũ�� 1024, �����ʹ� x, ���� 5
    ROM biosROM(1024 * 10, x, 5);

    // RAM ��ü ����: ũ�� 1024 * 1024
    RAM mainMemory(1024 * 1024);

    // ROM���� RAM���� ������ ���� (0~4���� �� 5�� ����)
    for (int i = 0; i < 5; i++) {
        mainMemory.write(i, biosROM.read(i));
    }

    // RAM�� ����� �����͸� ���
    for (int i = 0; i < 5; i++) {
        cout << mainMemory.read(i);
    }
    cout << endl;

    return 0;
}
