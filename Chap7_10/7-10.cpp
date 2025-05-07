#include <iostream>  // 입출력을 위한 헤더파일 (cin, cout 사용하려면 필수)
using namespace std; // std:: 생략하고 cin, cout 등 바로 사용하기 위해

// 통계 데이터를 저장하고 처리하는 클래스 선언
class Statistics {
    int* data;     // 정수 데이터를 저장할 동적 배열 포인터 (int 배열을 가리킴)
    int size;      // 현재 저장된 정수의 개수 (통계에 몇 개 입력됐는지)
    int capacity;  // 저장 가능한 최대 개수 (예: 100개까지 가능)

public:
    // 생성자: 객체가 만들어질 때 자동 호출됨
    Statistics() {
        capacity = 100;               // 저장 가능한 최대 개수 100개로 설정
        size = 0;                     // 처음에는 아무 데이터도 없으니 0
        data = new int[capacity];     // int형 배열을 heap 메모리에 동적 할당
        // new int[capacity]: 정수 100개짜리 배열을 동적으로 생성하고 그 주소를 data에 저장
    }

    // 소멸자: 객체가 소멸될 때 호출됨. 동적 메모리를 해제할 때 사용
    ~Statistics() {
        delete[] data; // new로 만든 배열은 반드시 delete[]로 해제해야 함
        // delete[]: 배열 삭제. 단일 변수는 delete, 배열은 delete[] 사용
    }

    // operator>> 연산자 오버로딩
    // 사용자가 '정수 >> Statistics 객체' 형태로 입력할 수 있게 해줌
    friend Statistics& operator>>(int value, Statistics& stat) {
        // friend 함수: 클래스 외부 함수지만 private 멤버(data, size 등)에 접근 가능함
        // 참고로 int >> 객체 형태는 클래스 멤버 함수로는 못 만듦 → 반드시 friend 함수여야 함

        if (stat.size < stat.capacity) {
            stat.data[stat.size++] = value;
            // data[size]에 값 저장 후 size 1 증가
        }
        return stat; // 연산 결과로 stat을 그대로 반환 (연쇄 입력 가능)
    }

    // operator<< 연산자 오버로딩
    // '통계 객체 << 평균 저장 변수' 형식으로 평균을 구해 저장할 수 있게 함
    friend Statistics& operator<<(Statistics& stat, int& avg) {
        if (stat.size == 0) {
            avg = 0; // 데이터가 하나도 없으면 평균은 0으로 처리
        }
        else {
            int sum = 0;
            for (int i = 0; i < stat.size; i++)
                sum += stat.data[i]; // 배열 전체를 순회하며 합계 계산
            avg = sum / stat.size;   // 평균 = 총합 / 개수
            // 주의: 정수 나눗셈이라 소수점은 버림됨 (예: 6/4 = 1)
        }
        return stat; // 반환은 통계 객체 stat 자체 (연쇄 가능)
    }

    // ~ 연산자 오버로딩
    // '~통계객체' 형태로 호출하면 데이터를 전부 삭제함
    friend void operator~(Statistics& stat) {
        stat.size = 0; // 실제 배열 메모리는 남아있지만 데이터는 0개로 간주함
    }

    // ! 연산자 오버로딩
    // '!통계객체' 형태로 통계가 비어있는지를 확인 (true면 비어 있음)
    friend bool operator!(Statistics& stat) {
        return stat.size == 0; // 비어있으면 true, 아니면 false
    }
};

int main() {
    Statistics stat; // 통계를 저장할 Statistics 객체 생성 (생성자 호출됨)

    if (!stat) // 데이터가 비어 있는지 확인 (operator! 호출)
        cout << "현재 통계 데이터가 없습니다." << endl;

    int x[5]; // 정수 5개를 저장할 배열 선언 (이름 x, 타입은 int[5])
    // 여기서 x는 그냥 통계 입력을 받기 위한 중간 저장 공간.

    cout << "5개의 정수를 입력하라>> ";
    for (int i = 0; i < 5; i++)
        cin >> x[i]; // 사용자로부터 5개 정수 입력받아서 배열에 저장

    for (int i = 0; i < 5; i++)
        x[i] >> stat;
    // 정수 >> 통계객체 형식으로 넣음 (연산자 >> 오버로딩됨)

    100 >> stat; // 추가로 100을 통계에 입력
    200 >> stat; // 추가로 200도 입력

    //~stat; // 주석처리: 이걸 실행하면 데이터가 다 사라져서 평균이 0이 됨

    int avg;
    stat << avg; // 통계 객체에서 평균값을 avg에 저장 (operator<< 호출)
    cout << "avg = " << avg << endl; // 평균 출력

    return 0;
}

