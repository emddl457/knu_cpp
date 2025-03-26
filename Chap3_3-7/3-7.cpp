#include <iostream> 
#include <cstdlib> 
#include <ctime>     
using namespace std;

class SelectableRandom // SelectableRandom 클래스 정의!! 사용자가 짝수 또는 홀수 중 어떤 걸 원할지 선택할 수 있도록 한다.
{
public: // 생성자: 객체가 만들어질 때 호출됨(계속 반복되는 것은 아니다~~!!)
    SelectableRandom() // srand(): rand() 함수에 seed(시작점)를 설정
    {
        srand((unsigned)time(0)); // 매번 실행 시 다른 랜덤값을 얻기 위해 현재 시간을 기반으로 설정
    }

	int nextEven() // nextEven(): 0 ~ RAND_MAX 범위에서 짝수만 반환 (next는 새로운 값을 만든다는 뜻), EVen은 짝수를 의미
    {
		int r; // 랜덤 숫자를 임시로 저장해두는 변수 r 선언! (물론 그냥 randomNumber로 해도 되지만, r이 간단하니까...)
        do 
        {
            r = rand();        // 랜덤 수 생성
        } while (r % 2 != 0);  // 만약 홀수면 다시 뽑기 (짝수가 나올 때까지 반복)
        return r;              // 짝수일 경우 반환
    }

	int nextOdd() // nextOdd(): 0 ~ RAND_MAX 범위에서 홀수만 반환 (Odd는 홀수를 의미)
    {
        int r;
        do 
        {
            r = rand();        // 랜덤 수 생성
        } while (r % 2 == 0);  // 만약 짝수면 다시 뽑기 (홀수가 나올 때까지 반복)
        return r;
    }

    int nextInRangeEven(int a, int b) // nextInRangeEven(a, b): a ~ b 범위에서 짝수만 랜덤하게 골라주는 함수!
    {
        int r;
        do
        {
			r = rand() % (b - a + 1) + a; //  a ~ b 사이의 랜덤 정수를 하나 생성하는 공식(a=2, b=10이면 2~10 사이의 아무 수나 나옴)
        } while (r % 2 != 0);  // 짝수가 아니면 다시 반복
        return r;
    }

    int nextInRangeOdd(int a, int b) // nextInRangeOdd(a, b): a ~ b 범위에서 홀수만 랜덤하게 골라주는 함수!
    {
        int r;
        do 
        {
            r = rand() % (b - a + 1) + a;
        } while (r % 2 == 0);  // 짝수면 반복 (홀수 나올 때까지)
        return r;
    }
};

int main() 
{
    SelectableRandom r; // SelectableRandom 객체 r 생성
    cout << "-- 0에서 " << RAND_MAX << "까지의 짝수 랜덤 정수 10개 --" << endl; // 첫 번째 출력: 0 ~ 32767 사이의 "짝수" 10개 출력
    for (int i = 0; i < 10; i++) 
    {
        int n = r.nextEven();// 짝수만 반환하는 nextEven() 호출
		cout << n << ' '; // 숫자 출력 후 공백 한 칸 띄우기 
    }
    cout << endl << endl; // 줄바꿈 두 번!

    cout << "-- 2에서 9까지의 랜덤 홀수 정수 10개 --" << endl; // 두 번째 출력: 2 ~ 9 사이의 "홀수" 10개 출력
    for (int i = 0; i < 10; i++)
    {
        int n = r.nextInRangeOdd(2, 9);// 2~9 범위의 홀수 반환
        cout << n << ' ';
    } cout << endl;
    return 0;
}
