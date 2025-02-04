#include<iostream>
using std::cout;
using std::ostream;
using std::cin;
using std::istream;

class Node;
class List;

////////////////////////////////////////////////////////////////////////////////////////////////////NODE
class Node {
    private:
        int data;
        Node* link;
    public:
        Node() : data(0), link(nullptr) {}
        Node(int i) : data(i), link(nullptr) {}
        Node(const Node& original);
        ~Node() {}
        //Overloading =
        Node& operator =(const Node& rhs);
        //Overloading <<
        friend ostream& operator <<(ostream& outs, const Node& node);
        friend ostream& operator <<(ostream& outs, const List& list);
        friend istream& operator >>(istream& ins, List& list);
        friend List merge(const List& listA, const List& listB);

        friend class List;
};
////////////////////////////////////////////////////////////////////////////////////////////////////NODE

////////////////////////////////////////////////////////////////////////////////////////////////////LIST
class List {
    private:
        Node* head;
        Node* tail;
        int size;
    public:
        List() : head(nullptr), tail(nullptr), size(0) {}
        List(const List& original) : head(nullptr), tail(nullptr), size(0) {*this = original;}
        ~List() {clear();}

        //Members functions.
        void insertAtHead(int i);
        void insertAtTail(int i);
        int removeFromHead();
        int removeFromTail();
        void clear();
        bool empty() {return size == 0;}
        int getSize() {return size;}
        List& operator =(const List& rhs);
        friend ostream& operator <<(ostream& outs, const List& list);
        friend istream& operator >>(istream& ins, List& list);
        friend List merge(const List& listA, const List& listB);
        friend class Node;
};

//Function to insert at the head.
void List::insertAtHead(int i) {
    Node* newNode = new Node(i);
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

//Function to insert at the tail.
void List::insertAtTail(int i) {
    Node* newNode = new Node(i);
    if(head == nullptr) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail -> link = newNode;
        tail = newNode;
    }
    size ++;
}

//Remove from the head of the list.
int List::removeFromHead() {
    int result;
    if(size == 1) {
        result = head -> data;
        clear();
        return result;
    }
    else if(head) {
        Node* temp = head;
        head = head -> link;
        result = temp -> data;
        delete temp;
        size --;
    } else result = 0;
    return result;
}

//Remove from the tail of the list.
int List::removeFromTail() {
    int result;
    if(size == 1) {
        return removeFromHead();
    }
    else if(head) {
        result = tail -> data;
        Node* temp = head;
        while(temp -> link -> link) {
            temp = temp -> link;     
        }
        result = temp -> link -> data;
        delete temp -> link;
        temp -> link = nullptr;
        tail = temp;
        size --;
        return result;
    } else return 0;
}

//Function to clear the whole list
void List::clear() {
    while(head) {
        Node* temp = head;
        head = head -> link;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Nice assignment operator.
List& List::operator =(const List& rhs) {
    if(this != &rhs) {
        Node* current = rhs.head;
        clear();
        while(current) {
            this->insertAtTail(current->data);
            current = current -> link;
        }
    }
    return *this;
}

ostream& operator <<(ostream& outs, const List& list) {
    Node* temp = list.head;
    int count(0);
    outs << "[";
    while(temp) {
        outs << temp -> data;
        if(count < list.size - 1) {
            outs << " -> ";
        }
        temp = temp -> link;
        count ++;
    }
    outs << "]";
    return outs;
}

istream& operator >>(istream& ins, List& list) {
    int i;
    ins >> i;
    list.insertAtTail(i);
    return ins;
}

List merge(const List& listA, const List& listB) {
    List result;
    List A(listA), B(listB);
    while(A.head && B.head) {
        if(A.head -> data < B.head -> data) {
            result.insertAtTail(A.removeFromHead());
        } else result.insertAtTail(B.removeFromHead());
    }
    //Copy the rest
    while(A.head) {
        result.insertAtTail(A.removeFromHead());
    }
    while(B.head) {
        result.insertAtTail(B.removeFromHead());
    }
    return result;
}
////////////////////////////////////////////////////////////////////////////////////////////////////LIST

int main() {
    List l1, l2;

    for(int i = 0; i < 5; i++) {
        cin >> l1;
    }
    cout << "l2 \n";

    for(int i = 0; i < 5; i++) {
        cin >> l2;
    }
    cout << l1 << "\n"; 
    cout << l2 << "\n";
    List l3 = merge (l1, l2);
    cout << l3 << "\n";
    return 0;
}





/*
//This time I understood how to overload the assignment operator for a linked list.
//And it is way easier if there is a tail pointer I think.
List& List::operator =(const List& rhs) {
    if(this != &rhs) {
        clear();
        Node* current = rhs.head;
        while(current) {
            Node* newNode = new Node(current -> data);
            if(head == nullptr) {
                head = newNode;
                tail = newNode;
            }
            else {
                tail -> link = newNode;
                tail = newNode;
            }
            size ++;
            current = current -> link;
        }
    }
    return *this;
}
*/