#include <iostream>
using namespace std;

// ���׸� �Լ� biggest ����
template <typename T>
T biggest(T arr[], int size) {
    T max = arr[0]; // ù ��° ���� �������� ����
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // �� ū ���� ������ max ����
        }
    }
    return max;
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    double y[] = { 2.5, 3.7, 1.9, 9.6 };
    char z[] = { 'a', 't', 'b', 'z' };

    // �پ��� �迭�� ���� biggest ȣ��
    cout << "���� ū ����: " << biggest(x, 5) << endl;        // 100
    cout << "���� ū �Ǽ�: " << biggest(y, 4) << endl;        // 9.6
    cout << "���� ū ����: " << biggest(z, 4) << endl;        // z

    return 0;
}
