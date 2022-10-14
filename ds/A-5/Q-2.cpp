#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* prev ;
    node() {
        this->val = 0;
        this->prev = NULL;
    }

    node(int data) {
        this->val = data;
        this->prev = NULL;
    }
};

class Queue {
public:
    node* head;
    node* last;

    Queue() {
        head = NULL;
        last = NULL;
    }

    Queue(node* ptr) {
        head = ptr ;
        last = ptr ;
    }

    void insert(int val);
    void pop();
    void show();
    bool isEmpty();

};


class stack : public Queue {
public:

    stack() {
        head = NULL;
        last = NULL;
    }

    stack(node* ptr) {
        head = ptr ;
        last = ptr ;
    }

    void push(int val);




};



int main() {

    stack q;

    int ans;

    do
    {
        cout << "\n\n1. push" << "\n" << "2. pop\n" << "3. show\n" << "4. isEmpty\n" << "Enter your ans :  ";
        cin >> ans;
        switch (ans)
        {
        case 1:
            int val;
            cout << "Enter val : ";
            cin >> val;
            q.push(val);
            break;

        case 2:
            q.pop();
            break;
        case 3:
            q.show() ;
            break;

        case 4:
            cout << ((q.isEmpty()) ? "YES\n" : "NO\n");

        default:
            break;
        }
    } while (ans != 0);


    return 0;
}


void Queue:: insert(int val) {

    node *ptr = new node(val);

    if (head == NULL) {
        this->head = ptr ;
        this->last = ptr ;
        return ;
    }

    ptr->prev = last;
    this->last = ptr;

}

void Queue::pop() {
    if (this->last == NULL) {
        cout << "Underflow !! \n";
        return ;
    }
    this->last = this->last->prev;

    if (this->last == NULL) this->head = NULL;

}

void Queue:: show() {
    node* ptr = this->last ;

    while (ptr != NULL) {
        cout << ptr->val << " ";
        ptr = ptr->prev;
    }

    cout << endl;
}

bool Queue::isEmpty() {
    return (this->head == NULL && this->last == NULL) ;
}



void stack :: push(int val) {
    node* ptr = new node(val);
    ptr->prev = this->last ;
    this->last = ptr ;

}
