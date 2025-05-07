#include <iostream>
using namespace std;

class Matrix {
    int m[4]; // 1행 4열처럼 동작 (4칸짜리 배열)

public:
    // 생성자: 4개 값으로 초기화
    Matrix(int a, int b, int c, int d) {
        m[0] = a; m[1] = b; m[2] = c; m[3] = d;
    }

    // show(): 값 출력
    void show() {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; i++)
            cout << m[i] << " ";
        cout << "}" << endl;
    }

    // += 연산자 오버로딩 (자기 자신에 더함)
    Matrix& operator+=(const Matrix& b) {
        for (int i = 0; i < 4; i++)
            m[i] += b.m[i];
        return *this;
    }

    // + 연산자 오버로딩 (두 행렬 더해서 새 객체 반환)
    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        return Matrix(
            a.m[0] + b.m[0],
            a.m[1] + b.m[1],
            a.m[2] + b.m[2],
            a.m[3] + b.m[3]
        );
    }

    // == 연산자 오버로딩 (같은지 비교)
    friend bool operator==(const Matrix& a, const Matrix& b) {
        for (int i = 0; i < 4; i++) {
            if (a.m[i] != b.m[i])
                return false;
        }
        return true;
    }
};

int main() {
    // a와 b 정의
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c(0, 0, 0, 0);

    c = a + b;   // a와 b 더한 결과를 c에 저장
    a += b;      // a에 b를 더한 결과를 다시 a에 저장

    a.show();    
    b.show();    
    c.show();    

    if (a == c)
        cout << "a and c are the same" << endl;

    return 0;
}


// +=는 멤버함수, 자기자신(a += b)
// +는 프렌드 함수. 자기자신을 포함한 새로운 객체 만듦(c = a + b)
// ==는 프렌드 함수. 두 객체를 비교해서 같으면 true, 다르면 false 반환(if (a == c))
// show()는 멤버함수. 행렬을 화면에 출력하는 기능.