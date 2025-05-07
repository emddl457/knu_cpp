#include <iostream>
using namespace std;

class Matrix {
    int m[2][2]; // 2행 2열짜리 정수형 배열 (행렬 역할)

public:
    // 기본 생성자: 인자가 없는 Matrix 객체를 만들 수 있게 함
    // 오류 E0291 ("기본 생성자 없음") 해결을 위해 추가함
    Matrix() {
        m[0][0] = 0; m[0][1] = 0;
        m[1][0] = 0; m[1][1] = 0;
    }

    // 4개의 정수를 받아서 2x2 행렬로 초기화하는 생성자
    Matrix(int a, int b, int c, int d) {
        m[0][0] = a; m[0][1] = b;
        m[1][0] = c; m[1][1] = d;
    }

    // 배열 대입 연산자 오버로딩
    // 시도: 배열 x를 행렬 b에 바로 대입하려고 했는데, 배열 대입은 안 되므로 오버로딩함
    // 교재처럼 b = x; 가 동작하도록 하기 위함
    void operator=(int x[4]) {
        m[0][0] = x[0];
        m[0][1] = x[1];
        m[1][0] = x[2];
        m[1][1] = x[3];
        // 시도해봤던 x = y; 는 C++에서 불가능 → for문으로 복사해야 함
    }

    // show() 멤버 함수: Matrix 내용을 { ... } 형식으로 출력
    void show() {
        cout << "Matrix = { ";
        for (int i = 0; i < 2; i++)         // 행 반복
            for (int j = 0; j < 2; j++)     // 열 반복
                cout << m[i][j] << " ";     // 한 칸씩 출력
        cout << "}" << endl;
    }

    // << 연산자 오버로딩: cout << matrix 객체 형태를 위해 프렌드 함수로 정의
    friend ostream& operator<<(ostream& os, Matrix& mat) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 2; j++)
                os << mat.m[i][j] << " ";
        return os;
    }
};

int main() {
    Matrix a(4, 3, 2, 1), b; // a는 정해진 값으로 초기화, b는 기본 생성자 호출됨

    int x[4], y[4] = { 1, 2, 3, 4 }; // y는 복사 원본, x는 복사 대상

    // 시도: x = y; 배열끼리는 직접 대입이 안 돼서 오류 발생 (E0137)
    // 그래서 아래처럼 for문으로 수동 복사함
    for (int i = 0; i < 4; i++)
        x[i] = y[i]; // 수동 복사로 해결

    b = x; // 배열 x를 행렬 b에 대입 → operator= 오버로딩이 작동

    // 여기서 x 배열을 출력해봤는데 교재 결과와 다르게 나와서, ( 1, 2, 3, 4 ) 형태로 출력됨....
    // 교재처럼 a 객체의 내용을 직접 출력하는 방식으로 수정하는 게 핵심임
    cout << a << endl; // a = (4, 3, 2, 1) 출력 → 교재와 일치
    b.show();          // b = {1 2 3 4} 출력 → 교재와 일치

    return 0;
}
