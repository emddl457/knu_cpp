#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // 책 제목
    int price;    // 책 가격
    int pages;    // 책 페이지 수

public:
    // 생성자: 객체 만들면서 바로 초기화 가능하게 함
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // ! 연산자 오버로딩: 가격이 0원이면 true 반환하게 만듦
    // 멤버 변수는 안 건드리니까 const 붙여줌
    bool operator!() const {
        return price == 0; // 가격이 0이면 공짜니까 true
    }
};

int main() {
    // 가격이 0원인 공짜책 생성
    Book book("버려진 책", 0, 50);

    // ! 연산자 사용: 가격이 0원이면 공짜다 출력
    if (!book)
        cout << "공짜다" << endl;

    return 0;
}

//!book에서 !는 book.operator!() 호출된다는 뜻이며,
//operator!() 함수에서 price == 0일 때 true를 반환하니 if문이 실행된다.