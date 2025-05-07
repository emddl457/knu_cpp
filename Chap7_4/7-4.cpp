#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // 책 제목
    int price;
    int pages;

public:
    // 생성자: 책 정보 초기화
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // < 연산자 오버로딩: 책 제목끼리 사전 순 비교할 수 있게 함
    // const 붙인 이유는 이 함수 안에서 멤버 변수 건들 일이 없기 때문
    bool operator<(const Book& b) const {
        return title < b.title; // string 클래스의 < 연산자 사용
    }

    // getTitle 함수: 제목 출력용 (출력할 때 편하게 쓰려고 따로 만듦)
    string getTitle() const {
        return title;
    }
};

int main() {
    // 기준 책 한 권 생성
    Book a("청춘", 20000, 300);

    // 사용자 입력을 통해 비교 대상 책 생성
    string b_title;
    cout << "책 이름을 입력하세요>> ";
    getline(cin, b_title); // 제목 한 줄 전체 입력 받기

    // 입력 받은 제목으로 새로운 Book 객체 생성
    Book b(b_title, 0, 0); // 가격, 페이지는 의미 없어서 0으로.

    // 사전 순 비교: b가 a보다 앞에 오면 a가 뒤에 있다고 출력
    if (b < a)
        cout << a.getTitle() << "이 " << b.getTitle() << "보다 뒤에 있구나!" << endl;

    return 0;
}
