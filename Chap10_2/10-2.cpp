#include <iostream>
using namespace std;

template <typename T>
bool equalArrays(T a[], T b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false; //�ϳ��� �ٸ��� false ��ȯ
        }
    }
    return true; //���� ������ true ��ȯ
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    int y[] = { 1, 10, 100, 5, 4 };
    int z[] = { 1, 10, 100, 5, 9 };

    if (equalArrays(x, y, 5))
        cout << "x�� y�� ����" << endl;
    else
        cout << "x�� y�� �ٸ���" << endl;

    if (equalArrays(x, z, 5))
        cout << "x�� z�� ����" << endl;
    else
        cout << "x�� z�� �ٸ���" << endl;

    double a[] = { 1.1, 2.2, 3.3 };
    double b[] = { 1.1, 2.2, 3.3 };

    if (equalArrays(a, b, 3))
        cout << "a�� b�� ����" << endl;
    else
        cout << "a�� b�� �ٸ���" << endl;

    return 0;
}
