#include <iostream>
using namespace std;

// 제네릭 함수 biggest 정의
template <typename T>
T biggest(T arr[], int size) {
    T max = arr[0]; // 첫 번째 값을 기준으로 설정
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i]; // 더 큰 값이 있으면 max 갱신
        }
    }
    return max;
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    double y[] = { 2.5, 3.7, 1.9, 9.6 };
    char z[] = { 'a', 't', 'b', 'z' };

    // 다양한 배열에 대해 biggest 호출
    cout << "가장 큰 정수: " << biggest(x, 5) << endl;        // 100
    cout << "가장 큰 실수: " << biggest(y, 4) << endl;        // 9.6
    cout << "가장 큰 문자: " << biggest(z, 4) << endl;        // z

    return 0;
}
