#include <iostream>
using namespace std;

class Shape {
protected:
    Shape* next;

public:
    Shape() { next = NULL; }
    virtual void draw() = 0; // ���� ���� �Լ�
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
    Shape* pStart; // ���� ����Ʈ�� ����
    Shape* pLast;  // ���� ����Ʈ�� ��

public:
    GraphicEditor() {
        pStart = NULL;
        pLast = NULL;
    }

    void insert() {
        int sel;
        cout << "��:1, ��:2, �簢��:3 >> ";
        cin >> sel;

        Shape* shape = nullptr;

        switch (sel) {
        case 1: shape = new Line(); break;
        case 2: shape = new Circle(); break;
        case 3: shape = new Rect(); break;
        default: cout << "�߸��� �����Դϴ�.\n"; return;
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
        cout << "�����ϰ��� �ϴ� ������ �ε��� >> ";
        cin >> index;

        if (pStart == NULL) {
            cout << "������ ������ �����ϴ�.\n";
            return;
        }

        Shape* current = pStart;
        Shape* previous = NULL;

        for (int i = 0; i < index; i++) {
            previous = current;
            current = current->getNext();
            if (current == NULL) {
                cout << "������ �� �����ϴ�.\n";
                return;
            }
        }

        if (previous == NULL) {
            // ù ��° ���� ����
            pStart = current->getNext();
            if (pStart == NULL) pLast = NULL; // ������ �����̾��� ���
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
        cout << "�׷��� �������Դϴ�.\n";
        while (true) {
            int cmd;
            cout << "����:1, ����:2, ��κ���:3, ����:4 >> ";
            cin >> cmd;
            switch (cmd) {
            case 1: insert(); break;
            case 2: remove(); break;
            case 3: show(); break;
            case 4: return;
            default: cout << "�߸��� ����Դϴ�.\n";
            }
        }
    }

    ~GraphicEditor() {
        // ���� ���� ��� ����
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
