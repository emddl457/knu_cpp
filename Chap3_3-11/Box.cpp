#include <iostream>
#include "Box.h"
using namespace std;

// 생성자: 너비와 높이를 초기화하고 채움 문자는 '*'로 초기 설정
Box::Box(int w, int h) 
{
    setSize(w, h);
    fill = '*';
}

// 채움 문자 변경 함수
void Box::setFill(char f) 
{
    fill = f;
}

// 크기 변경 함수
void Box::setSize(int w, int h) 
{
    width = w;
    height = h;
}

// 박스를 그리는 함수
void Box::draw() {
    for (int n = 0; n < height; n++) 
    {
        for (int m = 0; m < width; m++)
            cout << fill; // 한 줄에 width만큼 fill 문자 출력
        cout << endl;     // 줄바꿈 (한 줄 끝나면 다음 줄로)
    }
}