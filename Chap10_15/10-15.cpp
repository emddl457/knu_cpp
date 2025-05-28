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
    cout << "원을 삽입하고 삭제하는 프로그램입니다." << endl;

    vector<Circle*> v;
    int menu;
    while (true) {
        cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            int radius;
            string name;
            cout << "생성하고자 하는 원의 반지름과 이름 >> ";
            cin >> radius >> name;
            cin.ignore();
            v.push_back(new Circle(radius, name));
        }
        else if (menu == 2) {
            string name;
            cout << "삭제하고자 하는 원의 이름은 >> ";
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
            cout << "1~4 중에서 선택해주세요." << endl;
        }
    }
    return 0;
}