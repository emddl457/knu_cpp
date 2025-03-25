#include <iostream>
using namespace std;
class CoffeeMachine 
{
private: // 멤버 변수는 private으로 선언하여 외부에서 직접 접근하지 못하도록 함!
    int coffee; // 커피 양
    int water;  // 물 양
    int sugar;  // 설탕 양

public: // 매개변수와 멤버 변수 이름이 같기 때문에 this->를 사용하여 구분함 (this는 객체 자신을 가리키는 포인터)
    CoffeeMachine(int coffee, int water, int sugar) 
    {
		this->coffee = coffee; // 클래스의 멤버 변수 coffee에 매개변수 값을 대입 (this->coffee는 멤버 변수를 가리킴)
		this->water = water;   // 같은 이유로 this->water 사용 
        this->sugar = sugar;   // this->sugar도 마찬가지!!
    }

   
	void drinkEspresso() // 에스프레소 한 잔 만들기: 커피 1, 물 1 사용됨
    {
		if (coffee >= 1 && water >= 1) // 커피와 물이 모두 1 이상일 때
        {
			coffee -= 1; // 커피 1 줄이기
			water -= 1; // 물 1 줄이기
        } // 재료가 부족할 경우 아무 것도 하지 않음!
    }

    void drinkAmericano()  // 아메리카노 한 잔 만들기: 커피 1, 물 2 사용됨
    {
		if (coffee >= 1 && water >= 2) // 커피와 물이 모두 1 이상일 때
        {
			coffee -= 1; // 커피 1 줄이기
			water -= 2;  // 물 2 줄이기
        }
    }

    void drinkSugarCoffee() // 설탕 커피 한 잔 만들기: 커피 1, 물 2, 설탕 1 사용됨
    {
		if (coffee >= 1 && water >= 2 && sugar >= 1) // 커피, 물, 설탕이 모두 1 이상일 때
        {
			coffee -= 1; // 커피 1 줄이기
			water -= 2;  // 물 2 줄이기
			sugar -= 1;  // 설탕 1 줄이기
        }
    }

	void fill() // 함수 정의 (재료를 모두 10으로 채우는 함수)
    {
		coffee = 10; // 커피 10으로 채우기
		water = 10;  // 물 10으로 채우기
		sugar = 10;  // 설탕 10으로 채우기
    }

	// 현재 커피머신 상태 출력 (커피, 물, 설탕의 양 출력)
	void show() // 함수 정의 (커피머신 상태 출력 함수)
    {
		cout << "커피 머신 상태, 커피:" << coffee // 현재 커피머신의 커피, 물, 설탕의 양 출력
			<< " 물:" << water // cout은 << 연산자로 여러 값을 출력할 수 있음
			<< " 설탕:" << sugar << endl;
    }
}; // 클래스 정의 끝~~
int main() 
{
    CoffeeMachine java(5, 10, 3); 
    java.drinkEspresso();  
    java.show();           
    java.drinkAmericano(); 
    java.show();          
    java.drinkSugarCoffee(); 
    java.show();            
    java.fill();           
    java.show();          
    return 0;
}
