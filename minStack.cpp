class MinStackNode {
    private:
        int val;
        MinStackNode* link;
    public:
        MinStackNode() : val(0), link(nullptr) {}
        MinStackNode(int i) : val(i), link(nullptr) {}
        friend MinStack;
};

class MinStack {
    private:
        MinStackNode* topNode;
        int size;
        int min;
    public:
        MinStack() : topNode(nullptr), size(0), min(0) {}
        MinStack(const MinStack& original);
        void push(int x);
        void pop();
        int top();
        int getMin();
        friend MinStackNode;
};

void MinStack::push(int x) {
    //update the min
    if(x < min) {
        min = x;
    }
    MinStackNode* newNode = new MinStackNode(x);
    if(top == nullptr) {
        topNode = newNode;
    }
    else {
        newNode -> link = topNode;
        topNode = newNode;
    }
    size ++;
}

void MinStack::pop() {
    bool updateMin(false);
    if(topNode) {
        MinStackNode* temp = topNode;
        if(temp -> val == min) {
            updateMin = true;
        }
        topNode = topNode -> link;
        delete temp;
    }
    if(updateMin) {
        MinStackNode* current = topNode;
        while(current) {
            if(current -> val < min) {
                min = current -> val;
            }
            current = current -> link;
        }
    }
}

int MinStack::top() {
    if(top) {
        return topNode -> val;
    } else return -1;
}

int MinStack::getMin() {
    if(top) {
        return min;
    } else return -1;
}