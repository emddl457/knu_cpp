#pragma once
// Box.h (헤더 파일) - 클래스 선언만 정의한다. 

class Box 
{
    int width, height;   // 박스의 너비와 높이
    char fill;           // 박스를 채울 문자

public:
    Box(int w, int h);           // 생성자 (너비와 높이 초기화)
    void setFill(char f);        // 채움 문자 설정
    void setSize(int w, int h);  // 박스의 크기 설정
    void draw();                 // 박스 그리기
};

// pragma 대신 #infndef, #define, #endif를 사용해도 된다.