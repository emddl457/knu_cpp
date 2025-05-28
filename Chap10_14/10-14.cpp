#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> users;
    string name, pw;
    int menu;

    cout << "***** ��ȣ ���� ���α׷� WHO�� �����մϴ� *****" << endl;

    while (true) {
        cout << "����:1, �˻�:2, ����:3 >> ";
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "1, 2, 3 �߿��� �������ּ���." << endl;
            continue;
        }

        cin.ignore(); // ���� ����

        if (menu == 1) {
            cout << "�̸� ��ȣ >> ";
            cin >> name >> pw;
            cin.ignore();
            users[name] = pw;
        }
        else if (menu == 2) {
            cout << "�̸� >> ";
            getline(cin, name);

            if (users.find(name) == users.end()) {
                cout << "����~~" << endl;
                continue;
            }

            for (int i = 0; i < 3; i++) {
                cout << "��ȣ? ";
                getline(cin, pw);
                if (users[name] == pw) {
                    cout << "���!!" << endl;
                    break;
                }
                else {
                    cout << "����~~" << endl;
                }
            }
        }
        else if (menu == 3) {
            cout << "���α׷��� �����մϴ�..." << endl;
            break;
        }
        else {
            cout << "1, 2, 3 �߿��� �������ּ���." << endl;
        }
    }
    return 0;
}