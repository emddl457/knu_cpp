#include <iostream>     // cout, endl 등 표준 입출력 기능을 쓰기 위한 헤더
#include <algorithm>    // sort 함수 사용하려면 필요함 (C++ 표준 라이브러리)
using namespace std;    // std:: 생략하고 cout 등 직접 쓰기 위함

class SortedArray {
    int size;  // 현재 배열에 들어 있는 요소 개수 (길이)
    int* p;    // 정수형 포인터: 동적 배열을 가리킴 (힙에 생성된 정수 배열 주소)

    void sort() {
        // 내부 정수 배열 p를 오름차순 정렬하는 멤버 함수
        // p: 정렬 대상 배열, size: 요소 개수
        std::sort(p, p + size);
        // p부터 p + size 직전까지 (즉, 배열 전체)를 오름차순 정렬
    }

public:
    SortedArray() {
        // 기본 생성자: 아무 값도 안 가진 비어 있는 배열 생성
        p = NULL;  // 포인터를 일단 아무 것도 안 가리키도록 함
        size = 0;  // 배열 크기도 0
    }

    SortedArray(int arr[], int size) {
        // 정수 배열을 전달받아 SortedArray 객체로 생성하는 생성자
        this->size = size;          // 전달받은 크기를 멤버 변수에 저장
        p = new int[size];          // 정수 배열 동적 할당 (heap 영역에 공간 생성)
        for (int i = 0; i < size; i++)
            p[i] = arr[i];          // 원본 배열 값을 새 배열로 복사
        sort();                     // 복사한 배열을 오름차순 정렬
    }

    SortedArray(SortedArray& src) {
        // 복사 생성자: 기존 SortedArray 객체를 복사해서 새 객체 만들 때 호출됨
        this->size = src.size;      // 복사 대상의 size 복사
        p = new int[size];          // 배열 새로 할당
        for (int i = 0; i < size; i++)
            p[i] = src.p[i];        // 배열 내용 복사
        // sort()는 이미 정렬돼 있으므로 다시 안 해도...되겠지?
    }

    ~SortedArray() {
        // 소멸자: 객체가 사라질 때 호출됨. 동적 할당된 배열을 해제해야 메모리 누수 안 생김
        delete[] p;  // new로 만든 배열은 delete[]로 해제해야 함
    }

    // + 연산자 오버로딩: 두 SortedArray를 합쳐서 새 SortedArray 반환
    SortedArray operator+(SortedArray& op2) {
        int* temp = new int[size + op2.size];  // 두 배열 합친 크기만큼 새로운 배열 생성

        // 첫 번째 배열 복사
        for (int i = 0; i < size; i++)
            temp[i] = p[i];

        // 두 번째 배열 복사
        for (int i = 0; i < op2.size; i++)
            temp[size + i] = op2.p[i];

        // temp 배열을 정렬된 SortedArray로 반환 (자동 정렬됨)
        SortedArray result(temp, size + op2.size);

        delete[] temp;  // 임시로 썼던 temp 배열은 더 이상 필요 없으니 해제

        return result;  // 새로 만들어진 배열을 복사본으로 리턴
    }

    // = 연산자 오버로딩: 다른 객체의 내용을 복사해서 덮어쓰기 할 때 사용
    SortedArray& operator=(const SortedArray& op2) {
        // 기존에 할당되어 있던 배열이 있다면 메모리 해제
        if (p != NULL)
            delete[] p;

        size = op2.size;            // 새 배열 크기 설정
        p = new int[size];          // 새 배열 메모리 할당
        for (int i = 0; i < size; i++)
            p[i] = op2.p[i];        // 배열 내용 복사

        return *this;               // 자기 자신 참조 반환 (연쇄 대입 가능)
    }

    void show() {
        // 배열 내용 출력하는 멤버 함수
        for (int i = 0; i < size; i++)
            cout << p[i] << " ";
        cout << endl;
    }
};

int main() {
    int a[] = { 3, 5, 1 };           // 정렬되지 않은 배열 a
    int b[] = { 2, 4 };              // 정렬되지 않은 배열 b

    SortedArray x(a, 3);           // 배열 a로부터 객체 x 생성 → 내부에서 자동 정렬됨
    SortedArray y(b, 2);           // 배열 b로부터 객체 y 생성

    SortedArray z;                 // 기본 생성자 호출 (비어있는 배열)
    z = x + y;                     // x와 y를 합친 새로운 배열을 z에 대입

    z.show();                      // 오름차순으로 정렬된 배열 확인

    return 0;
}
