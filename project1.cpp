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
using std::cout;
using std::cin;
using std::ostream;
using std::istream;

template <class T>
class Node;
template <class T>
class List;

////////////////////////////////////////////////////////////////////////////////////////////////////Node
template <class T>
class Node {
    private:
        T data;
        Node* link;
    public:
        //Default constructor.
        Node();
        //Constructor with a data parameter.
        Node(T t);
        //Copy constructor.
        Node(const Node<T>& n);
        //Destructor.
        ~Node() {}

        //Overloading <<cout>>.
        template <class V>
        friend ostream& operator <<(ostream& outs, const Node<V>& n);

        //Making the overloading of << a friend of node as well so it can access the data.
        template <class V>
        friend ostream& operator <<(ostream& outs, const List<V>& l);

        //Members function.
        void setData(T t) {data = t;}
        T getData() const {return data;}

        //Make list a friend of Node.
        friend List<T>;
};

//Default constructor.
template <class T>
Node<T>::Node() {
    link = nullptr;
    data = NULL;
}

//Constructor with a data parameter.
template <class T>
Node<T>::Node(T t) {
    link = nullptr;
    data = t;
}

template <class T>
Node<T>::Node(const Node<T>& n) {
    data = n.data;
    link = n.link;
}

template <class T>
ostream& operator <<(ostream& outs, const Node<T>& n) {
    outs << n.data;
    return outs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////Node


////////////////////////////////////////////////////////////////////////////////////////////////////List
template <class T>
class List {
    private:
        Node<T>* head;
        int size;
    public:
        List() : head(nullptr), size(0) {}
        List(const List<T>& original);
        ~List() {clear();}

        template <class V>
        friend ostream& operator <<(ostream& outs, const List<V>& l);

        void insertAtHead(T t);
        void clear();
        int getSize() {return size;}
        void reverse();
        friend Node<T>; 
};

template <class T>
List<T>::List(const List<T>& original) {
    head = nullptr;
    size = original.size;

    Node<T>* current = original.head;
    Node<T>* last = nullptr;
    
    while(current != nullptr) {
        Node<T>* newNode = new Node<T>(current -> data);
        if(head == nullptr) {
            head = newNode;
        }
        else {
            last -> link = newNode;
        }
        last = newNode;
        current = current -> link;
    }
}

//Overloading <<.
template <class T>
ostream& operator <<(ostream& outs, const List<T>& l) {
    Node<T>* current = l.head;
    int count = 0;
    outs << "[";
    while(current != nullptr) {
        outs << current -> data;
        if (count < l.size - 1) {
            outs << ", ";
        }
        count ++;
        current = current -> link;
    }
    outs << "]";
    return outs;
}

template <class T>
void List<T>::insertAtHead(T t) {
    Node<T>* temp = new Node(t);
    if(size == 0) {
        head = temp;
    }
    else {
        temp -> link = head;
        head = temp;
    }
    size ++;
}

template <class T>
void List<T>::clear() {
    while(head != nullptr) {
        Node<T>* temp = head;
        head = head -> link;
        delete temp;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////List

int main() {
    Node<int> i(10);
    Node<char> c('c');
    cout << i << "\n";
    cout << c << "\n";
    List<int> li;
    li.insertAtHead(10);
    li.insertAtHead(25);
    li.insertAtHead(55);
    li.insertAtHead(23);
    li.insertAtHead(55);
    cout << li << "\n";
    List<char> lc;
    lc.insertAtHead('a');
    lc.insertAtHead('c');
    lc.insertAtHead('a');
    lc.insertAtHead('c');
    cout << lc << "\n";
    return 0;
}