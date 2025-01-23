#include <iostream>
using namespace std;

struct QueueNode {
    char data;
    QueueNode* link;
};

typedef QueueNode* QueueNodePtr;

class Queue {
    public:
        //Constructor
        Queue();
        //Copy constructor
        Queue(Queue& a_queue);
        //Destructor
        ~Queue();
        //Function to add
        void add(char c);
        //Function to remove
        char remove();
        //Returns true if empty
        bool empty() const;
        //Function to print the queue.
        void print() const;
    private:
        QueueNodePtr front;
        QueueNodePtr back;
};

//Basic constructor
Queue::Queue() {
    front = nullptr;
    back = nullptr;
}

//Copy constructor.
Queue::Queue(Queue& a_queue) {
    cout << "new" << endl;
    back = nullptr;
    front = nullptr;
    
    if(!a_queue.empty()) {
        //Copy the first item.
        QueueNodePtr oldQueue = a_queue.front;
        front = new QueueNode;
        front -> data = oldQueue -> data;
        front -> link = nullptr;
        //Set back to front for the first node.
        back = front;

        //Copy the rest
        oldQueue = oldQueue -> link;

        while (oldQueue != nullptr) {
            //Create a new node.
            QueueNodePtr temp = new QueueNode;
            //Copy the data from the original queue to the new node.
            temp -> data = oldQueue -> data;
            //Initialize the link of the new node to null.
            temp -> link = nullptr;

            //Connect the new node to the queue.
            back -> link = temp;

            //The new node is now the back of the queue.
            back = temp;

            //Move to the next one.
            oldQueue = oldQueue ->link;
        }
    }

}

//Destructor (uses remove)
Queue::~Queue() {
    char next;
    while(!empty()) {
        //Remove calls delete.
        next = remove();
    }
    cout << "Queue deleted";
}

//Function to add to the queue.
void Queue::add(char c) {
    //If the queue is empty
    if(empty()) {
        front = new QueueNode;
        front -> data = c;
        front -> link = nullptr;
        back = front;
    }
    else {
        //Create new node
        QueueNodePtr temp;
        temp = new QueueNode;
        //Copy the data into the new node.
        temp -> data = c;
        //Initialize the pointer of the new node to null
        temp -> link = nullptr;
        //Link the queue with the new node
        back -> link = temp;
        back = temp;
    }
}

char Queue::remove() {
    char result;
    if(empty()) {
        cout << "Error removing from an empty Queue" << endl;
        exit(1);
    } 
    result = front->data;
    QueueNodePtr discard;
    discard = front;
    front = front -> link;

    //If front is pointing to null i.e. if the last node has been removed.
    if(front == nullptr) {
        back = nullptr;
    }

    delete(discard);
    return result;
}

void Queue::print() const {
    if(!empty()) {
        QueueNodePtr current;
        current = front;
        while(current != nullptr) {
            cout << current -> data;
            current = current->link;
        }
        delete(current);
    }
}

bool Queue::empty() const{
    return(front == nullptr);
}



int main() {
    Queue q;
    char ans;
    while(ans != '\n') {
        cin.get(ans);
        q.add(ans);
    }
    Queue r(q);
    cout << endl;
    q.print();
    cout << endl;
    r.print();
    cout << endl << "End of program" << endl;
    return 0;
}