#include <iostream>
#include <string>
using namespace std;

// ������ ��ȯ�ϴ� �߻� Ŭ����
class Converter {
protected:
    double ratio; 

    // ��ȯ �Լ�: �ڽ� Ŭ�������� ����
    virtual double convert(double src) = 0;

    // ���� ���� �̸� ��ȯ: �ڽ� Ŭ�������� ����
    virtual string getSourceString() = 0;

    // �ٲ� ���� �̸� ��ȯ: �ڽ� Ŭ�������� ����
    virtual string getDestString() = 0;

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

// Converter�� ��ӹ޾� ��ȭ�� �޷��� �ٲٴ� Ŭ����
class WonToDollar : public Converter {
public:
    // �����ڿ��� ȯ��(1�޷� = 1010��)�� �ѱ�
    WonToDollar(double ratio) : Converter(ratio) {}

    // ��ȯ ����: ��ȭ�� �޷��� ������ ȯ��
    double convert(double src) override {
        return src / ratio;
    }

    //���� ���� �̸� ��ȯ
    string getSourceString() override {
        return "��";
    }

    //�ٲ� ���� �̸� ��ȯ
    string getDestString() override {
        return "�޷�";
    }
};

int main() {
    WonToDollar wd(1010);
    wd.run();  // ����
    return 0;
}
