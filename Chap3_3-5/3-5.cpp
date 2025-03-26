#include <iostream>
#include <cstdlib>  // rand(), srand(), RAND_MAX (랜덤 함수들)
#include <ctime>    // time() (시간 함수) 
using namespace std; 

class Random 
{
public:
	Random() // 생성자
    {
		// 현재 시간을 기반으로 seesd 설정 (매번 다른 랜덤 숫자 생성) rand() 함수는 seed 값이 같으면 같은 랜덤 수 생성
		srand((unsigned)time(0)); // <ctime> 안에 있는 함수
    }

    // 0에서 RAND_MAX(32767) 사이의 랜덤 정수 반환
    int next() 
    {
		return rand(); // <cstdlib> 안에 있는 함수!
    }

    // a 이상 b 이하 범위의 랜덤 정수 반환
	int nextInRange(int a, int b) // a, b: 범위, a 이상 b 이하의 랜덤 정수 반환, a, b는 포함
    {
		// (b - a + 1): 범위 크기, 0부터 시작하므로 +1 해줘야 함
		// rand() % 범위 + a: 원하는 범위 안에서 랜덤 수 만들기, a를 더해주는 이유는 a부터 시작하기 위해서
        return rand() % (b - a + 1) + a;
    }
};

// main 함수
int main() 
{
	Random r;  // Random 객체 생성

    // 첫 번째 출력: 0부터 RAND_MAX까지의 랜덤 정수 10개 출력
    cout << "-- 0에서 " << RAND_MAX << " 까지의 랜덤 정수 10개 --" << endl;
	for (int i = 0; i < 10; i++)  // 10번 반복, 10개 출력, 0~9
    {
        int n = r.next();  // 랜덤 정수 생성
		cout << n << ' '; // 생성된 랜덤 정수 출력, 띄어쓰기로 구분
    }

	cout << endl << endl; // 줄바꿈 두 번

    // 두 번째 출력: 2부터 4까지의 랜덤 정수 10개 출력
	cout << "-- 2에서 4 까지의 랜덤 정수 10개 --" << endl; // 2~4 사이 랜덤 정수 10개 출력
	for (int i = 0; i < 10; i++) // 10번 반복, 10개 출력, 0~9

    {
        int n = r.nextInRange(2, 4);  // 2~4 사이 랜덤 수
		cout << n << ' '; // 생성된 랜덤 정수 출력, 띄어쓰기로 구분
    }

	cout << endl; // 줄바꿈
    return 0;
}
