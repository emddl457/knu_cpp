#include <iostream>
#include "Box.h"
using namespace std;

int main() 
{
    Box b(10, 2);      // 너비 10, 높이 2인 박스 객체 생성 (기본 채움문자 '*')
    b.draw();          // 첫 번째 박스 출력 (10x2, *로 채움)

    cout << endl;

    b.setSize(7, 4);   // 박스의 크기를 7x4로 변경
    b.setFill('^');    // 박스를 '^' 문자로 채우도록 설정
    b.draw();          // 두 번째 박스 출력 (7x4, ^로 채움)

    return 0;
}