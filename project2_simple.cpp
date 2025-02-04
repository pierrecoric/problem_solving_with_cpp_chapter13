/*
Simple version with just a struct for the nodes. No template.
Functions of the list:
Constructors
Copy constructor
Destructor
Insert at Head.
Insert at tail.
Clear function
empty
size
Insert after a specific Node
Merge Sort of the list?
Merge.
Reverse.
Overloading the assignment operator.
*/

#include <iostream>
using std::cout;
using std::ostream;

struct Node {
    int data;
    Node* link;
};

class List {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        //Default constructor.
        List() : head(nullptr), tail(nullptr), size(0) {}
        //Copy constructor.
        List(const List& original) : head(nullptr), tail(nullptr), size(0) {*this = original;}
        ~List() {clear();}

        //Members function.
        //Insert at Head.
        void insertAtHead(int i);
        //Insert at Tail.
        void insertAtTail(int i);
        //Insert at Node.
        void insertAfterNode(int n, int i);
        //Insert after Target.
        void insertAfterTarget(int i);
        //Clear the list.
        void clear();
        //Empty.
        bool empty() {return size == 0;}
        //Get Size.
        int getSize() {return size;}
        //Overloading the assignment operator.
        List& operator =(const List& rhs);
        //Merge function
        friend List merge(const List& listA, const List& listB);
        friend List mergeSort(const List& listA);
        friend ostream& operator <<(ostream& outs, const List& list);
};

//Clear function.
void List::clear() {
    //While the head of the list is not pointing to nullptr.
    while(head != nullptr) {
        //Create a temporary node that is pointing at the head of the list.
        Node* temp = head;
        //Moving the head pointer to advance through the list.
        head = head -> link;
        //Delete the temporary node.
        delete temp;
    }
}

//Insert at Head.
void List::insertAtHead(int i) {
    Node* newNode = new Node;
    newNode -> data = i;
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        newNode -> link = head;
        head = newNode;
    }
    size ++;
}
//Insert at Tail.
void List::insertAtTail(int i) {
    Node* newNode = new Node;
    newNode -> data = i;
    if(tail == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> link = newNode;
        tail = newNode;
    }
    size ++;
}

void List::insertAfterNode(int n, int i) {
    Node* newNode = new Node;
    newNode -> data = i;
}

//Overloading of <<.
ostream& operator <<(ostream& outs, const List& list) {
    Node* temp = list.head;
    int count(0);
    while(temp != nullptr) {
        outs << temp -> data;
        if(count < list.size - 1) {
            outs << ", ";
        }
        count ++;
        temp = temp -> link;
    }
    return outs;
}

int main() {
    List l1;
    l1.insertAtHead(0);
    l1.insertAtTail(1);
    l1.insertAtTail(2);
    l1.insertAtTail(3);
    l1.insertAtHead(-1);
    cout << "Test:\n\n";
    cout << l1 << "\n";
    return 0;
}