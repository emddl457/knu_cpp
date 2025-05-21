#include <iostream>
#include <string>
using namespace std;

class Converter {
protected:
    double ratio; 

    //���� ���� �Լ���: �ڽ� Ŭ�������� �ݵ�� �����ؾ� ��
    virtual double convert(double src) = 0;          
    virtual string getSourceString() = 0; //�� ���� �̸�
    virtual string getDestString() = 0; //��ȯ �� ���� �̸�

public:
    Converter(double ratio) { this->ratio = ratio; }

    void run() {
        double src;
        cout << getSourceString() << "�� " << getDestString() << "�� �ٲߴϴ�." << endl;
        cout << getSourceString() << "�� �Է��ϼ���>> ";
        cin >> src;
        cout << "��ȯ ��� : " << convert(src) << getDestString() << endl;
    }
};

//Km�� Mile�� ��ȯ�ϴ� Ŭ����
class KmToMile : public Converter {
public:
    //�����ڿ��� Km ��� 1 Mile�� ������ �޾� ����
    KmToMile(double ratio) : Converter(ratio) {}

    //Km�� Mile�� ��ȯ: 1.609344�� ����
    double convert(double src) override {
        return src / ratio;
    }

    //�Է� ���� ��Ī ��ȯ
    string getSourceString() override {
        return "Km";
    }

    //��� ���� ��Ī ��ȯ
    string getDestString() override {
        return "Mile";
    }
};

int main() {
    //1������ 1.609344km
    KmToMile toMile(1.609344);
    toMile.run();
    return 0;
}
