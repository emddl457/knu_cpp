#include <iostream>
#include <string>
using namespace std;

// Book 클래스 정의
class Book {
    string title; // 책 제목
    int price;    // 책 가격
    int pages;    // 책 페이지 수

public:
    // 생성자
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // 책 정보 출력 함수
    void show() {
        cout << title << " " << price << "원 " << pages << " 페이지" << endl;
    }

    // 멤버 연산자 += : 가격 증가
    Book& operator+=(int value) {
        price += value;
        return *this;
    }

    // 멤버 연산자 -= : 가격 감소
    Book& operator-=(int value) {
        price -= value;
        return *this;
    }

    // 멤버 연산자 == (title 비교)
    bool operator==(const Book& b) const {
        return title == b.title;
    }

    // 프렌드 함수로 == (price 비교)
    friend bool operator==(const Book& a, int price) {
        return a.price == price;
    }

    // 프렌드 함수로 == (title, price, pages 모두 비교)
    friend bool operator==(const Book& a, const Book& b) {
        return (a.title == b.title) && (a.price == b.price) && (a.pages == b.pages);
    }

    // 부정 연산자 ! : 가격이 0이면 true 반환
    bool operator!() const {
        return price == 0;
    }

    // 문자열 비교용 getTitle 함수
    string getTitle() const {
        return title;
    }

    // 문자열 비교 연산자 < (사전 순 비교용)
    bool operator<(const Book& b) const {
        return title < b.title;
    }
};

// 메인 함수
int main() {
    // 1번
    Book a("청춘", 20000, 300), b("미래", 30000, 500);
    a += 500;  // a의 가격을 500원 증가시킴
    b -= 500;  // b의 가격을 500원 감소시킴
    a.show();  // 청춘 20500원 300 페이지
    b.show();  // 미래 29500원 500 페이지

    return 0;
}