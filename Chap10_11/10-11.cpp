#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Book {
    int year;
    string title;
    string author;
public:
    Book(int year, string title, string author) {
        this->year = year;
        this->title = title;
        this->author = author;
    }

    int getYear() { return year; }
    string getTitle() { return title; }
    string getAuthor() { return author; }

    void print() {
        cout << year << "년도, " << title << ", " << author << endl;
    }
};

int main() {
    vector<Book> v;

    cout << "입고할 책을 입력하세요. 년도에 -1을 입력하면 입고를 종료합니다." << endl;

    while (true) {
        int year;
        cout << "년도>>";
        cin >> year;
        cin.ignore();

        if (year == -1) break;

        string title, author;
        cout << "책이름>>";
        getline(cin, title);
        cout << "저자>>";
        getline(cin, author);

        v.push_back(Book(year, title, author));
    }

    cout << "총 입고된 책은 " << v.size() << "권입니다." << endl;

    // 저자 검색
    string searchAuthor;
    cout << "검색하고자 하는 저자 이름을 입력하세요>>";
    getline(cin, searchAuthor);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getAuthor() == searchAuthor) {
            v[i].print();
        }
    }

    // 연도 검색
    int searchYear;
    cout << "검색하고자 하는 년도를 입력하세요>>";
    cin >> searchYear;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getYear() == searchYear) {
            v[i].print();
        }
    }

    return 0;
}
