#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
    double ratio; 

    //순수 가상 함수들: 자식 클래스에서 반드시 구현해야 함
    virtual double convert(double src) = 0;          
    virtual string getSourceString() = 0; //원 단위 이름
    virtual string getDestString() = 0; //변환 후 단위 이름

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

//Km를 Mile로 변환하는 클래스
class KmToMile : public Converter {
public:
    //생성자에서 Km 대비 1 Mile의 비율을 받아 전달
    KmToMile(double ratio) : Converter(ratio) {}

    //Km를 Mile로 변환: 1.609344로 나눔
    double convert(double src) override {
        return src / ratio;
    }

    //입력 단위 명칭 반환
    string getSourceString() override {
        return "Km";
    }

    //출력 단위 명칭 반환
    string getDestString() override {
        return "Mile";
    }
};

int main() {
    //1마일은 1.609344km
    KmToMile toMile(1.609344);
    toMile.run();
    return 0;
}
