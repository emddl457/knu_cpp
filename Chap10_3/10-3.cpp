#include <iostream>
using namespace std;

// ���ø� �Լ� ����
template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];                   // ���� ���� �ӽ� ����
        arr[i] = arr[size - 1 - i];        // ���� ���� ���ʿ� ����
        arr[size - 1 - i] = temp;          // �ӽ� ������ ���� ���� ���ʿ� ����
    }
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    reverseArray(x, 5);

    for (int i = 0; i < 5; i++)
        cout << x[i] << ' ';             
    cout << endl;

    // �Ǽ� �迭 �׽�Ʈ
    double y[] = { 1.1, 2.2, 3.3 };
    reverseArray(y, 3);
    for (int i = 0; i < 3; i++)
        cout << y[i] << ' ';             
    cout << endl;

    return 0;
}
