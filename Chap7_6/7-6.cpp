#include <iostream>
using namespace std;

class Matrix {
    int m[4]; // 1�� 4��ó�� ���� (4ĭ¥�� �迭)

public:
    // ������: 4�� ������ �ʱ�ȭ
    Matrix(int a, int b, int c, int d) {
        m[0] = a; m[1] = b; m[2] = c; m[3] = d;
    }

    // show(): �� ���
    void show() {
        cout << "Matrix = { ";
        for (int i = 0; i < 4; i++)
            cout << m[i] << " ";
        cout << "}" << endl;
    }

    // += ������ �����ε� (�ڱ� �ڽſ� ����)
    Matrix& operator+=(const Matrix& b) {
        for (int i = 0; i < 4; i++)
            m[i] += b.m[i];
        return *this;
    }

    // + ������ �����ε� (�� ��� ���ؼ� �� ��ü ��ȯ)
    friend Matrix operator+(const Matrix& a, const Matrix& b) {
        return Matrix(
            a.m[0] + b.m[0],
            a.m[1] + b.m[1],
            a.m[2] + b.m[2],
            a.m[3] + b.m[3]
        );
    }

    // == ������ �����ε� (������ ��)
    friend bool operator==(const Matrix& a, const Matrix& b) {
        for (int i = 0; i < 4; i++) {
            if (a.m[i] != b.m[i])
                return false;
        }
        return true;
    }
};

int main() {
    // a�� b ����
    Matrix a(1, 2, 3, 4), b(2, 3, 4, 5), c(0, 0, 0, 0);

    c = a + b;   // a�� b ���� ����� c�� ����
    a += b;      // a�� b�� ���� ����� �ٽ� a�� ����

    a.show();    
    b.show();    
    c.show();    

    if (a == c)
        cout << "a and c are the same" << endl;

    return 0;
}


// +=�� ����Լ�, �ڱ��ڽ�(a += b)
// +�� ������ �Լ�. �ڱ��ڽ��� ������ ���ο� ��ü ����(c = a + b)
// ==�� ������ �Լ�. �� ��ü�� ���ؼ� ������ true, �ٸ��� false ��ȯ(if (a == c))
// show()�� ����Լ�. ����� ȭ�鿡 ����ϴ� ���.