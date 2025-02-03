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
using std::cout;
using std::ostream;

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
        template <class O>
        //Overloading <<
        friend ostream& operator <<(ostream& outs, const Node<O>& n);
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
/*
template <class T>
class List {
    private:
        Node<T>* head;
        List();
        List(const List<T>& original) {

        }
    public:
};
*/
////////////////////////////////////////////////////////////////////////////////////////////////////End List

int main() {
    Node<int> i(45);
    cout << i << "\n";
    return 0;
}