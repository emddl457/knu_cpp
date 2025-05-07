#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // 책 제목 저장용
    int price;    // 책 가격 저장용
    int pages;    // 책 페이지 수 저장용

public:
    // 생성자: Book 객체를 만들 때 제목, 가격, 페이지 수를 초기화함
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // Book == int : 책의 가격이랑 정수를 비교할 수 있게 만든 연산자
    // friend 붙인 이유는 클래스 외부에서 멤버 변수(price)에 접근해야 하기 때문
    friend bool operator==(const Book& book, int value) {
        return book.price == value; // 가격이 같으면 true 리턴
    }

    // Book == string : 책 제목이랑 문자열 비교하려고 만든 연산자
    // 이것도 friend로 해서 title 접근 가능하게 함
    friend bool operator==(const Book& book, const string& t) {
        return book.title == t; // 제목 같으면 true
    }

    // Book == Book : 제목, 가격, 페이지 수 모두 같아야 같은 책이라고 판단
    // 멤버가 3개라서 각각 따로 비교해줌
    friend bool operator==(const Book& a, const Book& b) {
        return a.title == b.title && a.price == b.price && a.pages == b.pages;
    }
};

int main() {
    // a2, b2 책 객체 생성 (명품 C++과 고급 C++ 책)
    Book a2("명품 C++", 30000, 500), b2("고급 C++", 30000, 500);

    // 가격 비교: a2 책 가격이 30000원이면 메시지 출력
    if (a2 == 30000)
        cout << "정가 30000원" << endl;

    // 제목 비교: a2의 제목이 "명품 C++"이면 메시지 출력
    if (a2 == "명품 C++")
        cout << "명품 C++ 입니다." << endl;

    // 전체 비교: 제목, 가격, 페이지 수가 전부 같으면 같은 책이라고 판단
    if (a2 == b2)
        cout << "두 책이 같은 책입니다." << endl;

    return 0;
}