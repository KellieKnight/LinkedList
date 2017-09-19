/* 
 * File:   List.h
 * Author: Kellie
 *
 * Created on September 19, 2017, 12:21 PM
 */

#ifndef LIST_H
#define LIST_H

//Interface for our List class
class List{
    
    //Can only be accessed by member functions
private:
    
    //typedef defines struct node* as nodePtr
    typedef struct node{
        int data;   //data in each node
        node* next; //node pointer
    }* nodePtr;
    
    
    nodePtr head;
    nodePtr current;
    nodePtr temp;

//Declaring function prototypes
public:
    //Constructor function sets initial values
    List();
    //Adds a node at the end with the given data.
    void PushBack(int addData);
    //Adds a node to the front with the given data.
    void PushFront(int addData);
    //Adds given element before given node.
    void AddBefore(int nodeData, int addData);
    //Adds given element after given node
    void AddAfter(int nodeData, int addData);
    //Deletes first element
    void PopFront();
    //Deletes last element
    void PopBack();
    //Deletes the specified node
    void DeleteNode(int delData);
    //Print
    void PrintList();
    

};


#endif /* LIST_H */

