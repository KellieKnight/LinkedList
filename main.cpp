
/* C++: Practicing Linked Lists
 * File:   main.cpp
 * Author: Kellie
 *
 */

#include <cstdlib>
#include "List.h"
#include <iostream>

using namespace std;



int main(int argc, char** argv) {

    List myList;
    int num = 0;
    
    
    cout << "Let's Make a List."<<endl
         << "Enter 5 numbers between 1 and 100:"<<endl;
    for(int i = 0; i < 5; i++){
        
        cout << "Number " << i + 1 << ":" << endl;
        
            cin >> num;
            
            while(!num){
                cout << "Invalid Input.\n";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> num;
            }
            
            myList.PushBack(num);    
    }
    
    cout<< "Here is your list:"<<endl;
    myList.PrintList();
    
    cout<<"What would you like to do?"<<endl;
    //TODO: add menu, options, etc.
    
    
    return 0;
}


