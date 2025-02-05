#include<iostream>
using std::cout;
using std::ostream;

template<class T>
class Node;

template<class T>
class Stack;

template<class T>
class Queue;

////////////////////////////////////////////////////////////////////////////////////////////////////Node
template<class T>
class Node {
    private:
        T data;
        Node<T>* link;
    public:
        //Default constructor.
        Node() : data(T()), link(nullptr) {}
        //Parametrized constructor.
        Node(T d) : data(d), link(nullptr) {}
        //Copy constructor.
        Node(const Node<T>& original);
        ~Node();

        //Members functions
        T getData() const {return data;}
        void setData(T d) {data = d;}
        //Overloading the assignment operator
        Node<T>& operator =(const Node<T>& rhs);
        //Overloading ==
        friend bool operator ==(const Node<T>& A, const Node<T>& B);
        //Overloading <<
        friend ostream& operator <<(ostream& outs, const Node<T>& node);
        
        friend class Stack<T>;
        friend class Queue<T>;
};

//Copy constructor.
template <class T>
Node<T>::Node(const Node<T>& original) {
    data = original.data;
    link = nullptr;
}

//Overloading the assignment operator
template <class T>
Node<T>& Node<T>::operator =(const Node<T>& rhs) {
    if(this != &rhs) {
        data = rhs.data;
        link = rhs.link;
    }
    return *this;
}

//Overloading == (it only compares the data)
template <class T>
bool operator ==(const Node<T>& A, const Node<T>& B) {
    return A.data == B.data;
}

template <class T>
ostream& operator <<(ostream& outs, const Node<T>& node) {
    outs << node.data;
    return outs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Node

////////////////////////////////////////////////////////////////////////////////////////////////////Stack
template <class T>
class Stack {
    private:
    public:
};
////////////////////////////////////////////////////////////////////////////////////////////////////Stack

////////////////////////////////////////////////////////////////////////////////////////////////////Queue
template <class T>
class Queue {
    private:
    public:
};
////////////////////////////////////////////////////////////////////////////////////////////////////Queue
int main() {
    //Node<int> n(1);
    //cout << n << "\n";
    return 0;
}