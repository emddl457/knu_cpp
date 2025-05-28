#include <iostream>
using namespace std;

// ���ø� concat �Լ� ����
template <typename T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    T* result = new T[sizea + sizeb]; // �� �迭 ���� �Ҵ�

    for (int i = 0; i < sizea; i++) {
        result[i] = a[i];             // ù ��° �迭 ����
    }
    for (int i = 0; i < sizeb; i++) {
        result[sizea + i] = b[i];     // �� ��° �迭 �̾���̱�
    }

    return result;
}

int main() {
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5 };
    int* result = concat(a, 3, b, 2);

    cout << "int �迭 ���� ���: ";
    for (int i = 0; i < 5; i++) {
        cout << result[i] << ' ';     // ���: 1 2 3 4 5
    }
    cout << endl;
    delete[] result;                  // ���� �Ҵ� ����

    char c1[] = { 'H', 'e', 'l' };
    char c2[] = { 'l', 'o' };
    char* result2 = concat(c1, 3, c2, 2);

    cout << "char �迭 ���� ���: ";
    for (int i = 0; i < 5; i++) {
        cout << result2[i];          
    }
    cout << endl;
    delete[] result2;

    return 0;
}
