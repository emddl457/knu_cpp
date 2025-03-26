#pragma once // 헤더 파일 맨 위에 쓰는 전처리기 지시어. 이 파일은 한 번만 포함되도록 함, 중복 포함 방지!

class Add
{
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};

class Sub
{
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};

class Mul
{
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};

class Div
{
    int a, b;
public:
    void setValue(int x, int y);
    int calculate();
};

/*
* #pragma와 비슷한 기능을 반드시 다른 방식으로도 넣어야 한다!
* (예시)
#ifndef CALCULATOR_H
#define CALCULATOR_H
// (헤더 내용)
#endif

* #pragma once는 비표준이지만 대부분의 컴파일러에서 지원한다.
* #ifndef, #define, #endif를 사용하는 방법은 표준이다.
* 둘 중 하나를 선택해서 사용하면 된다!
* 둘 다 사용할 필요는 없다. 둘 다 사용하면 중복 포함 방지가 두 번 일어난다...
*/
