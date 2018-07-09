// LinkedList.h

#include <iostream>

using namespace std;

struct Node 
{ 
int *data; 
Node *next; 
};

class LinkedList{
  public:
    //constructor
    LinkedList() : head(NULL), tail(NULL) {}
    
    //copy constructor
    //performs a deep copy of the passed list
    LinkedList(const LinkedList& bList);
    
    //destructor
    // deletes all the nodes in the list
    ~LinkedList(){ clear(); };
    
   
    // insert a new node into the head of this list 
    // set the data to the argument item
    void insert(int& item);
    
    // find
    // finds the node with the data that matches item
    // returns a pointer to the node
    Node* find(int& item);
    
    // remove
    // deletes the node that matches item,
    // nothing if no nodes match
    void remove(int& item);
    
    //size
    // prints the number of nodes the list has
    int size();
    
     // append
    // attaches a second list to the end of this list
    void append(LinkedList& list2);
    
    //print
    //prints a the items from head to tail deliniated with a ->
    void print();
    
    //clear
    // deletes all the nodes in the list.  
    // sets head and tail to NULL
    void clear();
    
    //reverse recursive
    //reverses the list so that the tail is the head and the 
    // head is the tail and every node in between is reversed
    // for example if the node is first 5 4 3 2 1
    // after it will be 1 2 3 4 5 
    // acheives this using a recursive loop
    void reverseRecursive();
    
    //reverse iterative
    //reverses the list so that the tail is the head and the 
    // head is the tail and every node in between is reversed
    // for example if the node is first 5 4 3 2 1
    // after it will be 1 2 3 4 5 
    void reverseIterative();
    
private:
    Node* head;
    Node* tail;
      
    // recursive loop called by reverseRecursive()
    void reverseR(Node* current);

};//end LinkedList

#include "LinkedList.cpp"