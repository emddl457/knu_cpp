#include <iostream>
#include <string>
using namespace std;

// 프린터의 기본 클래스
class Printer {
protected:
    string model;        // 모델명
    string manufacturer; // 제조사
    int printedCount;    // 인쇄된 총 페이지 수
public:
    Printer(string model, string manufacturer) {
        this->model = model;
        this->manufacturer = manufacturer;
        this->printedCount = 0;
    }

    // 가상함수로 인쇄 기능 정의 (자식 클래스에서 오버라이딩)
    virtual void print(int pages) = 0;

    // 프린터 정보 출력 함수
    virtual void show() = 0;
};

// 잉크젯 프린터 클래스
class InkJetPrinter : public Printer {
    int availableInk;  // 남은 잉크량
public:
    InkJetPrinter(string model, string manufacturer, int availableInk)
        : Printer(model, manufacturer) {
        this->availableInk = availableInk;
    }

    void print(int pages) override {
        if (availableInk >= pages) {
            availableInk -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
        else {
            cout << "잉크가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() override {
        cout << model << " / " << manufacturer << " / 남은 종이 " << (100 - printedCount)
            << " / 남은 잉크 " << availableInk << endl;
    }
};

// 레이저 프린터 클래스
class LaserPrinter : public Printer {
    int availableToner;  // 남은 토너량
public:
    LaserPrinter(string model, string manufacturer, int availableToner)
        : Printer(model, manufacturer) {
        this->availableToner = availableToner;
    }

    void print(int pages) override {
        if (availableToner >= pages) {
            availableToner -= pages;
            printedCount += pages;
            cout << "프린트하였습니다." << endl;
        }
        else {
            cout << "토너가 부족하여 프린트할 수 없습니다." << endl;
        }
    }

    void show() override {
        cout << model << " / " << manufacturer << " / 남은 종이 " << (100 - printedCount)
            << " / 남은 토너 " << availableToner << endl;
    }
};

int main() {
    // 프린터 객체 배열 (잉크젯과 레이저)
    InkJetPrinter ink("Officejet V40", "HP", 10);
    LaserPrinter laser("SCX-6x45", "삼성전자", 20);

    while (true) {
        cout << "\n현재 작동중인 2 대의 프린터는 아래와 같다" << endl;
        cout << "잉크젯 : "; ink.show();
        cout << "레이저 : "; laser.show();

        cout << "프린터(1:잉크젯, 2:레이저)와 매수 입력>> ";
        int type, pages;
        cin >> type >> pages;

        if (type == 1) {
            ink.print(pages);
        }
        else if (type == 2) {
            laser.print(pages);
        }
        else {
            cout << "잘못된 입력입니다." << endl;
        }

        cout << "계속 프린트 하시겠습니까?(y/n)>> ";
        char cont;
        cin >> cont;
        if (cont == 'n' || cont == 'N') break;
    }

    return 0;
}
