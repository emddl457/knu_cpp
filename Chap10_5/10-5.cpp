#include <iostream>
using namespace std;

// 템플릿 concat 함수 정의
template <typename T>
T* concat(T a[], int sizea, T b[], int sizeb) {
    T* result = new T[sizea + sizeb]; // 새 배열 동적 할당

    for (int i = 0; i < sizea; i++) {
        result[i] = a[i];             // 첫 번째 배열 복사
    }
    for (int i = 0; i < sizeb; i++) {
        result[sizea + i] = b[i];     // 두 번째 배열 이어붙이기
    }

    return result;
}

int main() {
    int a[] = { 1, 2, 3 };
    int b[] = { 4, 5 };
    int* result = concat(a, 3, b, 2);

    cout << "int 배열 연결 결과: ";
    for (int i = 0; i < 5; i++) {
        cout << result[i] << ' ';     // 출력: 1 2 3 4 5
    }
    cout << endl;
    delete[] result;                  // 동적 할당 해제

    char c1[] = { 'H', 'e', 'l' };
    char c2[] = { 'l', 'o' };
    char* result2 = concat(c1, 3, c2, 2);

    cout << "char 배열 연결 결과: ";
    for (int i = 0; i < 5; i++) {
        cout << result2[i];          
    }
    cout << endl;
    delete[] result2;

    return 0;
}
