#include <iostream>
#include <string>
using namespace std;

// Book Ŭ���� ����
class Book {
    string title; // å ����
    int price;    // å ����
    int pages;    // å ������ ��

public:
    // ������
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // å ���� ��� �Լ�
    void show() {
        cout << title << " " << price << "�� " << pages << " ������" << endl;
    }

    // ��� ������ += : ���� ����
    Book& operator+=(int value) {
        price += value;
        return *this;
    }

    // ��� ������ -= : ���� ����
    Book& operator-=(int value) {
        price -= value;
        return *this;
    }

    // ��� ������ == (title ��)
    bool operator==(const Book& b) const {
        return title == b.title;
    }

    // ������ �Լ��� == (price ��)
    friend bool operator==(const Book& a, int price) {
        return a.price == price;
    }

    // ������ �Լ��� == (title, price, pages ��� ��)
    friend bool operator==(const Book& a, const Book& b) {
        return (a.title == b.title) && (a.price == b.price) && (a.pages == b.pages);
    }

    // ���� ������ ! : ������ 0�̸� true ��ȯ
    bool operator!() const {
        return price == 0;
    }

    // ���ڿ� �񱳿� getTitle �Լ�
    string getTitle() const {
        return title;
    }

    // ���ڿ� �� ������ < (���� �� �񱳿�)
    bool operator<(const Book& b) const {
        return title < b.title;
    }
};

// ���� �Լ�
int main() {
    // 1��
    Book a("û��", 20000, 300), b("�̷�", 30000, 500);
    a += 500;  // a�� ������ 500�� ������Ŵ
    b -= 500;  // b�� ������ 500�� ���ҽ�Ŵ
    a.show();  // û�� 20500�� 300 ������
    b.show();  // �̷� 29500�� 500 ������

    return 0;
}