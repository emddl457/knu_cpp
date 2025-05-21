#include <iostream>
using namespace std;

class Shape {
protected:
    Shape* next;

public:
    Shape() { next = NULL; }
    virtual void draw() = 0; // 순수 가상 함수
    Shape* getNext() { return next; }
    void setNext(Shape* p) { next = p; }
    virtual ~Shape() {}
};

class Line : public Shape {
public:
    void draw() override {
        cout << "Line" << endl;
    }
};

class Circle : public Shape {
public:
    void draw() override {
        cout << "Circle" << endl;
    }
};

class Rect : public Shape {
public:
    void draw() override {
        cout << "Rectangle" << endl;
    }
};

class GraphicEditor {
    Shape* pStart; // 연결 리스트의 시작
    Shape* pLast;  // 연결 리스트의 끝

public:
    GraphicEditor() {
        pStart = NULL;
        pLast = NULL;
    }

    void insert() {
        int sel;
        cout << "선:1, 원:2, 사각형:3 >> ";
        cin >> sel;

        Shape* shape = nullptr;

        switch (sel) {
        case 1: shape = new Line(); break;
        case 2: shape = new Circle(); break;
        case 3: shape = new Rect(); break;
        default: cout << "잘못된 선택입니다.\n"; return;
        }

        if (pStart == NULL)
            pStart = pLast = shape;
        else {
            pLast->setNext(shape);
            pLast = shape;
        }
    }

    void remove() {
        int index;
        cout << "삭제하고자 하는 도형의 인덱스 >> ";
        cin >> index;

        if (pStart == NULL) {
            cout << "삭제할 도형이 없습니다.\n";
            return;
        }

        Shape* current = pStart;
        Shape* previous = NULL;

        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->getNext();
            if (current == NULL) {
                cout << "삭제할 수 없습니다.\n";
                return;
            }
        }

        if (previous == NULL) {
            // 첫 번째 도형 삭제
            pStart = current->getNext();
            if (pStart == NULL) pLast = NULL; // 마지막 도형이었을 경우
        }
        else {
            previous->setNext(current->getNext());
            if (current == pLast) pLast = previous;
        }

        delete current;
    }

    void show() {
        Shape* current = pStart;
        int index = 0;

        while (current != NULL) {
            cout << index++ << ": ";
            current->draw();
            current = current->getNext();
        }
    }

    void run() {
        cout << "그래픽 에디터입니다.\n";
        while (true) {
            int cmd;
            cout << "삽입:1, 삭제:2, 모두보기:3, 종료:4 >> ";
            cin >> cmd;
            switch (cmd) {
            case 1: insert(); break;
            case 2: remove(); break;
            case 3: show(); break;
            case 4: return;
            default: cout << "잘못된 명령입니다.\n";
            }
        }
    }

    ~GraphicEditor() {
        // 남은 도형 모두 정리
        while (pStart != NULL) {
            Shape* temp = pStart;
            pStart = pStart->getNext();
            delete temp;
        }
    }
};

int main() {
    GraphicEditor editor;
    editor.run();
    return 0;
}
