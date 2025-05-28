#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> v;  // 정수 벡터 생성
    int input;

    while (true) {
        cout << "정수를 입력하세요(0을 입력하면 종료)>>";
        cin >> input;

        if (input == 0)
            break;

        v.push_back(input);  // 입력값 벡터에 추가

        // 전체 벡터 출력
        for (int i = 0; i < v.size(); i++) {
            cout << v[i] << ' ';
        }
        cout << endl;

        // 평균 계산
        int sum = 0;
        for (int i = 0; i < v.size(); i++) {
            sum += v[i];
        }
        double average = static_cast<double>(sum) / v.size();
        cout << "평균 = " << average << endl;
    }

    return 0;
}
