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
        cout << year << "�⵵, " << title << ", " << author << endl;
    }
};

int main() {
    vector<Book> v;

    cout << "�԰��� å�� �Է��ϼ���. �⵵�� -1�� �Է��ϸ� �԰� �����մϴ�." << endl;

    while (true) {
        int year;
        cout << "�⵵>>";
        cin >> year;
        cin.ignore();

        if (year == -1) break;

        string title, author;
        cout << "å�̸�>>";
        getline(cin, title);
        cout << "����>>";
        getline(cin, author);

        v.push_back(Book(year, title, author));
    }

    cout << "�� �԰�� å�� " << v.size() << "���Դϴ�." << endl;

    // ���� �˻�
    string searchAuthor;
    cout << "�˻��ϰ��� �ϴ� ���� �̸��� �Է��ϼ���>>";
    getline(cin, searchAuthor);
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getAuthor() == searchAuthor) {
            v[i].print();
        }
    }

    // ���� �˻�
    int searchYear;
    cout << "�˻��ϰ��� �ϴ� �⵵�� �Է��ϼ���>>";
    cin >> searchYear;
    for (int i = 0; i < v.size(); i++) {
        if (v[i].getYear() == searchYear) {
            v[i].print();
        }
    }

    return 0;
}
