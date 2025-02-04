/*
1. Write a void function that takes a linked list of integers and reverses the
order of its Nodes. The function will have one call-by-reference parameter
that is a pointer to the head of the list. After the function is called, this
pointer will point to the head of a linked list that has the same Nodes as
the original list, but in the reverse of the order they had in the original list.
Note that your function will neither create nor destroy any Nodes. It will
simply rearrange Nodes. Place your function in a suitable test program.
*/

#include <iostream>
#include<initializer_list>
using std::cout;
using std::cin;
using std::ostream;
using std::istream;
using std::initializer_list;

template <class T>
class Node;
template <class T>
class List;

////////////////////////////////////////////////////////////////////////////////////////////////////Node
template <class T>
class Node {
    private:
        T data;
        Node<T>* link;
    public:
        //Default constructor.
        Node();
        //Constructor with a data parameter.
        Node(T t);
        //Copy constructor.
        Node(const Node<T>& n);
        //Destructor.
        ~Node() {}

        //Overloading <<.
        template <class V>
        friend ostream& operator <<(ostream& outs, const Node<V>& n);

        //Making the overloading of << a friend of Node as well so it can access the data.
        template <class V>
        friend ostream& operator <<(ostream& outs, const List<V>& l);

        //Overloading >>
        template <class V>
        friend istream& operator >>(istream& ins, Node<V>& n);

        //Overloadin =
        Node<T>& operator =(const Node<T>& rhs);

        //Members function.
        void setData(T t) {data = t;}
        T getData() const {return data;}
        void setLink(Node<T>* l) {link = l;}

        //Make list a friend of Node.
        friend class List<T>;
};

//Default constructor.
template <class T>
Node<T>::Node() {
    link = nullptr;
    data = T();
}

//Constructor with a data parameter.
template <class T>
Node<T>::Node(T t) {
    link = nullptr;
    data = t;
}

//Copy Constructor
template <class T>
Node<T>::Node(const Node<T>& n) {
    data = n.data;
    if(n.link) {
        link = new Node<T>(*n.link);
    }
    else link = nullptr;
}

//Overloading <<
template <class T>
ostream& operator <<(ostream& outs, const Node<T>& n) {
    outs << n.data;
    return outs;
}

//Overloading >>
template <class T>
istream& operator >>(istream& ins, Node<T>& n) {
    T input;
    ins >> input;
    n.data = input;
    return ins;
}

//Overloading the assignment operator.
template<class T>
Node<T>& Node<T>::operator =(const Node<T>& rhs) {
    if(this != &rhs) {
        data = rhs.data;
        delete link;
        link = rhs.link ? new Node<T>(*rhs.link) : nullptr;
    }
    return *this;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Node


////////////////////////////////////////////////////////////////////////////////////////////////////List
template <class T>
class List {
    private:
        Node<T>* head;
        int size;
    public:
        //Default constructor
        List() : head(nullptr), size(0) {}
        //Constructor with and initializer list.
        List(initializer_list<T> values);
        //Copy constructor.
        List(const List<T>& original);
        //Destructor.
        ~List() {clear();}

        template <class V>
        friend ostream& operator <<(ostream& outs, const List<V>& l);

        List<T>& operator =(const List<T>& rhs);

        void insertAtHead(T t);
        void clear();
        int getSize() {return size;}
        void reverse();
        friend class Node<T>; 
};

//Copy constructor.
template <class T>
List<T>::List(const List<T>& original) {
    head = nullptr;
    size = original.size;

    if(original.head == nullptr) {
        size = 0;
        return;
    }

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

//Overloading the assignment operator for List
template<class T>
List<T>& List<T>::operator =(const List<T>& rhs) {
    if(this != &rhs) {

        clear();

        size = rhs.size;

        if(rhs.head != nullptr) {
            head = new Node<T>(rhs.head->data);
            Node<T>* current = head;
            Node<T>* currentRhs = rhs.head->link;
            
            while(currentRhs != nullptr) {
                current -> link = new Node<T>(currentRhs -> data);
                current = current -> link;
                currentRhs = currentRhs -> link;
            }
        }
        else {
            head = nullptr;
        }
    
    }
    return *this;
}

//Constructor with and initializer list.
template <class T>
List<T>::List(initializer_list<T> values) {
    head = nullptr;
    size = 0;
    for (auto it = values.end() - 1; it >= values.begin(); --it) {
        insertAtHead(*it);
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

//Insert at head function.
template <class T>
void List<T>::insertAtHead(T t) {
    Node<T>* temp = new Node<T>(t);
    if(size == 0) {
        head = temp;
    }
    else {
        temp -> link = head;
        head = temp;
    }
    size ++;
}

//clear function.
template <class T>
void List<T>::clear() {
    while(head != nullptr) {
        Node<T>* temp = head;
        head = head -> link;
        delete temp;
    }
}

//Reverse function.
template <class T>
void List<T>::reverse() {
    //Declaring and initializing three pointers:
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    
    //Iterating
    while(current != nullptr) {
        //Store the next node
        next = current->link;
        //invert the node pointer of the current node.
        current->link = previous;

        //Move the pointers
        previous = current;
        current = next;
    }
    head = previous;
}
////////////////////////////////////////////////////////////////////////////////////////////////////List

int main() {
    Node<int> i(10);
    Node<int> test;
    test = i;
    cout << test << " ... " << i << "\n";
    cin >> test;
    cout << test << " ... " << i << "\n";
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
    List<char> lx(lc);
    cout << lx << "\n";
    lx.reverse();
    cout << lx << "\n";
    lc.clear();
    cout << "cleared " << lc << "\n";
    List<int> ll = {1, 5, 4, 10, 100, 45};
    cout << ll << "\n";
    li = ll;
    cout << li;
    return 0;
}