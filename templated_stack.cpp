#include<iostream>
using std::cout;
using std::ostream;

template <class T>
class Node;

template <class T>
class Stack;

template <class T>
class Queue;

////////////////////////////////////////////////////////////////////////////////////////////////////Node
template <class T>
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
        ~Node() {}

        //Members functions
        T getData() const {return data;}
        void setData(T d) {data = d;}
        //Overloading the assignment operator
        Node<T>& operator =(const Node<T>& rhs);
        //Overloading ==
        template <class N>
        friend bool operator ==(const Node<N>& A, const Node<N>& B);
        //Overloading <<
        template <class N>
        friend ostream& operator <<(ostream& outs, const Node<N>& node);
        template <class S>
        friend ostream& operator <<(ostream& outs, const Stack<S>& s);
        
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
        Node<T>* top;
        int size;
    public:
        Stack() : top(nullptr), size(0) {}
        Stack(const Stack<T>& original);
        ~Stack(){ clear();}

        //Members functions
        int getSize() {return size;}
        bool empty() {return size == 0;}
        //Push function.
        void push(T d);
        //Pop function.
        T pop();
        //Clear function.
        void clear();

        //Overloading the assignment operator
        Stack<T>& operator =(const Stack<T>& rhs);

        //Overloading the << operator.
        template <class S>
        friend ostream& operator <<(ostream& outs, const Stack<S>& s);

        friend class Node<T>;
};

template <class T>
Stack<T>::Stack(const Stack<T>& original) {
    top = nullptr;
    size = 0;
    Node<T>* current = original.top;
    while(current) {
        Node<T>* newNode = new Node<T>(current -> data);
        if(top == nullptr) {
            top = newNode;
        }
        top = top -> link;
        current = current -> link;
        size ++;
    }
}

//Push function.
template <class T>
void Stack<T>::push(T d) {
    Node<T>* newNode = new Node<T>(d);
    newNode -> link = top;
    top = newNode;
    size ++;
}

//Pop function
template <class T>
T Stack<T>::pop() {
    if(top) {
        T result = top -> data;
        Node<T>* temp = top;
        top = top -> link;
        delete temp;
        size --;
        return result;
    }
    else return T();
}

//clear function.
template <class T>
void Stack<T>::clear() {
    while(top) {
        Node<T>* temp = top;
        top = top -> link;
        delete temp;
    }
    size = 0;
    top = nullptr;
}

template <class T>
ostream& operator <<(ostream& outs, const Stack<T>& s) {
    Node<T>* current = s.top;
    int count(0);
    outs << "_\n";
    while(current) {
        outs << current -> data << "\n";
        current = current -> link;
        if(count < s.size - 1) {
            outs << "|\n";
            count ++;
        }
    }
    outs << "_";
    return outs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Stack

////////////////////////////////////////////////////////////////////////////////////////////////////Queue
template <class T>
class Queue {
    private:
    public:
};
////////////////////////////////////////////////////////////////////////////////////////////////////Queue
int main() {
    Stack<int> s;
    s.push(1);
    s.push(2);
    s.push(3);
    s.push(4);
    cout << s << "\n";
    cout << "poping " << s.pop() << " from the stack\n";
    cout << s << "\n";
    return 0;
}