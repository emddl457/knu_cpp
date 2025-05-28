#include <iostream>
using namespace std;

template <typename T>
T* remove(T src[], int sizeSrc, T minus[], int sizeMinus, int& retSize) {
    T* temp = new T[sizeSrc];
    int count = 0;

    for (int i = 0; i < sizeSrc; i++) {
        bool found = false;
        for (int j = 0; j < sizeMinus; j++) {
            if (src[i] == minus[j]) {
                found = true;
                break;
            }
        }
        if (!found) {
            temp[count++] = src[i];  //���ܵ��� ���� �׸� �����ϱ�
        }
    }

    //��� ũ�� ����
    retSize = count;

    //��Ȯ�� ũ��� �� �迭 ����
    T* result = new T[retSize];
    for (int i = 0; i < retSize; i++) {
        result[i] = temp[i];
    }

    delete[] temp;  //�ӽ� �迭 ����
    return result;
}

int main() {
    int src[] = { 1, 10, 100, 5, 4 };
    int minus[] = { 10, 4 };
    int newSize;

    int* filtered = remove(src, 5, minus, 2, newSize);

    cout << "���ŵ� ��� �迭: ";
    for (int i = 0; i < newSize; i++) {
        cout << filtered[i] << ' ';  // ���: 1 100 5
    }
    cout << endl;
    delete[] filtered;

   
    char src2[] = { 'a', 'b', 'c', 'd' };
    char minus2[] = { 'b', 'd' };
    int charSize;

    char* filtered2 = remove(src2, 4, minus2, 2, charSize);
    cout << "���� �迭 ���� ���: ";
    for (int i = 0; i < charSize; i++) {
        cout << filtered2[i] << ' ';  
    }
    cout << endl;
    delete[] filtered2;

    return 0;
}
