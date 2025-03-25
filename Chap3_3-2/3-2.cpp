#include <iostream>
#include <string>
using namespace std;

class Date
{
private: // 클래스 안에 있는 데이터(변수)를 외부에서 직접 접근하지 못하게 막는 역할을 한다! 대신 public 함수를 통해서 값을 읽거나 바꾸게 만드는 것이다. 그래야 잘못된 값이 들어오는 것을 막을 수 있다.(예를 들면 month = 999 같은 값) 
    int year, month, day;

public: // public은 외부(사용자)가 사용할 수 있다. 예: private은 int x;(외부에서 x를 건드리지 못함), public은 int getYear() 같은 함수이다.
    Date(int a, int b, int c) // 생성자 1: 정수형 연도, 월, 일을 받는 생성자.
    //생성자란, 객체가 처음 만들어질 때 자동으로 실행되는 함수다. 클래스의 이름과 동일한 멤버 함수! 객체의 초기화에 사용된다.
    {
        //전달받은 값을 멤버 변수에 저장한다. 
        year = a;
        month = b;
        day = c;
    }

    Date(string date) // 생성자 2. YYYY/M/D의 형식을 문자열로 받아서 날짜로 분해한다.
    {
        year = stoi(date.substr(0, 4)); // (stoi = string to int: 문자열string을 정수int로 바꿔주는 함수)
        month = stoi(date.substr(5, 1)); // (sub + str = sub-string, 문자열의 일부를 잘라내는 함수)
        day = stoi(date.substr(7));
    }

    void show() // void는 아무것도 반환하지 않는 함수이다. 즉, void show(): 단지 아래를 출력하고 끝, 어떤 값을 돌려주는(return) 함수가 아니다.
    {
        cout << year << "년" << month << "월" << day << "일" << endl;
    } // 그래서 void가 붙는다! 나는 값을 돌려줄 게 없어요 라는 뜻이므로!

    int getYear() // 반대로, 이 함수는 year 값을 반환(return)하므로, 정수형 int를 사용한다. 
    {
        return year;
    }

    int getMonth()
    {
        return month;
    }

    int getDay()
    {
        return day;
    }
};

int main()
{
    Date birth(2014, 3, 20);
    Date independenceDay("1945/8/15");

    independenceDay.show(); // "1945년8월15일"
    cout << birth.getYear() << "," << birth.getMonth() << "," << birth.getDay() << endl;

    return 0;
}