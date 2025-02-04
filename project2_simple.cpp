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
        void insertAfterTarget(int target, int i);
        int removeFromHead();
        int removeFromTail();
        bool removeFirstTarget(int target);
        //Clear the list.
        void clear();
        //Empty.
        bool empty() {return size == 0;}
        //Get Size.
        int getSize() {return size;}
        int getTail();
        //Overloading the assignment operator.
        List& operator =(const List& rhs);
        //Merge function
        friend List merge(const List& listA, const List& listB);
        friend List mergeSort(const List& list);
        friend List splash(const List& list, int begin, int end);
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
        head = nullptr;
        tail = nullptr;
        size = 0;
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
    
    Node* current = head;

    if(n >= size) {
        insertAtTail(i);
    }
    else if (n == 0) {
        insertAtHead(i);
    }
    else {
        for(int j = 0; j < n - 1; j++) {
            current = current -> link;
        }
        Node* newNode = new Node;
        newNode -> data = i;
        newNode -> link = current -> link;
        current -> link = newNode;
        size ++;
    }
}

//Insert after a specific target if the target is found.
void List::insertAfterTarget(int target, int i) {
    
    bool found(false);

    Node* current = head;
    while(current != nullptr) {
        if(current -> data == target) {
            found = true;
            break;
        }
        current = current -> link;
    }
    if(found) {
        Node* newNode = new Node;
        newNode -> data = i;
        newNode -> link = current -> link;
        //Make sure that if the target is the last element the tail is updated.
        if(tail == current) {
            tail = newNode;
        }
        current -> link = newNode;
        size ++;
    }
}

//Returns the tail if it points to something
int List::getTail() {
    if(tail) {
        return tail->data;
    }
    else return 0;
}

//Remove from head.
int List::removeFromHead() {
    if(size == 1) {
        int result = head -> data;
        head = nullptr;
        tail = nullptr;
        size = 0;
        return result;
    }
    else if(head != nullptr) {
        Node* temp = new Node;
        temp = head;
        head = head -> link;
        int result = temp -> data;
        delete temp;
        size --;
        return result;
    }
    else return 0;
}

//Remove from the tail.
int List::removeFromTail() {
    //if there is only one element.
    if(size == 1) {
        return removeFromHead();
    }
    else if(head) {
        Node* temp = new Node;
        temp = head;
        while(temp -> link -> link != nullptr) {
            temp = temp -> link;
        }
        int result = temp -> link -> data;
        delete temp -> link;
        temp -> link = nullptr;
        tail = temp;
        size --;
        return result;
    }
    else if(head -> link == nullptr) {
        return head -> data;
        delete head;
        head = nullptr;
        tail = nullptr;
        size = 0;
    }
    else {
        return 0;  
    }
}

//Remove the first occurence of a given element and return true if it has been found.
bool List::removeFirstTarget(int target) {
    bool found = false;

    Node* previous;
    Node* current = head;

    if(current == nullptr) {
        return false;
    }
    else if(current -> data == target) {
        removeFromHead();
        return true;
    }
    else {
        while(current != nullptr) {
            previous = current;
            current = current -> link;
            if (current -> data == target) {
                found = true;
                break;
            }
        }
        if(found) {
            previous -> link = current -> link;
            delete current;
            size --;
        }
        return found;
    }

}

//Overloading the assignment operator
List& List::operator =(const List& rhs) {
    //Check for self assignment.
    if(this != &rhs) {
        this -> clear();
        if(rhs.head != nullptr) {
            Node*current = rhs.head;
            while(current != nullptr) {
                this -> insertAtTail(current -> data);
                current = current -> link;
            }
        }
    }
    return *this;
}


//Overloading of <<.
ostream& operator <<(ostream& outs, const List& list) {
    Node* temp = list.head;
    int count(0);
    outs << "[";
    while(temp != nullptr) {
        outs << temp -> data;
        if(count < list.size - 1) {
            outs << " -> ";
        }
        count ++;
        temp = temp -> link;
    }
    outs << "]";
    return outs;
}

List merge(const List& listA, const List& listB) {
    List A(listA), B(listB);
    List result;
    while(A.head != nullptr && B.head != nullptr) {
        if(A.head -> data < B.head -> data) {
            result.insertAtTail(A.removeFromHead());
        } else result.insertAtTail(B.removeFromHead());
    }
    
    while(A.head != nullptr) {
        result.insertAtTail(A.removeFromHead());
    }
    while(B.head != nullptr) {
        result.insertAtTail(B.removeFromHead());
    }
    
    return result;
}

List mergeSort(const List& list) {
    List sorted(list);
    if(sorted.getSize() == 1) {
        return sorted;
    }
    return sorted;
}

List splash(const List& list, int begin, int end) {
    List result(list);
    for(int i = 0; i < begin; i ++) {
        result.removeFromHead();
    }
    for(int i = list.size; i > end; i --) {
        result.removeFromTail();
    }
    return result;
}



//Testing.
int main() {
    cout << "Test:\n\n";
    List l1;
    cout << l1.getSize() << "\n";
    cout << "insertions:\n";
    l1.insertAtHead(0);
    cout << l1 << "\n";
    l1.insertAtTail(1);
    cout << l1 << "\n";
    l1.insertAtTail(2);
    cout << l1 << "\n";
    l1.insertAtTail(3);
    cout << l1 << "\n";
    l1.insertAtHead(-1);
    cout << l1 << "\n";
    l1.insertAfterTarget(1, 5);
    cout << l1 << "\n";
    l1.insertAfterNode(1, 10);
    cout << l1 << "\n";
    l1.insertAfterTarget(3, 42);
    cout << l1 << "\n";
    l1.insertAfterTarget(3, 45);
    cout << l1 << "\n";
    l1.insertAfterTarget(42, 99);
    cout << l1 << "\n";
    l1.removeFromTail();
    cout << l1 << "\n";
    l1.clear();
    l1.insertAtHead(10);
    l1.insertAtHead(9);
    cout << l1 << "\n";
    l1.removeFromTail();
    cout << "here size is " << l1.getSize() << "\n";
    l1.removeFromTail();
    cout << l1 << "\n";
    l1.insertAtHead(0);
    cout << l1 << "\n";
    l1.insertAtTail(1);
    cout << l1 << "\n";
    l1.insertAtTail(2);
    cout << l1 << "\n";
    l1.insertAtTail(3);
    cout << l1 << "\n";
    l1.insertAtHead(-1);
    cout << l1 << "\n";
    l1.insertAfterTarget(1, 5);
    cout << l1 << "\n";
    l1.removeFirstTarget(2);
    cout << l1 << "\n";
    cout << "testing assignment operator \n";
    List l2;
    l1.clear();
    l1.insertAtHead(1);
    l2 = l1;
    l2.insertAtHead(0);
    l2.insertAtHead(-2);
    l1 = l2;
    cout << l1 << "\n";
    cout << "testing the copy constructor \n";
    List l3(l1);
    cout << l1 << "\n";
    //Reseting everything for some new tests.
    l1.clear();
    l2.clear();
    l3.clear();
    cout << l1 << l2 << l3 << "\n";

    l1.insertAtTail(1);
    l1.insertAtTail(3);
    l1.insertAtTail(7);
    l1.insertAtTail(12);

    l2.insertAtTail(1);
    l2.insertAtTail(2);
    l2.insertAtTail(6);
    l2.insertAtTail(19);
    l2.insertAtTail(20);
    l2.insertAtTail(100);
    l2.insertAtTail(101);

    cout << l1 << "\n" << l2 << "\n";

    l3 = merge(l1, l2);

    cout << l3 << "\n";

    l3.clear();

    cout << "easy population on l3 \n";

    for(int i = 0; i < 11; i++) {
        l3.insertAtTail(i);
    }

    cout << l3 << "\n";

    List l4 = splash(l3, 0, l3.getSize() / 2);
    List l5 = splash(l3, l3.getSize() / 2, l3.getSize());
    cout << "Testing the splash function: \n";
    cout << l4 << "\n";
    cout << l5.getSize() << "\n";
    cout << l5 << "\n";

    cout << "\n All good 🔄 \n";
    return 0;
}