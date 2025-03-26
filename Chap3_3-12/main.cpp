#include <iostream>
#include "Ram.h"
using namespace std;

int main()
{
    Ram ram;                    

    //  Ram ram;은 Ram 객체를 "스택(stack)"에 생성하는 것을 의미한다. 그런데 C6262라는 경고가 발생했다.
	// 물론 프로그램을 실행하는 데에는 문제가 없지만, 이 경고는 "스택(stack)에 큰 객체를 생성하면 프로그램이 느려질 수 있다"는 경고였다.
	// 그래서 이 경고를 없애기 위해서는 Ram 객체를 "힙(heap)"에 생성하도록 수정해야 한다.
	// 이것 대신 Ram* ram = new Ram();로 수정하면 된다. 그러면 Ram 객체는 "힙(heap)"에 생성되어 더 큰 메모리 공간을 사용할 수 있다.
	// 그리고 delete ram;을 통해 Ram 객체를 제거해야 한다. (사용 후 수동으로 메모리 해제)
    // new Ram으로 수정할 경우, delete ram;을 깜빡하면 메모리 누수가 발생할 수 있으니 주의할 것!
	// 그러나 이 프로그램은 Ram 객체를 생성한 후 바로 사용하고 종료하기 때문에 우선 그대로 두기로 결정했다.


    ram.write(100, 20);          // 100번지에 20 저장
    ram.write(101, 30);          // 101번지에 30 저장

    // 100번지 + 101번지 값을 더해서 102번지에 저장
    char res = ram.read(100) + ram.read(101);
    ram.write(102, res);

    // 102번지 값 출력 (char → int로 출력)
    cout << "102 번지의 값 = " << (int)ram.read(102) << endl;

    return 0;  // Ram 소멸자 호출 후, "메모리 제거됨" 출력됨
}