#include <iostream>
#include "Ram.h"
using namespace std;

// 생성자: 메모리 배열을 0으로 초기화하고 크기를 설정
Ram::Ram() 
{
    for (int i = 0; i < 100 * 1024; i++)
		mem[i] = 0; // 100*1024 = 102400, 100KB의 메모리 공간을 0으로 초기화한다.
	size = 100 * 1024; // 100KB의 메모리 공간을 size에 저장한다.
}

// 소멸자: 메모리 제거 메시지 출력
Ram::~Ram() 
{
    cout << "메모리 제거됨" << endl;
}

// 메모리는 주소에 어떤 값을 저장하고, 다시 읽는 작업을 계속 반복한다.
// read와 write는 주어진 주소에 값을 읽고 쓰는 함수!
// 주소 adress에 값 value를 저장하거나, 주소 adress의 값을 반환한다.

char Ram::read(int address)

{
    return mem[address];
}

// 주소와 값을 받아 해당 위치에 저장
void Ram::write(int address, char value) 
{
    mem[address] = value;
}