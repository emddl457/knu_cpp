#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, int> scores;
    string name;
    int score;

    cout << "***** 점수관리 프로그램 HIGH SCORE를 시작합니다 *****" << endl;

    while (true) {
        cout << "입력:1, 조회:2, 종료:3 >> ";
        int menu;
        cin >> menu;
        cin.ignore(); // 개행 제거

        if (menu == 1) {
            cout << "이름과 점수 >> ";
            cin >> name >> score;
            cin.ignore();
            scores[name] = score;
        }
        else if (menu == 2) {
            cout << "이름 >> ";
            getline(cin, name);
            if (name == "최고수") {
                // 최고 점수 찾기
                int maxScore = -1;
                string maxName;
                for (auto& p : scores) {
                    if (p.second > maxScore) {
                        maxScore = p.second;
                        maxName = p.first;
                    }
                }
                cout << "최고수의 점수는 " << maxScore << endl;
            }
            else {
                if (scores.find(name) != scores.end()) {
                    cout << name << "의 점수는 " << scores[name] << endl;
                }
                else {
                    cout << name << "의 점수를 찾을 수 없습니다." << endl;
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
