#include <iostream>  // ������� ���� ������� (cin, cout ����Ϸ��� �ʼ�)
using namespace std; // std:: �����ϰ� cin, cout �� �ٷ� ����ϱ� ����

// ��� �����͸� �����ϰ� ó���ϴ� Ŭ���� ����
class Statistics {
    int* data;     // ���� �����͸� ������ ���� �迭 ������ (int �迭�� ����Ŵ)
    int size;      // ���� ����� ������ ���� (��迡 �� �� �Էµƴ���)
    int capacity;  // ���� ������ �ִ� ���� (��: 100������ ����)

public:
    // ������: ��ü�� ������� �� �ڵ� ȣ���
    Statistics() {
        capacity = 100;               // ���� ������ �ִ� ���� 100���� ����
        size = 0;                     // ó������ �ƹ� �����͵� ������ 0
        data = new int[capacity];     // int�� �迭�� heap �޸𸮿� ���� �Ҵ�
        // new int[capacity]: ���� 100��¥�� �迭�� �������� �����ϰ� �� �ּҸ� data�� ����
    }

    // �Ҹ���: ��ü�� �Ҹ�� �� ȣ���. ���� �޸𸮸� ������ �� ���
    ~Statistics() {
        delete[] data; // new�� ���� �迭�� �ݵ�� delete[]�� �����ؾ� ��
        // delete[]: �迭 ����. ���� ������ delete, �迭�� delete[] ���
    }

    // operator>> ������ �����ε�
    // ����ڰ� '���� >> Statistics ��ü' ���·� �Է��� �� �ְ� ����
    friend Statistics& operator>>(int value, Statistics& stat) {
        // friend �Լ�: Ŭ���� �ܺ� �Լ����� private ���(data, size ��)�� ���� ������
        // ����� int >> ��ü ���´� Ŭ���� ��� �Լ��δ� �� ���� �� �ݵ�� friend �Լ����� ��

        if (stat.size < stat.capacity) {
            stat.data[stat.size++] = value;
            // data[size]�� �� ���� �� size 1 ����
        }
        return stat; // ���� ����� stat�� �״�� ��ȯ (���� �Է� ����)
    }

    // operator<< ������ �����ε�
    // '��� ��ü << ��� ���� ����' �������� ����� ���� ������ �� �ְ� ��
    friend Statistics& operator<<(Statistics& stat, int& avg) {
        if (stat.size == 0) {
            avg = 0; // �����Ͱ� �ϳ��� ������ ����� 0���� ó��
        }
        else {
            int sum = 0;
            for (int i = 0; i < stat.size; i++)
                sum += stat.data[i]; // �迭 ��ü�� ��ȸ�ϸ� �հ� ���
            avg = sum / stat.size;   // ��� = ���� / ����
            // ����: ���� �������̶� �Ҽ����� ������ (��: 6/4 = 1)
        }
        return stat; // ��ȯ�� ��� ��ü stat ��ü (���� ����)
    }

    // ~ ������ �����ε�
    // '~��谴ü' ���·� ȣ���ϸ� �����͸� ���� ������
    friend void operator~(Statistics& stat) {
        stat.size = 0; // ���� �迭 �޸𸮴� ���������� �����ʹ� 0���� ������
    }

    // ! ������ �����ε�
    // '!��谴ü' ���·� ��谡 ����ִ����� Ȯ�� (true�� ��� ����)
    friend bool operator!(Statistics& stat) {
        return stat.size == 0; // ��������� true, �ƴϸ� false
    }
};

int main() {
    Statistics stat; // ��踦 ������ Statistics ��ü ���� (������ ȣ���)

    if (!stat) // �����Ͱ� ��� �ִ��� Ȯ�� (operator! ȣ��)
        cout << "���� ��� �����Ͱ� �����ϴ�." << endl;

    int x[5]; // ���� 5���� ������ �迭 ���� (�̸� x, Ÿ���� int[5])
    // ���⼭ x�� �׳� ��� �Է��� �ޱ� ���� �߰� ���� ����.

    cout << "5���� ������ �Է��϶�>> ";
    for (int i = 0; i < 5; i++)
        cin >> x[i]; // ����ڷκ��� 5�� ���� �Է¹޾Ƽ� �迭�� ����

    for (int i = 0; i < 5; i++)
        x[i] >> stat;
    // ���� >> ��谴ü �������� ���� (������ >> �����ε���)

    100 >> stat; // �߰��� 100�� ��迡 �Է�
    200 >> stat; // �߰��� 200�� �Է�

    //~stat; // �ּ�ó��: �̰� �����ϸ� �����Ͱ� �� ������� ����� 0�� ��

    int avg;
    stat << avg; // ��� ��ü���� ��հ��� avg�� ���� (operator<< ȣ��)
    cout << "avg = " << avg << endl; // ��� ���

    return 0;
}

