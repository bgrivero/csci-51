#include <string>
#include <iostream>
using namespace std;

// The following struct is the basic Node struct which is used for IntList and IntStack.
struct IntNode{
    int val;
    IntNode* next;
};

// The following struct is an IntNode implementation of a Integer LinkedList.
// Uses pointers because it is dynamic (i.e. size changes at runtime).
struct IntList{
    // The struct keeps track of the pointer for the first node.
    IntNode* firstNodeP;

    // The function instantiates the firstNode and returns the pointer to the first node.
    IntNode* createFirstNode(int val){
        firstNodeP = new IntNode{val, NULL};
        return firstNodeP;
    }

    // The function inserts a newNode after some other node.
    IntNode* insert(IntNode* nodeP, IntNode* newNode){
        newNode -> next = nodeP -> next;
        nodeP -> next = newNode;
        return newNode;
    }

    // The function gets the first node pointer.
    IntNode* getFirst(){
        return firstNodeP;
    }

    // The function returns the node after any other node.
    IntNode* getNextNode(IntNode* nodeP){
        if (nodeP == NULL) {
            return NULL;
        }
        return nodeP -> next;
    }

    // The function deletes a node.
    void deleteNode(IntNode* nodeP){
        // The linked list is empty or the node being deleted is null i.e. illegal memory access 
        if (firstNodeP == NULL || nodeP == NULL){
            return;
        }

        // Deleting the first node
        // Necessary because there is no nodes before the first node
        if (nodeP == firstNodeP){
            IntNode* temp = firstNodeP;
            firstNodeP = getNextNode(firstNodeP);
            delete temp;
            return;
        }

        // Deleting other nodes that is not the first
        IntNode* current = firstNodeP;
        while (current -> next != NULL && current -> next != nodeP){
            current = current->next;
        }

        //deletes nodeP and continues the linked list
        if (current -> next == nodeP){
            current -> next = getNextNode(nodeP);
            delete nodeP;
        }
    }

    // The function is used to print out all node values in the linked list.
    void printAllVals(){
        if (firstNodeP == NULL){
            cout << "Empty linked list." << endl;
            return;
        }
        cout << "--- Linked List Values ---" << endl;
        cout << firstNodeP -> val << endl;

        IntNode* nextP = firstNodeP -> next;
        while (nextP != NULL){
            cout << nextP -> val << endl;
            nextP = nextP -> next;
        }
        return;
    }

    // Destructor so there is no memory leak
    ~IntList() {
        IntNode* current = firstNodeP;
        while (current != 0){
            IntNode* next = current -> next;
            delete current;
            current = next;
        }
        firstNodeP = nullptr;
    }
};

struct IntStack{
    // REVIEW: If this set up fulfills "not exposing" IntNode struct to user.
    private:
    IntNode* topP;
    int stacksize;

    public:
    // Initializing an empty stack.
    IntStack(){
        topP = NULL;
        stacksize = 0;
    }
    
    // This function pushes a value onto the stack. topP is the next for the newNode since the next value is always the previous one.
    void push(int value){
        IntNode* newNode = new IntNode{value, topP};
        topP = newNode;
        stacksize ++;
    }

    // This function returns the value of the top node and deletes it from the stack.
    int pop(){
        if(topP == NULL){
            cout << "Stack is empty" << endl;
            return -99;
        };
        // Temporary have the topNode to have the top-most node which will be deleted later on.
        IntNode* topNode = topP;
        int returnValue = topNode -> val;
        // Move the topP to the "next" (node below the top).
        topP = topP -> next;
        delete topNode;
        stacksize --;
        return returnValue;
    }

    // This function returns the value of the current stacksize.
    int size(){
        return stacksize;
    }
};


int main(void){
    // Initialize linkedlist
    IntList linkedList = IntList {NULL};
    linkedList.printAllVals();
    IntNode* nextP = linkedList.createFirstNode(0);

    // Add some nodes to the linked list
    for (int i = 1; i < 5; i++){
        IntNode* nextNodeP = new IntNode {i,NULL};
        nextP = linkedList.insert(nextP, nextNodeP);
    }
    
    cout << linkedList.firstNodeP -> next -> next -> val << endl;
    cout << linkedList.getFirst() << endl;
    // Print all values to validate correctness of code.
    linkedList.printAllVals();

    // Delete first node
    linkedList.deleteNode(linkedList.firstNodeP);
    cout << "--- Deleted first node ---" << endl;
    linkedList.printAllVals();

    // Delete node 2
    IntNode* node2 = linkedList.firstNodeP->next;
    linkedList.deleteNode(node2);
    cout << "--- Deleted second node ---" << endl;
    linkedList.printAllVals();

    // Stack check
    cout << "--- Stack Time! ---" << endl;
    IntStack testStack;
    testStack.push(1);
    testStack.push(2);
    testStack.push(5);
    testStack.push(9);
    cout << testStack.pop() << endl;
    cout << testStack.pop() << endl;
    cout << testStack.pop() << endl;
    cout << testStack.pop() << endl;
    cout << testStack.pop() << endl;
};
