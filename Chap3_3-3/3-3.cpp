#include <iostream>
#include <string>
using namespace std;


class Account // Account 클래스 선언하기

{
private:
	string name; // 이름
	int id; // 계좌번호
	int balance; // 잔액

public: // 생성자, Account 객체가 만들어질 때 초기값을 설정해준다. 
	Account(string name, int id, int balance) // 문제의 예시처럼 "kitae"라는 이름, 1이라는 계좌번호, 5000이라는 잔액이 호출된다.
	{
		this->name = name; // 매개변수와 멤버 변수의 이름이 같기 때문에 this를 사용하여 멤버 변수임을 명확히 해준다.
		this->id = id;
		this->balance = balance;
	}

	string getOwner() // 계좌 소유자 이름을 반환하는 함수
	{
		return name;
	}

	void deposit(int amount) // 입금하는 함수
	{
		balance += amount; // amount만큼 잔액에 더해준다.
	}

	int withdraw(int amount) // 출금하는 함수 (!!문제의 조건에 따라 반환값을 int로 설정해준다!! void로 설정하면 오류가 발생한다.)
	// void로 작성하면 main함수에서 "int" 형식의 엔터티를 초기화할 수 없습니다, 라는 오류가 발생하게 된다.
	{
		if (amount > balance) // 출금하려는 금액이 잔액보다 많을 경우
			return 0; 
		balance -= amount; // 출금하려는 금액이 잔액보다 적을 경우 amount만큼 잔액에서 빼준다.
	return amount; 
	}

	int inquiry() // 잔액을 반환하는 함수
	{
		return balance;
	}

};

int main()
{
	Account a("kitae", 1, 5000); // id 1번, 잔액 5000원, 이름이 kitae인 계좌 생성
	a.deposit(50000); // 50000원 저금 
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl; // kitae의 잔액은 55000원
	int money = a.withdraw(20000); // 20000원 출금
	cout << a.getOwner() << "의 잔액은 " << a.inquiry() << endl; // kitae의 잔액은 35000원

	return 0; 
}
