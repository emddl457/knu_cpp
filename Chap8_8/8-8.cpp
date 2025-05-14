#include <iostream>
#include <string>
using namespace std;

// ������ �⺻ Ŭ����
class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;
public:
    Printer(string model, string manufacturer, int availableCount) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->availableCount = availableCount;
        this->printedCount = 0;
    }

    virtual void print(int pages) = 0; // ���������Լ�
    virtual void show() = 0;
};

// ��ũ�� ������ Ŭ����
class InkJetPrinter : public Printer {
    int availableInk;
public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount) {
        this->availableInk = availableInk;
    }

    void print(int pages) override {
        if (availableCount >= pages && availableInk >= pages) {
            availableCount -= pages;
            availableInk -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            cout << "������ ��ũ�� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void show() override {
        cout << model << " , " << manufacturer << " , ���� ���� "
            << availableCount << "�� , ���� ��ũ " << availableInk << endl;
    }
};

// ������ ������ Ŭ����
class LaserPrinter : public Printer {
    int availableToner;
public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount) {
        this->availableToner = availableToner;
    }

    void print(int pages) override {
        if (availableCount >= pages && availableToner >= pages) {
            availableCount -= pages;
            availableToner -= pages;
            printedCount += pages;
            cout << "����Ʈ�Ͽ����ϴ�." << endl;
        }
        else {
            cout << "������ ��ʰ� �����Ͽ� ����Ʈ�� �� �����ϴ�." << endl;
        }
    }

    void show() override {
        cout << model << " , " << manufacturer << " , ���� ���� "
            << availableCount << "�� , ���� ��� " << availableToner << endl;
    }
};

int main() {
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    // ���� ����� �� ����
    cout << "���� �۵����� 2 ���� �����ʹ� �Ʒ��� ����" << endl;
    cout << "��ũ�� : "; ink.show();
    cout << "������ : "; laser.show();

    while (true) {
        cout << "\n������(1:��ũ��, 2:������)�� �ż� �Է�>> ";
        int type, pages;
        cin >> type >> pages;

        if (type == 1)
            ink.print(pages);
        else if (type == 2)
            laser.print(pages);
        else
            cout << "�߸��� �����Դϴ�." << endl;

        // ���� ���� ��ũ/���/���� ���¸� �ݺ� ���...
        ink.show();
        laser.show();

        cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>> ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N')
            break;
    }

    return 0;
}

