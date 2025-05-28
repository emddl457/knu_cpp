#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Circle {
    string name;
    int radius;
public:
    Circle(int radius, string name) {
        this->radius = radius;
        this->name = name;
    }
    double getArea() { return 3.14 * radius * radius; }
    string getName() { return name; }
};

int main() {
    cout << "���� �����ϰ� �����ϴ� ���α׷��Դϴ�." << endl;

    vector<Circle*> v;
    int menu;
    while (true) {
        cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            int radius;
            string name;
            cout << "�����ϰ��� �ϴ� ���� �������� �̸� >> ";
            cin >> radius >> name;
            cin.ignore();
            v.push_back(new Circle(radius, name));
        }
        else if (menu == 2) {
            string name;
            cout << "�����ϰ��� �ϴ� ���� �̸��� >> ";
            cin >> name;
            cin.ignore();

            for (auto it = v.begin(); it != v.end(); ) {
                if ((*it)->getName() == name) {
                    delete* it;
                    it = v.erase(it);
                }
                else {
                    ++it;
                }
            }
        }
        else if (menu == 3) {
            for (int i = 0; i < v.size(); i++) {
                cout << v[i]->getName() << endl;
            }
        }
        else if (menu == 4) {
            for (int i = 0; i < v.size(); i++) {
                delete v[i];
            }
            v.clear();
            break;
        }
        else {
            cout << "1~4 �߿��� �������ּ���." << endl;
        }
    }
    return 0;
}