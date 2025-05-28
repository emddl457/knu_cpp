#include <iostream>
using namespace std;

// 템플릿 함수 정의
template <typename T>
void reverseArray(T* arr, int size) {
    for (int i = 0; i < size / 2; i++) {
        T temp = arr[i];                   // 앞쪽 값을 임시 보관
        arr[i] = arr[size - 1 - i];        // 뒤쪽 값을 앞쪽에 복사
        arr[size - 1 - i] = temp;          // 임시 보관한 앞쪽 값을 뒤쪽에 대입
    }
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    reverseArray(x, 5);

    for (int i = 0; i < 5; i++)
        cout << x[i] << ' ';             
    cout << endl;

    // 실수 배열 테스트
    double y[] = { 1.1, 2.2, 3.3 };
    reverseArray(y, 3);
    for (int i = 0; i < 3; i++)
        cout << y[i] << ' ';             
    cout << endl;

    return 0;
}
