#include <iostream>
#include <string>
using namespace std;

// �¼� �ϳ��� ǥ���ϴ� Ŭ����
class Seat {
    string name; // ������ �̸�, ������ "---"
public:
    Seat() { name = "---"; }
    void reserve(const string& name) { this->name = name; }
    void cancel() { name = "---"; }
    string getName() const { return name; }
    bool isEmpty() const { return name == "---"; }
    void show() const { cout << name << "\t"; }
};

// �ϳ��� ���� �ð���(07��, 12��, 17��)�� �ش��ϴ� �¼� �迭
class Schedule {
    Seat seats[8]; // �¼� 8��
public:
    void reserve(int seatNum, const string& name) {
        // �¼� ��ȣ�� 0~7�� ��ȿ
        if (seatNum < 0 || seatNum >= 8) {
            cout << "�¼� ��ȣ ����\n";
            return;
        }
        if (!seats[seatNum].isEmpty()) {
            cout << "�̹� ����� �¼��Դϴ�.\n";
        }
        else {
            seats[seatNum].reserve(name);
        }
    }

    void cancel(int seatNum, const string& name) {
        if (seatNum < 0 || seatNum >= 8) {
            cout << "�¼� ��ȣ ����\n";
            return;
        }
        if (seats[seatNum].getName() != name) {
            cout << "������ �̸��� ��ġ���� �ʽ��ϴ�.\n";
        }
        else {
            seats[seatNum].cancel();
        }
    }

    void show() const {
        for (int i = 0; i < 8; i++) {
            seats[i].show();
        }
        cout << endl;
    }
};

// �� ���� ������(07��, 12��, 17��)�� �����ϴ� Ŭ����
class AirlineBook {
    Schedule schedule[3];
public:
    void reserve(int timeIdx, int seatNum, const string& name) {
        schedule[timeIdx].reserve(seatNum, name);
    }

    void cancel(int timeIdx, int seatNum, const string& name) {
        schedule[timeIdx].cancel(seatNum, name);
    }

    void showAll() const {
        // ȯ�� ������ ������� ���� (ó������ ��µǵ��� ������)
        cout << "07��:\t"; schedule[0].show();
        cout << "12��:\t"; schedule[1].show();
        cout << "17��:\t"; schedule[2].show();
    }

    void showSchedule(int idx) const {
        schedule[idx].show();
    }
};

// ����� �޴��� ó���ϴ� Ŭ����
class Console {
public:
    static void run() {
        AirlineBook book;

        // ���α׷� ���� �� ȯ�� ������ �� ���� ���
        cout << "***** �Ѽ��װ��� ���Ű��� ȯ���մϴ� *****" << endl;

        while (true) {
            int command;
            cout << "\n����:1, ���:2, ����:3, ������:4>> ";
            cin >> command;

            if (command == 1) {
                int timeSel, seatNum;
                string name;
                cout << "07��:1, 12��:2, 17��:3>> ";
                cin >> timeSel;

                // �ش� �ð� �¼� ���� ���� ���
                if (timeSel == 1) {
                    cout << "07��:\t"; book.showSchedule(0);
                }
                else if (timeSel == 2) {
                    cout << "12��:\t"; book.showSchedule(1);
                }
                else if (timeSel == 3) {
                    cout << "17��:\t"; book.showSchedule(2);
                }

                cout << "�¼� ��ȣ�� ";
                cin >> seatNum;
                seatNum--; // 1~8 �Է��� 0~7�� ��ȯ

                cout << "�̸� �Է¡� ";
                cin >> name;

                book.reserve(timeSel - 1, seatNum, name);
            }

            else if (command == 2) {
                int timeSel, seatNum;
                string name;
                cout << "07��:1, 12��:2, 17��:3>> ";
                cin >> timeSel;

                if (timeSel == 1) {
                    cout << "07��:\t"; book.showSchedule(0);
                }
                else if (timeSel == 2) {
                    cout << "12��:\t"; book.showSchedule(1);
                }
                else if (timeSel == 3) {
                    cout << "17��:\t"; book.showSchedule(2);
                }

                cout << "�¼� ��ȣ�� ";
                cin >> seatNum;
                seatNum--; // 1~8 �Է��� 0~7�� ��ȯ

                cout << "�̸� �Է¡� ";
                cin >> name;

                book.cancel(timeSel - 1, seatNum, name);
            }

            else if (command == 3) {
                book.showAll();
            }

            else if (command == 4) {
                cout << "���� �ý����� �����մϴ�." << endl;
                break;
            }

            else {
                cout << "�߸��� �Է��Դϴ�." << endl;
            }
        }
    }
};

int main() {
    Console::run();
    return 0;
}
