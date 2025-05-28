#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> scores;
    string name;
    int score;

    cout << "***** �������� ���α׷� HIGH SCORE�� �����մϴ� *****" << endl;

    while (true) {
        cout << "�Է�:1, ��ȸ:2, ����:3 >> ";
        int menu;
        cin >> menu;
        cin.ignore(); // ���� ����

        if (menu == 1) {
            cout << "�̸��� ���� >> ";
            cin >> name >> score;
            cin.ignore();
            scores[name] = score;
        }
        else if (menu == 2) {
            cout << "�̸� >> ";
            getline(cin, name);
            if (name == "�ְ��") {
                // �ְ� ���� ã��
                int maxScore = -1;
                string maxName;
                for (auto& p : scores) {
                    if (p.second > maxScore) {
                        maxScore = p.second;
                        maxName = p.first;
                    }
                }
                cout << "�ְ���� ������ " << maxScore << endl;
            }
            else {
                if (scores.find(name) != scores.end()) {
                    cout << name << "�� ������ " << scores[name] << endl;
                }
                else {
                    cout << name << "�� ������ ã�� �� �����ϴ�." << endl;
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
