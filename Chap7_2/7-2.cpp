#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // å ���� �����
    int price;    // å ���� �����
    int pages;    // å ������ �� �����

public:
    // ������: Book ��ü�� ���� �� ����, ����, ������ ���� �ʱ�ȭ��
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // Book == int : å�� �����̶� ������ ���� �� �ְ� ���� ������
    // friend ���� ������ Ŭ���� �ܺο��� ��� ����(price)�� �����ؾ� �ϱ� ����
    friend bool operator==(const Book& book, int value) {
        return book.price == value; // ������ ������ true ����
    }

    // Book == string : å �����̶� ���ڿ� ���Ϸ��� ���� ������
    // �̰͵� friend�� �ؼ� title ���� �����ϰ� ��
    friend bool operator==(const Book& book, const string& t) {
        return book.title == t; // ���� ������ true
    }

    // Book == Book : ����, ����, ������ �� ��� ���ƾ� ���� å�̶�� �Ǵ�
    // ����� 3���� ���� ���� ������
    friend bool operator==(const Book& a, const Book& b) {
        return a.title == b.title && a.price == b.price && a.pages == b.pages;
    }
};

int main() {
    // a2, b2 å ��ü ���� (��ǰ C++�� ��� C++ å)
    Book a2("��ǰ C++", 30000, 500), b2("��� C++", 30000, 500);

    // ���� ��: a2 å ������ 30000���̸� �޽��� ���
    if (a2 == 30000)
        cout << "���� 30000��" << endl;

    // ���� ��: a2�� ������ "��ǰ C++"�̸� �޽��� ���
    if (a2 == "��ǰ C++")
        cout << "��ǰ C++ �Դϴ�." << endl;

    // ��ü ��: ����, ����, ������ ���� ���� ������ ���� å�̶�� �Ǵ�
    if (a2 == b2)
        cout << "�� å�� ���� å�Դϴ�." << endl;

    return 0;
}