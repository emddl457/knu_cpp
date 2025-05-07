#include <iostream>  // 입출력 사용을 위해 포함
using namespace std; // std:: 생략하고 cout, endl 등을 바로 쓰기 위해

class Color {
    int red, green, blue; // RGB 각각의 색상 성분 값을 저장할 변수

public:
    // 생성자: Color 객체를 만들 때 RGB 값을 초기화함
    Color() : red(0), green(0), blue(0) {}
    Color(int r, int g, int b) : red(r), green(g), blue(b) {}

    // show 함수: 현재 Color 객체의 RGB 값을 화면에 출력함
    void show() {
        cout << red << " " << green << " " << blue << endl;
    }

    // + 연산자 오버로딩 (멤버 함수)
    // 두 색을 더해서 새로운 Color 객체를 반환함
    Color operator+(const Color& c) {
        // 각 성분을 더하되, 255 초과 시 255로 제한 (RGB 최대값은 255)
        int r = (red + c.red > 255) ? 255 : red + c.red;
        int g = (green + c.green > 255) ? 255 : green + c.green;
        int b = (blue + c.blue > 255) ? 255 : blue + c.blue;

        // 계산한 r, g, b를 기반으로 새 Color 객체 생성해 리턴
        return Color(r, g, b);
    }

    // == 연산자 오버로딩 (프렌드 함수)
    // 두 Color 객체의 RGB 값이 모두 같으면 true 반환
    friend bool operator==(const Color& a, const Color& b) {
        return a.red == b.red && a.green == b.green && a.blue == b.blue;
        // RGB 각각이 일치해야만 true
    }
};

int main() {
    // red: 빨강 (255, 0, 0), blue: 파랑 (0, 0, 255)
    Color red(255, 0, 0), blue(0, 0, 255), c;

    // red와 blue를 더한 값을 c에 저장함 (보라색이 되길 기대)
    c = red + blue;

    // c 색상 값 출력 (255 0 255가 나와야 보라색)
    c.show();

    // 비교할 보라색 객체 생성 (기댓값: (255, 0, 255))
    Color fuchsia(255, 0, 255);

    // c와 fuchsia가 같은 색상인지 비교
    if (c == fuchsia) // == 연산자 오버로딩 함수가 호출됨
        cout << "보라색 맞음" << endl;
    else
        cout << "보라색 아님" << endl;

    return 0;
}

// 외울 개념들... operator+는 두 색상의 합을 구하는 연산자 오버로딩. 새 색상 객체를 반환.
// operator==는 두 색상이 같은지 비교하는 연산자 오버로딩. true/false 반환. (RGB 값이 모두 같아야 true)
// friend는 클래스 외부 함수지만 private 멤버에 접근할 수 있게 해주는 키워드.
// show()는 RGB 값을 출력하는 멤버 함수. Color 객체의 상태를 보여줌.
