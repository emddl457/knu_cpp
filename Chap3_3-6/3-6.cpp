#include <iostream>
#include <cstdlib>  // rand(), srand(), RAND_MAX
#include <ctime>    // time()
using namespace std;

class EvenRandom // 짝수만 반환하는 랜덤 클래스 생성
{
public: // 생성자: seed 설정 (이전 5번 문제에서의 Random 클래스와 동일하다)
    EvenRandom() 
    {
		srand((unsigned)time(0)); // 현재 시간으로 시드 설정, 0은 1970년 1월 1일 0시 0분 0초부터 현재까지의 초를 반환한다.
    }

    // 기존 Random 클래스와 다른 점은 next(): 0 ~ RAND_MAX 사이의 "짝수" 랜덤 정수 반환한다는 것!!
    int next() 
    {
        int r;
        do 
        {
            r = rand();           // 랜덤 수 생성
        } while (r % 2 != 0);     // !! 홀수면 다시 반복하고, 짝수일 때만 반환
        return r;
    }

    int nextInRange(int a, int b) // 기존 nextInRange와 차이점 하나 더!! nextInRange(a, b): a 이상 b 이하의 "짝수" 랜덤 정수 반환하는 역할을 한다. 그 외에는 next()와 동일!
    {
        int r;
        do 
        {
            r = rand() % (b - a + 1) + a;  // a ~ b 사이 랜덤 수 생성
        } 
        while (r % 2 != 0); // 짝수가 아닐 경우 다시 생성
        return r;
    }
};

int main() 
{
    EvenRandom r;  // EvenRandom 객체 생성

    // 0 ~ 32767 사이의 짝수 랜덤 수 10개 출력
	cout << "-- 0에서 " << RAND_MAX << "까지의 랜덤 짝수 10개 --" << endl; // RAND_MAX는 32767
	for (int i = 0; i < 10; i++) // 10번 반복, 10개 출력, 0 ~ 9 (당연히 5번 문제와 동일)
    {
		int n = r.next();      // next()는 이제 무조건 짝수만 반환, 홀수는 반환하지 않음
        cout << n << ' ';
    }

    cout << endl << endl;

	// 2 ~ 10 사이의 짝수 랜덤 수 10개 출력
    cout << "-- 2에서 10까지의 랜덤 짝수 10개 --" << endl;
    for (int i = 0; i < 10; i++) 
    {
        int n = r.nextInRange(2, 10); // nextInRange도 짝수만 반환
        cout << n << ' ';
    }

    cout << endl;
    return 0;
}
