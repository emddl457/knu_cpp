#include <iostream>     // cout, endl �� ǥ�� ����� ����� ���� ���� ���
#include <algorithm>    // sort �Լ� ����Ϸ��� �ʿ��� (C++ ǥ�� ���̺귯��)
using namespace std;    // std:: �����ϰ� cout �� ���� ���� ����

class SortedArray {
    int size;  // ���� �迭�� ��� �ִ� ��� ���� (����)
    int* p;    // ������ ������: ���� �迭�� ����Ŵ (���� ������ ���� �迭 �ּ�)

    void sort() {
        // ���� ���� �迭 p�� �������� �����ϴ� ��� �Լ�
        // p: ���� ��� �迭, size: ��� ����
        std::sort(p, p + size);
        // p���� p + size �������� (��, �迭 ��ü)�� �������� ����
    }

public:
    SortedArray() {
        // �⺻ ������: �ƹ� ���� �� ���� ��� �ִ� �迭 ����
        p = NULL;  // �����͸� �ϴ� �ƹ� �͵� �� ����Ű���� ��
        size = 0;  // �迭 ũ�⵵ 0
    }

    SortedArray(int arr[], int size) {
        // ���� �迭�� ���޹޾� SortedArray ��ü�� �����ϴ� ������
        this->size = size;          // ���޹��� ũ�⸦ ��� ������ ����
        p = new int[size];          // ���� �迭 ���� �Ҵ� (heap ������ ���� ����)
        for (int i = 0; i < size; i++)
            p[i] = arr[i];          // ���� �迭 ���� �� �迭�� ����
        sort();                     // ������ �迭�� �������� ����
    }

    SortedArray(SortedArray& src) {
        // ���� ������: ���� SortedArray ��ü�� �����ؼ� �� ��ü ���� �� ȣ���
        this->size = src.size;      // ���� ����� size ����
        p = new int[size];          // �迭 ���� �Ҵ�
        for (int i = 0; i < size; i++)
            p[i] = src.p[i];        // �迭 ���� ����
        // sort()�� �̹� ���ĵ� �����Ƿ� �ٽ� �� �ص�...�ǰ���?
    }

    ~SortedArray() {
        // �Ҹ���: ��ü�� ����� �� ȣ���. ���� �Ҵ�� �迭�� �����ؾ� �޸� ���� �� ����
        delete[] p;  // new�� ���� �迭�� delete[]�� �����ؾ� ��
    }

    // + ������ �����ε�: �� SortedArray�� ���ļ� �� SortedArray ��ȯ
    SortedArray operator+(SortedArray& op2) {
        int* temp = new int[size + op2.size];  // �� �迭 ��ģ ũ�⸸ŭ ���ο� �迭 ����

        // ù ��° �迭 ����
        for (int i = 0; i < size; i++)
            temp[i] = p[i];

        // �� ��° �迭 ����
        for (int i = 0; i < op2.size; i++)
            temp[size + i] = op2.p[i];

        // temp �迭�� ���ĵ� SortedArray�� ��ȯ (�ڵ� ���ĵ�)
        SortedArray result(temp, size + op2.size);

        delete[] temp;  // �ӽ÷� ��� temp �迭�� �� �̻� �ʿ� ������ ����

        return result;  // ���� ������� �迭�� ���纻���� ����
    }

    // = ������ �����ε�: �ٸ� ��ü�� ������ �����ؼ� ����� �� �� ���
    SortedArray& operator=(const SortedArray& op2) {
        // ������ �Ҵ�Ǿ� �ִ� �迭�� �ִٸ� �޸� ����
        if (p != NULL)
            delete[] p;

        size = op2.size;            // �� �迭 ũ�� ����
        p = new int[size];          // �� �迭 �޸� �Ҵ�
        for (int i = 0; i < size; i++)
            p[i] = op2.p[i];        // �迭 ���� ����

        return *this;               // �ڱ� �ڽ� ���� ��ȯ (���� ���� ����)
    }

    void show() {
        // �迭 ���� ����ϴ� ��� �Լ�
        for (int i = 0; i < size; i++)
            cout << p[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[] = { 3, 5, 1 };           // ���ĵ��� ���� �迭 a
    int b[] = { 2, 4 };              // ���ĵ��� ���� �迭 b

    SortedArray x(a, 3);           // �迭 a�κ��� ��ü x ���� �� ���ο��� �ڵ� ���ĵ�
    SortedArray y(b, 2);           // �迭 b�κ��� ��ü y ����

    SortedArray z;                 // �⺻ ������ ȣ�� (����ִ� �迭)
    z = x + y;                     // x�� y�� ��ģ ���ο� �迭�� z�� ����

    z.show();                      // ������������ ���ĵ� �迭 Ȯ��

    return 0;
}
