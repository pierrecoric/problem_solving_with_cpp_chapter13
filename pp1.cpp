/*
1. The following program creates a linked list with three names:

Add code to the main function that:
a. Outputs in order all names in the list.
b. Inserts the name “Joshua” in the list after “James” then outputs the
modified list.
c. Deletes the node with “Joules” then outputs the modified list.
d. Deletes all nodes in the list.

*/

#include <iostream>
#include <string>
using namespace std;
struct Node {
    string name;
    Node *link;
};

typedef Node* NodePtr;

//a. Outputs in order all names in the list.
void outputList(NodePtr& list);

//b. Inserts the name “Joshua” in the list after “James” then outputs the modidfied list
void insertAfter(NodePtr& list, string target, string name);

//c. Deletes the node with “Joules” then outputs the modified list.
void deleteTarget(NodePtr& list, string target);

//d. Deletes all nodes in the list.
void deleteList(NodePtr& list);

int main() {
    NodePtr listPtr, tempPtr;

    listPtr = new Node;
    listPtr -> name = "Emily";

    tempPtr = new Node;
    tempPtr -> name = "James";
    listPtr -> link = tempPtr;

    tempPtr -> link = new Node;
    tempPtr = tempPtr->link;
    tempPtr -> name = "Joules";
    tempPtr -> link = NULL;

    //Testing the printing function.
    cout << "Printing the list." << endl;
    outputList(listPtr);
    cout << "Inserting Josuah." << endl;
    //Inserting Josuah after James.
    insertAfter(listPtr, "James", "Josuah");
    //Inserting something at the end.
    insertAfter(listPtr, "Joules", "Boris");
    //Inserting something with a wrong target.
    insertAfter(listPtr, "Coco", "Fred");
    cout << endl << "Printing the list after insertions." << endl;
    outputList(listPtr);
    cout << endl << "Deleting James" << endl;
    deleteTarget(listPtr, "James");
    cout << "Printing after deletion" << endl;
    outputList(listPtr);

    deleteList(listPtr);

    return 0;
}

void outputList(NodePtr& list) {
    NodePtr temp = list;
    while(temp != NULL) {
        cout << temp -> name << endl;
        temp = temp -> link;
    }
}

void insertAfter(NodePtr& list, string target, string name) {
    NodePtr temp = list;
    NodePtr newNode = new Node;

    //Initializing the new node.
    newNode -> name = name;
    newNode -> link = NULL;

    while(temp != NULL) {
        if (temp -> name == target) {
            cout << target << " found." << endl;
            newNode -> link = temp -> link;
            temp -> link = newNode;
            return;
        }
        temp = temp -> link;
    }
    delete newNode;
    //If not found:
    cout << target << " not found." << endl;
}

void deleteTarget(NodePtr& list, string target) {
    NodePtr temp = list;
    NodePtr prev = NULL;

    //Traverse the list to find the target node
    while(temp != NULL) {
        if(temp -> name == target) {
            if(prev == NULL) {
                list = temp -> link;
            }
            else {
                prev -> link = temp -> link;
            }
            delete temp;
            return;
        }

        //Move to the next node
        prev = temp;
        temp = temp -> link;
    }
    cout << target << " not found." << endl;
}

void deleteList(NodePtr& list) {
    while (list != NULL) {
        cout << "Deleting: " << list -> name << endl;
        NodePtr temp = list;
        list = list -> link;
        delete temp;
    }
    cout << "List deleted" << endl;
}