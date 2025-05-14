#include <iostream>
#include <string>
using namespace std;

// 프린터 기본 클래스
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

    virtual void print(int pages) = 0; // 순수가상함수
    virtual void show() = 0;
};

// 잉크젯 프린터 클래스
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
            cout << "프린트하였습니다." << endl;
        }
        else {
            cout << "용지나 잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() override {
        cout << model << " , " << manufacturer << " , 남은 종이 "
            << availableCount << "장 , 남은 잉크 " << availableInk << endl;
    }
};

// 레이저 프린터 클래스
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
            cout << "프린트하였습니다." << endl;
        }
        else {
            cout << "용지나 토너가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() override {
        cout << model << " , " << manufacturer << " , 남은 종이 "
            << availableCount << "장 , 남은 토너 " << availableToner << endl;
    }
};

int main() {
    InkJetPrinter ink("Officejet V40", "HP", 5, 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 3, 20);

    // 상태 출력은 한 번만
    cout << "현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
    cout << "잉크젯 : "; ink.show();
    cout << "레이저 : "; laser.show();

    while (true) {
        cout << "\n프린터(1:잉크젯, 2:레이저)와 매수 입력>> ";
        int type, pages;
        cin >> type >> pages;

        if (type == 1)
            ink.print(pages);
        else if (type == 2)
            laser.print(pages);
        else
            cout << "잘못된 선택입니다." << endl;

        // 현재 남은 잉크/토너/종이 상태만 반복 출력...
        ink.show();
        laser.show();

        cout << "계속 프린트 하시겠습니까?(y/n)>> ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N')
            break;
    }

    return 0;
}

