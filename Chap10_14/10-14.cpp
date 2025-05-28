#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> users;
    string name, pw;
    int menu;

    cout << "***** 암호 관리 프로그램 WHO를 시작합니다 *****" << endl;

    while (true) {
        cout << "삽입:1, 검사:2, 종료:3 >> ";
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "1, 2, 3 중에서 선택해주세요." << endl;
            continue;
        }

        cin.ignore(); // 개행 제거

        if (menu == 1) {
            cout << "이름 암호 >> ";
            cin >> name >> pw;
            cin.ignore();
            users[name] = pw;
        }
        else if (menu == 2) {
            cout << "이름 >> ";
            getline(cin, name);

            if (users.find(name) == users.end()) {
                cout << "실패~~" << endl;
                continue;
            }

            for (int i = 0; i < 3; i++) {
                cout << "암호? ";
                getline(cin, pw);
                if (users[name] == pw) {
                    cout << "통과!!" << endl;
                    break;
                }
                else {
                    cout << "실패~~" << endl;
                }
            }
        }
        else if (menu == 3) {
            cout << "프로그램을 종료합니다..." << endl;
            break;
        }
        else {
            cout << "1, 2, 3 중에서 선택해주세요." << endl;
        }
    }
    return 0;
}