#include <iostream>
using namespace std;

// 템플릿 함수 정의
template <typename T>
bool search(T key, T arr[], int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == key) {
            return true;  // 찾았을 경우
        }
    }
    return false;         // 못 찾았을 경우
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };

    if (search(100, x, 5))
        cout << "100이 배열 x에 포함되어 있다" << endl;
    else
        cout << "100이 배열 x에 포함되어 있지 않다" << endl;

    if (search(7, x, 5))
        cout << "7이 배열 x에 포함되어 있다" << endl;
    else
        cout << "7이 배열 x에 포함되어 있지 않다" << endl; 

    
    char c[] = { 'a', 'e', 'i', 'o', 'u' };
    if (search('i', c, 5))
        cout << "'i'가 포함되어 있음" << endl;
    else
        cout << "'i'가 포함되어 있지 않음" << endl;

    return 0;
}
