#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
#include <sstream>
using namespace std;

class Nation {
    string nation;
    string capital;
public:
    Nation(string nation, string capital) {
        this->nation = nation;
        this->capital = capital;
    }
    string getNation() { return nation; }
    string getCapital() { return capital; }
};

int main() {
    vector<Nation> v;

    v.push_back(Nation("대한민국", "서울"));
    v.push_back(Nation("미국", "워싱턴"));
    v.push_back(Nation("일본", "도쿄"));
    v.push_back(Nation("중국", "베이징"));
    v.push_back(Nation("프랑스", "파리"));
    v.push_back(Nation("영국", "런던"));
    v.push_back(Nation("독일", "베를린"));
    v.push_back(Nation("이탈리아", "로마"));
    v.push_back(Nation("스페인", "마드리드"));

    srand((unsigned int)time(0));
    int inputCount = 0, quizCount = 0, endCount = 0;
    int inputIndex = 10;

    cout << "***** 나라의 수도 맞추기 게임을 시작합니다. *****\n";

    while (true) {
        cout << "정보입력: 1, 퀴즈: 2, 종료: 3 >> ";
        int menu;
        cin >> menu;

        if (cin.fail()) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "숫자만 입력해주세요.\n";
            continue;
        }
        cin.ignore(); // 버퍼 정리

        if (menu == 1) {
            cout << "현재 " << v.size() << "개 나라가 입력되어 있습니다.\n";

            while (true) {
                cout << inputIndex++ << ">>";
                string line;
                getline(cin, line);
                istringstream iss(line);
                string country, capital;
                iss >> country >> capital;

                if (country == "no" && capital == "no") {
                    break;  // 바로 메뉴 복귀
                }

                if (country.empty() || capital.empty()) {
                    cout << "나라와 수도를 정확히 입력해주세요.\n";
                    continue;
                }

                bool exists = false;
                for (auto& n : v) {
                    if (n.getNation() == country) {
                        exists = true;
                        break;
                    }
                }

                if (exists) {
                    cout << "already exists !!\n";
                }
                else {
                    v.push_back(Nation(country, capital));
                    inputCount++;
                }
            }
        }

        else if (menu == 2) {
            while (true) {
                int index = rand() % v.size();
                cout << v[index].getNation() << "의 수도는?>> ";
                string answer;
                getline(cin, answer);
                quizCount++;

                if (answer == "exit") {
                    cout << "퀴즈 종료\n";
                    endCount++;
                    break;
                }

                if (answer == v[index].getCapital()) {
                    cout << "Correct !!\n";
                }
                else {
                    cout << "NO !!\n";
                }
            }
        }

        else if (menu == 3) {
            cout << "프로그램을 종료합니다.\n";
            break;
        }

        else {
            cout << "1, 2, 3 중 하나를 입력해주세요.\n";
        }
    }

    return 0;
}
