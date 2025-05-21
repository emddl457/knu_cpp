#include <iostream>
#include <string>
using namespace std;

// 단위를 변환하는 추상 클래스
class Converter {
protected:
    double ratio; 

    // 변환 함수: 자식 클래스에서 구현
    virtual double convert(double src) = 0;

    // 원래 단위 이름 반환: 자식 클래스에서 구현
    virtual string getSourceString() = 0;

    // 바뀐 단위 이름 반환: 자식 클래스에서 구현
    virtual string getDestString() = 0;

public:
    Converter(double ratio) { this->ratio = ratio; }

    void run() {
        double src; 
        cout << getSourceString() << "을 " << getDestString() << "로 바꿉니다." << endl;
        cout << getSourceString() << "을 입력하세요>> ";
        cin >> src;
        cout << "변환 결과 : " << convert(src) << getDestString() << endl;
    }
};

// Converter를 상속받아 원화를 달러로 바꾸는 클래스
class WonToDollar : public Converter {
public:
    // 생성자에서 환율(1달러 = 1010원)을 넘김
    WonToDollar(double ratio) : Converter(ratio) {}

    // 변환 구현: 원화를 달러로 나눠서 환산
    double convert(double src) override {
        return src / ratio;
    }

    //원래 단위 이름 반환
    string getSourceString() override {
        return "원";
    }

    //바뀐 단위 이름 반환
    string getDestString() override {
        return "달러";
    }
};

int main() {
    WonToDollar wd(1010);
    wd.run();  // 실행
    return 0;
}
