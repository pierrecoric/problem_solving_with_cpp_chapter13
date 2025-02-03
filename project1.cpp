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
        List();
        List(const List<T>& original);
        ~List() {clear();}

        template <class V>
        friend ostream& operator <<(ostream& outs, const List<V>& l);

        void clear();
        int getSize() {return size;}
        void reverse(); 
};

////////////////////////////////////////////////////////////////////////////////////////////////////List

int main() {
    Node<int> i(10);
    Node<char> c('c');
    cout << i << "\n";
    cout << c << "\n";
    return 0;
}