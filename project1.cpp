/*
1. Write a void function that takes a linked list of integers and reverses the
order of its nodes. The function will have one call-by-reference parameter
that is a pointer to the head of the list. After the function is called, this
pointer will point to the head of a linked list that has the same nodes as
the original list, but in the reverse of the order they had in the original list.
Note that your function will neither create nor destroy any nodes. It will
simply rearrange nodes. Place your function in a suitable test program.
*/

#include <iostream>
#include <string>
using namespace std;

class Node;
class List;
class Node {
    private:
        string data;
        Node* link;
    public:
        //simple constructor.
        Node() : data(""), link(nullptr) {}; 
        //Constructor with string parameter.
        Node(string s);
        ~Node() {};
        string const getData() {return data;}
        void setData(string s) {data = s;}
        Node* const getLink() {return link;}
        void setLink(Node* l) {link = l;}
        friend List;
};

Node::Node(string s) {
    data = s;
    link = nullptr;
}

typedef Node* nodePtr;

class List {
    private:
        nodePtr head;
        int size;
    public:
        List(): head(nullptr), size(0) {};
        ~List() {clear();}
        void insertAtHead(string data);
        void print();
        void clear();
        int getSize() {return size;}
        nodePtr const getHead() {return head;}
        void setHead(nodePtr ptr) {head = ptr;}
        void reverse();
};

void List::insertAtHead(string data) {
    nodePtr temp = new Node(data);
    if(size == 0) {
        head = temp;
    }
    else {
        temp -> link = head;
        head = temp;
    }
    size ++;
}

void List::print() {
    if(size == 0) {
        cout << "Empty list." << endl;
        return;
    }
    nodePtr temp = head;
    while (temp != nullptr) {
        cout << temp -> data << endl;
        temp = temp -> link;
    } 
}

void List::clear() {
    while(head != nullptr) {
        nodePtr temp = head;
        head = head -> link;
        delete temp;
    }
}

void List::reverse() {
    nodePtr previous(nullptr), current(head), next(nullptr);
    while(current != nullptr) {
        //Store the next one.
        next = current -> link;

        //Reverse the node pointer of the current node to point to the previous node.
        current -> link = previous;

        //Move the pointers
        previous = current;
        current = next;
    }
    head = previous;
}

nodePtr reverse(nodePtr head) {
    //Declaring and initializing the pointers.
    nodePtr previous(nullptr), current(head), next(nullptr);
    while (current != nullptr) {
        //Store the next one
        next = current->getLink();

        //Reverse the node pointer of the current Node;
        current->setLink(previous);

        //Move the pointers 
        previous = current;
        current = next;
    }
    return previous;
}

int main() {
    List l;
    cout << "Testing program" << endl;
    l.insertAtHead("first");
    l.insertAtHead("second");
    l.insertAtHead("third");
    l.insertAtHead("fourth");
    l.print();
    cout << "Clearing the list" << endl;
    l.clear();
    l.clear();
    l.print();
    l.insertAtHead("first");
    l.insertAtHead("second");
    l.insertAtHead("third");
    l.insertAtHead("fourth");
    l.print();
    cout << "Testing the reverse function:" << endl;
    l.setHead(reverse(l.getHead()));
    l.print();
    cout << "Reversing again:" << endl;
    l.reverse();
    l.print();
    return 0;
}