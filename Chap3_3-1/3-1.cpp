#include <iostream>
using namespace std;

class Tower //Tower라는 이름의 클래스를 정의한다.
{
private:
	int height; // 높이를 저장하는 멤버 '변수' 생성(private은 클래스 내부에서만 접근이 가능함)

public: // 기본 생성자로, 객체가 생성될 때 기본적으로 높이를 1로 설정한다.
	Tower()
	{
		height = 1; // (타워를 만들 때 쓸 방법 1), '생성자 함수'
	}

	Tower(int h) // 매개변수가 있는 생성자로, 사용자가 원하는 높이 값을 설정할 수 있다.
	{
		height = h; // 전달받은 h 값을 height에 저장한다. (타워를 만들 때 쓸 방법2), '생성자 함수'
	}

	int getHeight() // 현재 타워의 높이를 반환하는 '멤버' 함수이다. (타워의 높이를 알아보는 기능)
	{
		return height; // private 변수에 직접 접근할 수 없기 때문에 이 함수를 통해 값을 얻어야 한다.
	}
};

int main() // 프로그램 실행 시작
{
	Tower myTower; // 기본 생성자 호출 -> 높이가 1로 설정된다.
	Tower seoulTower(100); // 매개변수 있는 생성자를 호출 -> 높이가 100으로 설정됨

	//getHeight() 함수를 호출하여 높이를 출력함
	cout << "높이는 " << myTower.getHeight() << "미터" << endl;
	cout << "높이는 " << seoulTower.getHeight() << "미터" << endl;

	return 0; //프로그램 종료!

}

// Tower 는 클래스로서 '타워라는 건 이렇게 만든다!'라고 정의한 것과 같다. 그 안에는 데이터(height), 데이터를 다루는 함수들(getHeight)가 포함된다.