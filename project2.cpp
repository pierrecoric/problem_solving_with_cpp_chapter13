/*
2. Write a function called merge_lists that takes two call-by-reference argu-
ments that are pointer variables that point to the heads of linked lists of
values of type int. The two linked lists are assumed to be sorted so that the
number at the head is the smallest number, the number in the next node is
the next smallest, and so forth. The function returns a pointer to the head
of a new linked list that contains all of the nodes in the original two lists.
The nodes in this longer list are also sorted from smallest to largest values.
Note that your function will neither create nor destroy any nodes. When
the function call ends, the two pointer variable arguments should have the
value NULL.
*/

#include<iostream>
#include<initializer_list>
using std::cout;
using std::ostream;
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
        Node() : data(T()), link(nullptr) {}
        //Constructor that specifies the data.
        Node(T t);
        //Copy constructor.
        Node(const Node<T>& original);

        //Overloading <<
        template <class O>
        friend ostream& operator <<(ostream& outs, const Node<O>& n);

        //Making the overloading of << for List a friend of Node.
        template <class O>
        friend ostream& operator <<(ostream& outs, const List<O>& l);

        friend class List<T>;
};

//Constructor that specifies the data.
template <class T>
Node<T>::Node(T t) {
    link = nullptr;
    data = t;
}
//Copy constructor.
template <class T>
Node<T>::Node(const Node<T>& original) {
    data = original.data;
    if(original.link) {
        //Deep recursive copy.
        link = new Node<T>(*original.link);    
    } else link = nullptr;
}

//Overloading <<
template <class T>
ostream& operator <<(ostream& outs, const Node<T>& n) {
    outs << n.data;
    return outs;
}

////////////////////////////////////////////////////////////////////////////////////////////////////End Node


////////////////////////////////////////////////////////////////////////////////////////////////////List
template <class T>
class List {
    private:
        Node<T>* head;
        int size;
    public:
        List() : head(nullptr), size(0) {}
        //Constructor with an initializer list.
        List(initializer_list<T> values);
        List(const List<T>& original);
        
        template <class O>
        friend ostream& operator <<(ostream& outs, const List<O>& l);

        void insertAtHead(T t);

        friend class Node<T>;
};

template <class T>
List<T>::List(initializer_list<T> values) {
    head = nullptr;
    size = 0;
    for(auto it = values.end() -1; it >= values.begin(); it--) {
        insertAtHead(*it);
    }
}

//Insert at head function.
template <class T>
void List<T>::insertAtHead(T t) {
    Node<T>* newNode = new Node<T>(t);
    if(head == nullptr) {
        head = newNode;
    }
    else {
        newNode -> link = head;
        head = newNode;
    }
    size ++;
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
////////////////////////////////////////////////////////////////////////////////////////////////////End List

int main() {
    Node<int> i(45);
    cout << i << "\n";
    List<int> l = {1,2,3,4};
    cout << l << "\n";
    return 0;
}