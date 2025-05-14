#include <iostream>
using namespace std;

//BaseMemory 클래스 정의
class BaseMemory {
    char* mem;  //문자 데이터를 저장하는 배열
protected:
    //생성자: size 크기만큼 동적 배열 생성
    BaseMemory(int size) { mem = new char[size]; }

    //메모리 접근용 protected 멤버로 남겨둠
    char read(int index) { return mem[index]; }
    void write(int index, char c) { mem[index] = c; } 
};

//읽기 전용 메모리 ROM 클래스 (BaseMemory 상속)
class ROM : public BaseMemory {
public:
    // 생성자에서 초기값 문자열 x를 mem 배열에 복사
    ROM(int size, char* x, int length) : BaseMemory(size) {
        for (int i = 0; i < length; i++) {
            write(i, x[i]);  //BaseMemory의 write()를 사용해서 초기화
        }
    }

    //외부에서 읽을 수 있도록 공개 read 함수 제공
    char read(int index) {
        return BaseMemory::read(index);  //protected read() 호출
    }
};

//읽고 쓸 수 있는 메모리 RAM 클래스 (BaseMemory 상속)
class RAM : public BaseMemory {
public:
    RAM(int size) : BaseMemory(size) {}  //생성자: size만 전달

    //외부에서 읽을 수 있도록 공개 read 함수 제공
    char read(int index) {
        return BaseMemory::read(index);
    }

    //외부에서 쓸 수 있도록 공개 write 함수 제공
    void write(int index, char c) {
        BaseMemory::write(index, c);
    }
};

int main() {
    // ROM에 들어갈 초기 문자열 배열 (5글자: "hello")
    char x[5] = { 'h', 'e', 'l', 'l', 'o' };

    // ROM 객체 생성: 크기 1024, 데이터는 x, 길이 5
    ROM biosROM(1024 * 10, x, 5);

    // RAM 객체 생성: 크기 1024 * 1024
    RAM mainMemory(1024 * 1024);

    // ROM에서 RAM으로 데이터 복사 (0~4까지 총 5개 문자)
    for (int i = 0; i < 5; i++) {
        mainMemory.write(i, biosROM.read(i));
    }

    // RAM에 복사된 데이터를 출력
    for (int i = 0; i < 5; i++) {
        cout << mainMemory.read(i);
    }
    cout << endl;

    return 0;
}
