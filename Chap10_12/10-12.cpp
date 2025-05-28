#include <iostream>
#include <vector>
#include <string>
#include <cstdlib>
#include <ctime>
using namespace std;

class Word {
    string eng;
    string kor[4];
    int correct;
public:
    Word(string eng, string kor0, string kor1, string kor2, string kor3, int correct) {
        this->eng = eng;
        kor[0] = kor0;
        kor[1] = kor1;
        kor[2] = kor2;
        kor[3] = kor3;
        this->correct = correct;
    }

    void show() {
        cout << eng << "?" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "(" << i + 1 << ") " << kor[i] << " ";
        }
        cout << ">> ";
    }

    bool check(int user) {
        return user == correct + 1;
    }
};

int main() {
    srand((unsigned int)time(0));
    vector<Word> wordList;

    // 초기 단어 등록
    wordList.push_back(Word("honey", "주식", "사진", "곰", "애인", 3));
    wordList.push_back(Word("dall", "주식", "거래", "애인", "인형", 3));
    wordList.push_back(Word("painting", "자기", "인형", "주식", "그림", 3));
    wordList.push_back(Word("stock", "애인", "거래", "곰", "주식", 3));

    cout << "***** 영어 어휘 테스트를 시작합니다. *****" << endl;

    while (true) {
        cout << "어휘 삽입 : 1, 어휘 테스트 : 2, 프로그램 종료 : 3 >> ";
        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            cout << "영어 단어에 exit을 입력하면 입력 끝" << endl;
            while (true) {
                string eng[4];
                string kor[4];

                for (int i = 0; i < 4; i++) {
                    cout << "영어 >>";
                    getline(cin, eng[i]);
                    if (eng[i] == "exit") {
                        cout << "exit를 입력하면 어휘 삽입 끝" << endl;
                        goto END_INSERT;
                    }
                    cout << "한글 >>";
                    getline(cin, kor[i]);
                }

                Word w(eng[1], kor[0], kor[1], kor[2], kor[3], 1); // 두 번째 영어 단어가 문제, 두 번째 한글 뜻이 정답
                wordList.push_back(w);
            }
        END_INSERT:;
        }

        else if (menu == 2) {
            cout << "영어 어휘 테스트를 시작합니다. 1~4 외 다른 입력시 종료." << endl;
            while (true) {
                int index = rand() % wordList.size();
                wordList[index].show();
                int answer;
                cin >> answer;
                if (cin.fail() || answer == -1) {
                    cin.clear();
                    cin.ignore(1000, '\n');
                    break;
                }
                if (wordList[index].check(answer))
                    cout << "Excellent !!" << endl;
                else
                    cout << "No !!" << endl;
            }
        }

        else if (menu == 3) {
            cout << "프로그램을 종료합니다." << endl;
            break;
        }

        else {
            cout << "1, 2, 3 중에서 선택해주세요." << endl;
        }
    }

    return 0;
}
