#include <cstdlib>
#include <iostream>

#include "List.h"

using namespace std;

//Constructor: Define private data members
List::List(){
    head = NULL;
    current = NULL;
    temp = NULL;
}

//Create a new node and make a nodePtr point to it
void List::PushBack(int addData){
    //nodePtr is the same as node*
    nodePtr n = new node;
    //Find node n is pointing to, access its next element and set to NULL
    n->next = NULL;
    //Fill node with given data
    n->data = addData;
    
    
    //If the list is not empty, set current pointer to the front of the list.
    if(head != NULL){
        current = head;
        //Go through the list and advance the current ptr until end is reached.
        while(current->next != NULL){
            current = current->next;
        }
        //End of the list is reached, so we add n to the end
        current->next = n;
    }
    
    if(head == NULL){
        head = n;
    }
    
    
    cout << addData << " has been added to the end of the list." << endl;
}

void List::PushFront(int addData){
    nodePtr n = new node;
    n->data = addData;
    n->next = head;
    head = n;
    
    cout << addData << " has been added to the front of the list." << endl;
}

void List::AddAfter(int nodeData, int addData){
    nodePtr addPtr = new node;
    addPtr->next = NULL;
    addPtr->data = addData;
   
    current = head;
    
    while(current != NULL && current->data != nodeData){
        current = current->next;
    }
    if(current == NULL){
        cout << nodeData << " was not in the list." << endl;
        delete addPtr;
        return;
    }
    
    //If the requested value is at the end, simply change its next.
    //addPtr is already pointing to NULL.
    else if(current->next == NULL){
        current->next = addPtr;  
    }
    
    //Current is now pointing to the node containing nodeData.
    //We want to place addPtr, which contains addData, after it.
    else{
        addPtr->next = current->next;
        current->next = addPtr;
        
    }
    
    cout << addData 
             << " was added after the first instance of "
             << nodeData << endl;
    return;
    
}

void List::AddBefore(int nodeData, int addData){
    nodePtr addPtr = new node;
    addPtr->next = NULL;
    addPtr->data = addData;
   
    current = head;
    temp = head;
    
    while(current != NULL && current->data != nodeData){
        temp = current;
        current = current->next;
    }
    if(current == NULL){
        cout << nodeData << " was not in the list." << endl;
        delete addPtr;
    }
    
    //Current is now pointing to the node containing nodeData.
    //Temp is now pointing to the node before current.
    //Place addPtr, which contains addData, in between temp and current.
    else{
        addPtr->next = current;
        temp->next = addPtr;
        
        cout << addData 
             << " was added before the first instance of "
             << nodeData << endl;
    }
    
}

//Search the list for the given data and delete it once found.
void List::DeleteNode(int delData){
    nodePtr delPtr = NULL;
    //set temp and current to point to the same thing as head
    temp = head;
    current = head;
    //Current is used for searching.
    //Temp trails current in order to not lose position in list.
    
    //Traverse the list by advancing the pointers
    //Exits if delData is not found (reached the end) or when delData is found.
    while(current != NULL && current->data != delData){
        temp = current;
        current = current->next;
    }
    if(current == NULL){
        cout << delData << " was not in list." << endl;
        delete delPtr; //garbage collection
    }
    
    //Current is now pointing to position of delData.
    //Temp is now pointing to the node behind delData.
    //Keep the list connected and delete the node.
    else{
        delPtr = current;           //Set delPtr to point to delData
        current = current->next;    //Advance current to point to the next node.
        temp->next = current;       //Connect temp to current to "skip over" del
        
        //If the deletion pointer is at the front of the list,
        //we want to advance head and set temp to NULL.
        if(delPtr == head){
            head = head->next;
            temp = NULL;
        }
        
        delete delPtr;              //delete node delPtr is pointing to.
        cout << "The value " << delData <<" has been removed." <<endl;
    }
}


void List::PopBack(){
    
    if(head == NULL){
        cout << "No items to delete." << endl;
        return;
    }
    
    nodePtr delPtr = new node;
    
    current = head;
    temp = head;
    
    //Traverse the list and find the last element.
    while(current->next != NULL){
        temp = current;
        current = current->next;
    }
    //At this point, current points to last element.
    //Temp points to second to last element.
    delPtr = current;
    temp->next = NULL;
    
    if(delPtr == head){
            head = head->next;
            temp = NULL;
        }
    
    cout << delPtr->data << " was deleted." <<endl; 
    
    delete delPtr;
    
    
}

void List::PopFront(){
    
    nodePtr delPtr = new node;
    
    if(head == NULL){
        cout << "No items to delete." << endl;
        return;
    }
    else if(head->next == NULL){
        delPtr = head;
        head = NULL;
    }
    else{
    delPtr = head;
    head = delPtr->next;
    }
    
    cout << delPtr->data << " was deleted." << endl;
    
    delete delPtr;
    
    
}

void List::PrintList(){
    
    current = head;
    while(current != NULL){
        cout << current->data << "\n";
        current = current->next;
    }
}



