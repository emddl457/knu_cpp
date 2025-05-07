#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // å ����
    int price;
    int pages;

public:
    // ������: å ���� �ʱ�ȭ
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // < ������ �����ε�: å ���񳢸� ���� �� ���� �� �ְ� ��
    // const ���� ������ �� �Լ� �ȿ��� ��� ���� �ǵ� ���� ���� ����
    bool operator<(const Book& b) const {
        return title < b.title; // string Ŭ������ < ������ ���
    }

    // getTitle �Լ�: ���� ��¿� (����� �� ���ϰ� ������ ���� ����)
    string getTitle() const {
        return title;
    }
};

int main() {
    // ���� å �� �� ����
    Book a("û��", 20000, 300);

    // ����� �Է��� ���� �� ��� å ����
    string b_title;
    cout << "å �̸��� �Է��ϼ���>> ";
    getline(cin, b_title); // ���� �� �� ��ü �Է� �ޱ�

    // �Է� ���� �������� ���ο� Book ��ü ����
    Book b(b_title, 0, 0); // ����, �������� �ǹ� ��� 0����.

    // ���� �� ��: b�� a���� �տ� ���� a�� �ڿ� �ִٰ� ���
    if (b < a)
        cout << a.getTitle() << "�� " << b.getTitle() << "���� �ڿ� �ֱ���!" << endl;

    return 0;
}
