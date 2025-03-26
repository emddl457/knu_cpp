#pragma once

class Ram 
{
    char mem[100 * 1024];  // 100KB 메모리 공간 (char는 1바이트)
    int size;              // 메모리의 전체 크기를 저장

public:
    Ram();                               // 생성자: 메모리 초기화
    ~Ram();                              // 소멸자: 메모리 해제 메시지 출력
    char read(int address);              // 주어진 주소의 값을 읽어 반환
    void write(int address, char value); // 주어진 주소에 값을 저장
};
