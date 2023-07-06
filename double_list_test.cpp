#include <iostream>

using namespace std;

// 노드 struct 구현 (data, prevNode, nextNode 존재)
struct node {
    string strData;
    node* pStPrev;
    node* pstNext;
};

// 더블 링크드 리스트 클래스 생성
class DLinkedList {
    private:
        node* head;
        node* tail;

    public:
        DLinkedList() {
            head = new node;
            tail = new node;

            head->pstNext = tail;
            tail->pStPrev = head;
        };
        
        ~DLinkedList() {
            while(!isEmpty()) removeFront();
            delete head;
            delete tail;
        }; // create empty list

        bool isEmpty() const;
        const string& getFront() const;
        const string& getBack() const;
        void addFront(const string& e);
        void addBack(const string& e);
        void removeFront();
        void removeBack();
        void TraverseForward();
        void TraverseBackward();

    protected: // local utilities
        void add(node* v, const string& e);
        void remove(node* v);
};

bool DLinkedList::isEmpty() const {
    if (head->pstNext == tail);
}

const string& DLinkedList::getFront() const {
    return head->pstNext->strData;
}

const string& DLinkedList::getBack() const {
    return tail->pStPrev->strData;
}

void DLinkedList::addFront(const string& e) {
    add(head, e);
}

void DLinkedList::addBack(const string& e) {
    add(tail->pStPrev, e);
}


// Insert new node after v
void DLinkedList::add(node* v, const string& e) {
    node* u = new node;
    u->strData = e;
    u->pstNext = v->pstNext;
    u->pStPrev = v;

    v->pstNext->pStPrev = u;
    v->pstNext = u;
}


void DLinkedList::removeFront() {
    remove(head->pstNext);
}

void DLinkedList::removeBack() {
    remove(tail->pStPrev);
}

void DLinkedList::remove(node* v) {
    node* u = v->pStPrev;
    node* w = v->pstNext;
    u->pstNext = w;
    w->pStPrev = u;
    delete v;
}

void DLinkedList::TraverseForward() {
    node* v = head->pstNext;
    while(v->pstNext != NULL) {
        cout << v->strData << " ";
        v = v->pstNext;
    }
}

void DLinkedList::TraverseBackward() {
    node* v = tail->pStPrev;
    while(v->pStPrev != NULL) {
        cout << v->strData << " ";
        v = v->pStPrev;
    }
}

int main (void) {
    DLinkedList* DL = new DLinkedList();

    DL->addFront("3");
    DL->addFront("5");
    DL->addFront("8");
    DL->addFront("10");

    // 3 -> 5 -> 8 -> 10
    DL->TraverseBackward();

    cout << endl;

    // 10 -> 8 -> 5 -> 3
    DL->TraverseForward();

    cout << endl;

    DL->removeBack();
    DL->removeBack();

    // 10 -> 8
    DL->TraverseForward();
    cout << endl;    

    return EXIT_SUCCESS;
}