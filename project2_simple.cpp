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
        void insertAtNode(int i);
        //Insert after Target.
        void insertAfterTarget(int i);
        //Clear the list.
        void clear();
        //Empty.
        bool empty() {return size == 0;}
        //Get Size.
        int getSize() {return size;}
        Node* copyList(Node* original);
        //Overloading the assignment operator.
        List& operator =(const List& rhs);
        //Merge function
        friend List merge(const List& listA, const List& listB);
        friend List mergeSort(const List& listA);
        friend ostream& operator <<(ostream& outs, List list);
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

//Helper function to copy a list.
Node* List::copyList(Node* original) {
    if(original == nullptr) {
        return nullptr;
    }
    Node* newHead = new Node;
    Node* newTail = new Node;
    newHead -> data = original -> data; 
    Node* current = newHead;
    original = original -> link;
    
    while(original != nullptr) {
        current -> link = new Node;
        current -> link -> data = original -> data;
        current  = current -> link;
        original = original -> link;
    }
    return newHead;
}

//Overloading the = operator using the copy list function.
List& List::operator =(const List& rhs) {
    if(this != &rhs) {
        clear();
        head = copyList(rhs.head);
    }
    return *this;
}


int main() {
    List l1;
    cout << "Test:\n\n";
    return 0;
}