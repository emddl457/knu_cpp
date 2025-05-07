#include <iostream>  // ����� ����� ���� ����
using namespace std; // std:: �����ϰ� cout, endl ���� �ٷ� ���� ����

class Color {
    int red, green, blue; // RGB ������ ���� ���� ���� ������ ����

public:
    // ������: Color ��ü�� ���� �� RGB ���� �ʱ�ȭ��
    Color() : red(0), green(0), blue(0) {}
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    // show �Լ�: ���� Color ��ü�� RGB ���� ȭ�鿡 �����
    void show() {
        cout << red << " " << green << " " << blue << endl;
    }

    // + ������ �����ε� (��� �Լ�)
    // �� ���� ���ؼ� ���ο� Color ��ü�� ��ȯ��
    Color operator+(const Color& c) {
        // �� ������ ���ϵ�, 255 �ʰ� �� 255�� ���� (RGB �ִ밪�� 255)
        int r = (red + c.red > 255) ? 255 : red + c.red;
        int g = (green + c.green > 255) ? 255 : green + c.green;
        int b = (blue + c.blue > 255) ? 255 : blue + c.blue;

        // ����� r, g, b�� ������� �� Color ��ü ������ ����
        return Color(r, g, b);
    }

    // == ������ �����ε� (������ �Լ�)
    // �� Color ��ü�� RGB ���� ��� ������ true ��ȯ
    friend bool operator==(const Color& a, const Color& b) {
        return a.red == b.red && a.green == b.green && a.blue == b.blue;
        // RGB ������ ��ġ�ؾ߸� true
    }
};

int main() {
    // red: ���� (255, 0, 0), blue: �Ķ� (0, 0, 255)
    Color red(255, 0, 0), blue(0, 0, 255), c;

    // red�� blue�� ���� ���� c�� ������ (������� �Ǳ� ���)
    c = red + blue;

    // c ���� �� ��� (255 0 255�� ���;� �����)
    c.show();

    // ���� ����� ��ü ���� (���: (255, 0, 255))
    Color fuchsia(255, 0, 255);

    // c�� fuchsia�� ���� �������� ��
    if (c == fuchsia) // == ������ �����ε� �Լ��� ȣ���
        cout << "����� ����" << endl;
    else
        cout << "����� �ƴ�" << endl;

    return 0;
}

// �ܿ� �����... operator+�� �� ������ ���� ���ϴ� ������ �����ε�. �� ���� ��ü�� ��ȯ.
// operator==�� �� ������ ������ ���ϴ� ������ �����ε�. true/false ��ȯ. (RGB ���� ��� ���ƾ� true)
// friend�� Ŭ���� �ܺ� �Լ����� private ����� ������ �� �ְ� ���ִ� Ű����.
// show()�� RGB ���� ����ϴ� ��� �Լ�. Color ��ü�� ���¸� ������.
