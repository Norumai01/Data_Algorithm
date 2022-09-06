// Linked List Implementation
// Stores integers
#include <iostream>
#include <stdexcept>

class MyList {};

class Node {
public:
    Node() : _data{0}, _next{nullptr} {}    // Constructor
    Node(int data) : _data{data}, _next{nullptr} {}
    Node(int data, Node* next) : _data{data}, _next{next} {}
    friend class MyList; // MyList get allow access with its private. 
private:
    int _data;
    Node* _next;
};

class MyList {
public:
    MyList() : _head{nullptr}, _nodeCount{0} {}
    void addFront(int data);
    void removeFront();
    int front();
    int size();
private:
    Node* _head;
    int _nodeCount;
};

void MyList::addFront(int data) {   // Add element to the front.
    Node* n = new Node(data);
    if (_head == nullptr) {
        _head = n;
        return;
    }
    n->_next = _head;
    _head = n;
    return; // Optional because it already ended here.
}

int MyList::front() {   // Return the front element
    if (_head == nullptr) {
        throw std::runtime_error("Empty List");
    }
    Node *n = _head;
    return n->_data;
}

int MyList::size() {    // This will help for homework #2. Output the size.
    int count = 0;
    Node* n = _head;
    while (n != nullptr) {  // Traverse through the linked list.
        count++;
        n = n->_next;
    }
    return count; 
}

void MyList::removeFront() {
    if (_head == nullptr) return;   //Doesn't do anything and exit the function.
    Node* n = _head;
    _head = n->_next; 
    delete n;   // Delete the old data. 
}

int main() {
    MyList list; 

    list.addFront(1);
    std::cout << list.front() << std::endl; // Print 1
    list.addFront(2);
    std::cout << list.front() << std::endl; // Print 2
    std::cout << list.size() << std::endl; // Print size of 2.
    list.removeFront();
    std::cout << list.size() << std::endl; // Print size of 1. 
    
    return EXIT_SUCCESS;
}