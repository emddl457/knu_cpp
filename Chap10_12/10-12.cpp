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

    // �ʱ� �ܾ� ���
    wordList.push_back(Word("honey", "�ֽ�", "����", "��", "����", 3));
    wordList.push_back(Word("dall", "�ֽ�", "�ŷ�", "����", "����", 3));
    wordList.push_back(Word("painting", "�ڱ�", "����", "�ֽ�", "�׸�", 3));
    wordList.push_back(Word("stock", "����", "�ŷ�", "��", "�ֽ�", 3));

    cout << "***** ���� ���� �׽�Ʈ�� �����մϴ�. *****" << endl;

    while (true) {
        cout << "���� ���� : 1, ���� �׽�Ʈ : 2, ���α׷� ���� : 3 >> ";
        int menu;
        cin >> menu;
        cin.ignore();

        if (menu == 1) {
            cout << "���� �ܾ exit�� �Է��ϸ� �Է� ��" << endl;
            while (true) {
                string eng[4];
                string kor[4];

                for (int i = 0; i < 4; i++) {
                    cout << "���� >>";
                    getline(cin, eng[i]);
                    if (eng[i] == "exit") {
                        cout << "exit�� �Է��ϸ� ���� ���� ��" << endl;
                        goto END_INSERT;
                    }
                    cout << "�ѱ� >>";
                    getline(cin, kor[i]);
                }

                Word w(eng[1], kor[0], kor[1], kor[2], kor[3], 1); // �� ��° ���� �ܾ ����, �� ��° �ѱ� ���� ����
                wordList.push_back(w);
            }
        END_INSERT:;
        }

        else if (menu == 2) {
            cout << "���� ���� �׽�Ʈ�� �����մϴ�. 1~4 �� �ٸ� �Է½� ����." << endl;
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
            cout << "���α׷��� �����մϴ�." << endl;
            break;
        }

        else {
            cout << "1, 2, 3 �߿��� �������ּ���." << endl;
        }
    }

    return 0;
}
