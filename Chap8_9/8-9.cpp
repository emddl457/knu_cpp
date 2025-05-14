#include <iostream>
#include <string>
using namespace std;

// 좌석 하나를 표현하는 클래스
class Seat {
    string name; // 예약자 이름, 없으면 "---"
public:
    Seat() { name = "---"; }
    void reserve(const string& name) { this->name = name; }
    void cancel() { name = "---"; }
    string getName() const { return name; }
    bool isEmpty() const { return name == "---"; }
    void show() const { cout << name << "\t"; }
};

// 하나의 비행 시간대(07시, 12시, 17시)에 해당하는 좌석 배열
class Schedule {
    Seat seats[8]; // 좌석 8개
public:
    void reserve(int seatNum, const string& name) {
        // 좌석 번호는 0~7만 유효
        if (seatNum < 0 || seatNum >= 8) {
            cout << "좌석 번호 오류\n";
            return;
        }
        if (!seats[seatNum].isEmpty()) {
            cout << "이미 예약된 좌석입니다.\n";
        }
        else {
            seats[seatNum].reserve(name);
        }
    }

    void cancel(int seatNum, const string& name) {
        if (seatNum < 0 || seatNum >= 8) {
            cout << "좌석 번호 오류\n";
            return;
        }
        if (seats[seatNum].getName() != name) {
            cout << "예약자 이름이 일치하지 않습니다.\n";
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

// 세 개의 스케줄(07시, 12시, 17시)을 관리하는 클래스
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
        // 환영 문구는 출력하지 않음 (처음에만 출력되도록 수정됨)
        cout << "07시:\t"; schedule[0].show();
        cout << "12시:\t"; schedule[1].show();
        cout << "17시:\t"; schedule[2].show();
    }

    void showSchedule(int idx) const {
        schedule[idx].show();
    }
};

// 사용자 메뉴를 처리하는 클래스
class Console {
public:
    static void run() {
        AirlineBook book;

        // 프로그램 시작 시 환영 문구는 한 번만 출력
        cout << "***** 한성항공에 오신것을 환영합니다 *****" << endl;

        while (true) {
            int command;
            cout << "\n예약:1, 취소:2, 보기:3, 끝내기:4>> ";
            cin >> command;

            if (command == 1) {
                int timeSel, seatNum;
                string name;
                cout << "07시:1, 12시:2, 17시:3>> ";
                cin >> timeSel;

                // 해당 시간 좌석 상태 먼저 출력
                if (timeSel == 1) {
                    cout << "07시:\t"; book.showSchedule(0);
                }
                else if (timeSel == 2) {
                    cout << "12시:\t"; book.showSchedule(1);
                }
                else if (timeSel == 3) {
                    cout << "17시:\t"; book.showSchedule(2);
                }

                cout << "좌석 번호≫ ";
                cin >> seatNum;
                seatNum--; // 1~8 입력을 0~7로 변환

                cout << "이름 입력≫ ";
                cin >> name;

                book.reserve(timeSel - 1, seatNum, name);
            }

            else if (command == 2) {
                int timeSel, seatNum;
                string name;
                cout << "07시:1, 12시:2, 17시:3>> ";
                cin >> timeSel;

                if (timeSel == 1) {
                    cout << "07시:\t"; book.showSchedule(0);
                }
                else if (timeSel == 2) {
                    cout << "12시:\t"; book.showSchedule(1);
                }
                else if (timeSel == 3) {
                    cout << "17시:\t"; book.showSchedule(2);
                }

                cout << "좌석 번호≫ ";
                cin >> seatNum;
                seatNum--; // 1~8 입력을 0~7로 변환

                cout << "이름 입력≫ ";
                cin >> name;

                book.cancel(timeSel - 1, seatNum, name);
            }

            else if (command == 3) {
                book.showAll();
            }

            else if (command == 4) {
                cout << "예약 시스템을 종료합니다." << endl;
                break;
            }

            else {
                cout << "잘못된 입력입니다." << endl;
            }
        }
    }
};

int main() {
    Console::run();
    return 0;
}
