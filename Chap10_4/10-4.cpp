#include <iostream>
using namespace std;

// ���ø� �Լ� ����
template <typename T>
bool search(T key, T arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;  // ã���� ���
        }
    }
    return false;         // �� ã���� ���
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };

    if (search(100, x, 5))
        cout << "100�� �迭 x�� ���ԵǾ� �ִ�" << endl;
    else
        cout << "100�� �迭 x�� ���ԵǾ� ���� �ʴ�" << endl;

    if (search(7, x, 5))
        cout << "7�� �迭 x�� ���ԵǾ� �ִ�" << endl;
    else
        cout << "7�� �迭 x�� ���ԵǾ� ���� �ʴ�" << endl; 

    
    char c[] = { 'a', 'e', 'i', 'o', 'u' };
    if (search('i', c, 5))
        cout << "'i'�� ���ԵǾ� ����" << endl;
    else
        cout << "'i'�� ���ԵǾ� ���� ����" << endl;

    return 0;
}
