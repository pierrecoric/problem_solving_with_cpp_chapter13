//Example of a stack class.

#include <iostream>
#include <cstddef>
using namespace std;

struct stackFrame {
    char data;
    stackFrame* link;
};

typedef stackFrame* stackFramePtr;
class Stack {
    public:
        //Constructor for an empty stack.
        Stack();
        //Constructor to copy a stack.
        Stack(const Stack& a_stack);
        //Destructor.
        ~Stack();
        void push(char c);
        char pop();
        bool empty() const;
        void print() const;
    private:
        stackFramePtr top;
};

//Creates an empty stack
Stack::Stack() : top(nullptr) {
    //Nothing to put here.
}

//Copy constructor
Stack::Stack(const Stack& a_stack) {
    //Initialize the top node to null.
    top = nullptr;
    //Check that the stack we are copying from is not empty.
    if(!a_stack.empty()) {
        //Copy the top node.
        stackFramePtr oldPointer = a_stack.top;
        top = new stackFrame;
        top->data = oldPointer->data;
        //initialize the top link to null.
        top->link = nullptr;

        //Copy the rest.
        //NextOne will move through the new stack and link each node to the previous one.
        stackFramePtr nextOne = top;
        //Moves the pointer to the next node in the original stack.
        oldPointer = oldPointer->link;

        while(oldPointer != nullptr) {
            stackFramePtr temp = new stackFrame;
            temp->data = oldPointer->data;
            //nullptr because it is now the new top node.
            temp->link = nullptr;
            //Link the rest of the stack to the new top node.
            nextOne->link = temp;

            //Move to the next node.
            nextOne = nextOne->link;
            oldPointer = oldPointer->link;
        }
    }
}

//Stack destructor
Stack::~Stack() {
    char next;
    while(!empty()) {
        //pop calls delete.
        next = pop();
    }
    cout << "Stack deleted" << endl;
}

void Stack::push(char c) {
    //Create a new frame and a pointer pointing to it.
    stackFramePtr newFrame = new stackFrame;
    //Puting the data into the new frame.
    newFrame->data = c;
    //Link this new frame to the current top of the stack.
    newFrame->link = top;
    //Update of the top pointer so it points towards the new frame.
    top = newFrame;
}

char Stack::pop() {
    if(empty()) {
        cout << "Error popping an empty stack." << endl;
        exit(1);
    }
    char result = top -> data;
    //Create a temporary node to hold the address of the top node so that it can be deleted after the top pointer has been reassigned to the next node.
    stackFramePtr temp;
    temp = top;
    top = top -> link;
    delete temp;
    return result;
}

bool Stack::empty() const {
    //Returns false if the value of top is not null.
    return (top == nullptr);
}

void Stack::print() const {
    stackFramePtr current = top;
    while(current != nullptr) {
        cout << current->data;
        current = current->link;
        cout << endl;
    }
    cout << endl;
}

int main() {
    Stack s;
    char ans;
    while(ans != '\n') {
        cin.get(ans);
        s.push(ans);
    }
    s.print();
    cout << "End of program." << endl;
    return 0;
}
