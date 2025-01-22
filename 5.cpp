/*
Playing around with linked lists.
*/

#include <iostream>
#include <string>
using namespace std;


class NodeType {
    public:
        NodeType();
        NodeType(string l);
        string getLetter() {return letter;}
        void setLetter(string s) {letter = s;}
        NodeType *link;
    private:
        string letter;
};
typedef NodeType* PointerType;

void insertHead(PointerType& head, string s);
void insertTail(PointerType& head, string s);
void outputList(PointerType head);


int main() {
    //Creating the head of the list.
    PointerType head = new NodeType("Head of the list.");
    //Outputing the content of the head of the list.
    cout << head -> getLetter() << endl;
    //Overwriting it.
    head->setLetter("Hello, how are you?.");
    //Outputing it.
    cout << head -> getLetter() << endl;
    //Inserting something at the begining.
    //THIS LINE DOES NOT SEEM TO WORK
    insertHead(head, "Hello, New insertion at the beginning of the list.");
    cout << head -> getLetter() << endl;
    //Adding more stuff
    insertHead(head, "Hello, Insertion 2 at the beginning of the list.");
    insertHead(head, "Hello, Insertion 3 at the beginning of the list.");
    insertHead(head, "One more insertion");
    insertTail(head, "At the end I put this");
    //Outputing the entire list.
    outputList(head);
    return 0;
}

NodeType::NodeType() {
    letter = "";
    link = nullptr;
}

NodeType::NodeType(string l) {
    letter = l;
    link = nullptr;
}

void insertHead(PointerType& head, string s) {
    PointerType temp = new NodeType(s);
    temp -> link = head;
    head = temp;
}

void insertTail(PointerType& head, string s) {
    PointerType temp = new NodeType(s);
    //In the case of an empty list.
    if (head == nullptr) {
        head = temp;
    }
    else {
        PointerType here = head;
        while (here -> link != nullptr) {
            here = here -> link;
        }
        here -> link = temp;
    }
}

void insertInPosition() {
    
}

void outputList(PointerType head) {
    PointerType iter;
    for(iter = head; iter != nullptr; iter = iter->link) {
        cout << iter -> getLetter() << endl;
    }
}