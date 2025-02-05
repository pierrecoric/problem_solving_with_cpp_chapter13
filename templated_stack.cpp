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
        //Declaring << for Stack and Queue here as well.
        template <class S>
        friend ostream& operator <<(ostream& outs, const Stack<S>& s);
        template <class Q>
        friend ostream& operator <<(ostream& outs, const Queue<Q>& s);
        
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
        //Default constructor.
        Stack() : top(nullptr), size(0) {}
        //Copy constructor. (uses =)
        Stack(const Stack<T>& original) : top(nullptr), size(0) {*this = original;}
        //Destructor.
        ~Stack(){ clear();}

        //Overloading the assignment operator
        Stack<T>& operator =(const Stack<T>& rhs);

        //Members functions
        int getSize() const {return size;}
        bool empty() const {return size == 0;}
        //Push function.
        void push(T d);
        //Pop function.
        T pop();
        //Clear function.
        void clear();
        void reverse();

        //Overloading the << operator.
        template <class S>
        friend ostream& operator <<(ostream& outs, const Stack<S>& s);

        friend class Node<T>;
};

//Overload the assignment operator.
template <class T>
Stack<T>& Stack<T>::operator =(const Stack<T>& rhs) {
    if(this != &rhs) {
        clear();
        Node<T>* current = rhs.top;
        while(current) {
            push(current -> data);
            current = current -> link;
        }
    }
    reverse();
    return *this;
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

//Reverse function
template <class T>
void Stack<T>::reverse() {
    if(size < 2) {
        return;
    }
    Node<T>* previous = nullptr;
    Node<T>* current = top;
    Node<T>* next = nullptr;
    
    while(current) {
        //Store the next node.
        next = current -> link;
        //Invert the current node's pointer
        current -> link = previous;

        //Move the pointers
        previous = current;
        current = next;
    }
    top = previous;
}

//Overloading <<.
template <class T>
ostream& operator <<(ostream& outs, const Stack<T>& s) {
    Node<T>* current = s.top;
    int count(0);
    outs << "_\n";
    while(current) {
        outs << *current << "\n";
        current = current -> link;
        if(count < s.size - 1) {
            outs << "|\n";
            count ++;
        }
    }
    outs << "-";
    return outs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Stack

////////////////////////////////////////////////////////////////////////////////////////////////////Queue
template <class T>
class Queue {
    private:
        Node<T>* head;
        Node<T>* tail;
        int size;
    public:
        //Default constructor.
        Queue() : head(nullptr), tail(nullptr), size(0) {}
        //Copy constructor. (uses =)
        Queue(const Queue<T>& original) : head(nullptr), tail(nullptr), size(0) {*this = original;}
        ~Queue() {clear();}

        //Overloading the assignment operator
        Queue<T>& operator =(const Queue<T>& rhs);

        //Members functions.
        int getSize() const {return size;}
        bool empty() const {return size == 0;}
        //enqueue function.
        void enqueue(T d);
        //dequeue function.
        T dequeue();
        //Clear function.
        void clear();
        void reverse();

        //Overloading the << operator.
        template <class Q>
        friend ostream& operator <<(ostream& outs, const Queue<Q>& q);

        friend class Node<T>;

};

//Overloading the assignment operator
template <class T>
Queue<T>& Queue<T>::operator =(const Queue<T>& rhs) {
    if(this != &rhs) {
        clear();
        Node<T>* current = rhs.head;
        while(current) {
            enqueue(current -> data);
            current = current -> link;
        }
    }
    return *this;
}

//enqueue function.
template <class T>
void Queue<T>::enqueue(T d) {
    Node<T>* newNode = new Node<T>(d);
    if(head) {
        tail -> link = newNode;
        tail = newNode;
    }
    else {
        head = newNode;
        tail = newNode;
    }
    size ++;
}

//dequeue function.
template <class T>
T Queue<T>::dequeue() {
    T result = T();
    if(empty()) {
        return result;
    }
    Node<T>* temp = head;
    result = temp -> data;
    head = head -> link;
    size --;
    delete temp;
    return result;
}

//clear function.
template <class T>
void Queue<T>::clear() {
    while(head) {
        Node<T>* temp = head;
        head = head -> link;
        delete temp;
    }
    head = nullptr;
    tail = nullptr;
    size = 0;
}

//Reverse function
template <class T>
void Queue<T>::reverse() {
    if(size < 2) {
        return;
    }
    Node<T>* previous = nullptr;
    Node<T>* current = head;
    Node<T>* next = nullptr;
    
    tail = current;
    while(current) {
        //Store the next node.
        next = current -> link;
        //Invert the current node's pointer
        current -> link = previous;

        //Move the pointers
        previous = current;
        current = next;
    }
    head = previous;
}

//Overloading the << operator.
template <class T>
ostream& operator <<(ostream& outs, const Queue<T>& q) {
    int count(0);
    outs << "[";
    Node<T>* current = q.head;
    while(current) {
        outs << *current;
        if(count < q.size - 1) {
            outs << " -> ";
            count ++;
        }
        current = current -> link;
    }
    outs << "]";
    return outs;
}
////////////////////////////////////////////////////////////////////////////////////////////////////Queue

int main() {
    cout << "Testing:\n";
    cout << "Testing Node:\n";
    cout << "Creating:\n";
    Node<int> n1(100);
    cout << "Outputing:\n";
    cout << n1 << "\n";
    cout << "Copy constructor:\n";
    Node<int> n2(n1);
    cout << n2 << "\n";
    cout << "\n";
    cout << "Testing Stack:\n";
    cout << "Creating:\n";
    Stack<int> s1;
    for(int i = 0; i < 25; i++) {
        s1.push(i);
    }
    cout << "Outputing:\n";
    cout << s1 << "\n";
    cout << "Copy constructor:\n";
    Stack<int> s2(s1);
    cout << s2 << "\n";
    cout << "clearing:\n";
    s1.clear();
    cout << s1 << "\n";
    cout << "poping on an empty stack:\n";
    cout << s1.pop();
    cout << "\n";
    cout << "Testing Queue:\n";
    cout << "Creating:\n";
    Queue<int> q1;
    for(int i = 0; i < 25; i++) {
        q1.enqueue(i);
    }
    cout << "Outputing:\n";
    cout << q1 << "\n";
    cout << "Copy constructor:\n";
    Queue<int> q2(q1);
    cout << q2 << "\n";
    cout << "clearing:\n";
    q1.clear();
    cout << q1 << "\n";
    cout << "dequeuing an empty queue:\n";
    cout << q1.dequeue();
    cout << "\n All good 🔄 \n";
    return 0;
}