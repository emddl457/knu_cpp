#include <iostream>
#include <string>
using namespace std;

//�⺻ Printer �߻� Ŭ����
class Printer {
protected:
    string model;
    string manufacturer;
    int printedCount;
    int availableCount;

public:
    Printer(string model, string manufacturer, int availableCount)
        : model(model), manufacturer(manufacturer), printedCount(0), availableCount(availableCount) {}

    virtual void print(int pages) = 0; //���� ���� �Լ�

    virtual void show() {
        cout << model << " , " << manufacturer << " , ���� ���� " << availableCount << "��";
    }

    virtual ~Printer() {}
};

//��ũ�� ������ Ŭ����
class InkJetPrinter : public Printer {
    int availableInk;

public:
    InkJetPrinter(string model, string manufacturer, int availableCount, int availableInk)
        : Printer(model, manufacturer, availableCount), availableInk(availableInk) {}

    void print(int pages) override {
        if (availableCount < pages || availableInk < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �� �����ϴ�." << endl;
            return;
        }

        availableCount -= pages;
        availableInk -= pages;
        printedCount += pages;
        cout << "����Ʈ�Ͽ����ϴ�." << endl;
    }

    void show() override {
        Printer::show();
        cout << " , ���� ��ũ " << availableInk << endl;
    }
};

//������ ������ Ŭ����
class LaserPrinter : public Printer {
    int availableToner;

public:
    LaserPrinter(string model, string manufacturer, int availableCount, int availableToner)
        : Printer(model, manufacturer, availableCount), availableToner(availableToner) {}

    void print(int pages) override {
        if (availableCount < pages || availableToner < pages) {
            cout << "������ �����Ͽ� ����Ʈ�� �� �� �����ϴ�." << endl;
            return;
        }

        availableCount -= pages;
        availableToner -= pages;
        printedCount += pages;
        cout << "����Ʈ�Ͽ����ϴ�." << endl;
    }

    void show() override {
        Printer::show();
        cout << " , ���� ��� " << availableToner << endl;
    }
};

int main() {
    //������ �ʱ� ���� ����
    InkJetPrinter inkjet("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "�Ｚ����", 3, 20);

    cout << "���� �۵����� 2���� �����ʹ� �Ʒ��� ����" << endl;
    inkjet.show();
    laser.show();

    while (true) {
        int type, pages;
        cout << "\n������(1:��ũ��, 2:������)�� �ż� �Է�>> ";
        cin >> type >> pages;

        if (type == 1) {
            inkjet.print(pages);
        }
        else if (type == 2) {
            laser.print(pages);
        }

        inkjet.show();
        laser.show();

        char cont;
        cout << "��� ����Ʈ �Ͻðڽ��ϱ�?(y/n)>> ";
        cin >> cont;
        if (cont != 'y' && cont != 'Y') break;
    }

    return 0;
}
