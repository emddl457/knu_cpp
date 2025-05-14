#include <iostream>
#include <string>
using namespace std;

// �������� �⺻ Ŭ����
class Printer {
protected:
    string model;        // �𵨸�
    string manufacturer; // ������
    int printedCount;    // �μ�� �� ������ ��
public:
    Printer(string model, string manufacturer) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->printedCount = 0;
    }

    // �����Լ��� �μ� ��� ���� (�ڽ� Ŭ�������� �������̵�)
    virtual void print(int pages) = 0;

    // ������ ���� ��� �Լ�
    virtual void show() = 0;
};

// ��ũ�� ������ Ŭ����
class InkJetPrinter : public Printer {
    int availableInk;  // ���� ��ũ��
public:
    InkJetPrinter(string model, string manufacturer, int availableInk)
        : Printer(model, manufacturer) {
        this->availableInk = availableInk;
    }

    void print(int pages) override {
        if (availableInk >= pages) {
            availableInk -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            cout << "��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void show() override {
        cout << model << " / " << manufacturer << " / ���� ���� " << (100 - printedCount)
            << " / ���� ��ũ " << availableInk << endl;
    }
};

// ������ ������ Ŭ����
class LaserPrinter : public Printer {
    int availableToner;  // ���� ��ʷ�
public:
    LaserPrinter(string model, string manufacturer, int availableToner)
        : Printer(model, manufacturer) {
        this->availableToner = availableToner;
    }

    void print(int pages) override {
        if (availableToner >= pages) {
            availableToner -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            cout << "��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void show() override {
        cout << model << " / " << manufacturer << " / ���� ���� " << (100 - printedCount)
            << " / ���� ��� " << availableToner << endl;
    }
};

int main() {
    // ������ ��ü �迭 (��ũ���� ������)
    InkJetPrinter ink("Officejet V40", "HP", 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 20);

    while (true) {
        cout << "\n���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
        cout << "��ũ�� : "; ink.show();
        cout << "������ : "; laser.show();

        cout << "������(1:��ũ��, 2:������)�� �ż� �Է�>> ";
        int type, pages;
        cin >> type >> pages;

        if (type == 1) {
            ink.print(pages);
        }
        else if (type == 2) {
            laser.print(pages);
        }
        else {
            cout << "�߸��� �Է��Դϴ�." << endl;
        }

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>> ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    return 0;
}
