#include <iostream>
using namespace std;

template <typename T>
bool equalArrays(T a[], T b[], int size) {
    for (int i = 0; i < size; i++) {
        if (a[i] != b[i]) {
            return false; //하나라도 다르면 false 반환
        }
    }
    return true; //전부 같으면 true 반환
}

int main() {
    int x[] = { 1, 10, 100, 5, 4 };
    int y[] = { 1, 10, 100, 5, 4 };
    int z[] = { 1, 10, 100, 5, 9 };

    if (equalArrays(x, y, 5))
        cout << "x와 y는 같다" << endl;
    else
        cout << "x와 y는 다르다" << endl;

    if (equalArrays(x, z, 5))
        cout << "x와 z는 같다" << endl;
    else
        cout << "x와 z는 다르다" << endl;

    double a[] = { 1.1, 2.2, 3.3 };
    double b[] = { 1.1, 2.2, 3.3 };

    if (equalArrays(a, b, 3))
        cout << "a와 b는 같다" << endl;
    else
        cout << "a와 b는 다르다" << endl;

    return 0;
}
