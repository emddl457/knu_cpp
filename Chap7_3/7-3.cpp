#include <iostream>
#include <string>
using namespace std;

class Book {
    string title; // å ����
    int price;    // å ����
    int pages;    // å ������ ��

public:
    // ������: ��ü ����鼭 �ٷ� �ʱ�ȭ �����ϰ� ��
    Book(string t, int p, int pg) : title(t), price(p), pages(pg) {}

    // ! ������ �����ε�: ������ 0���̸� true ��ȯ�ϰ� ����
    // ��� ������ �� �ǵ帮�ϱ� const �ٿ���
    bool operator!() const {
        return price == 0; // ������ 0�̸� ��¥�ϱ� true
    }
};

int main() {
    // ������ 0���� ��¥å ����
    Book book("������ å", 0, 50);

    // ! ������ ���: ������ 0���̸� ��¥�� ���
    if (!book)
        cout << "��¥��" << endl;

    return 0;
}

//!book���� !�� book.operator!() ȣ��ȴٴ� ���̸�,
//operator!() �Լ����� price == 0�� �� true�� ��ȯ�ϴ� if���� ����ȴ�.