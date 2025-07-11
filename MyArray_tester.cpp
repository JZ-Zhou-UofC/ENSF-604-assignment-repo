
/*
 IMPORTANT NOTE: STUDENTS ARE NOT SUPPOESED TO MAKE ANY CHANGES TO THIS FILE
 */
#include <string>
#include <iostream>
#include <cstring>
using namespace std;
#include "MyArray.h"

MyArray* run_test();
int main( void ) {
    freopen("data.txt", "r", stdin);
    
    cout << "Starting Test Run. Using input file." <<  endl;
    // testing functions that use MyArray objects
    MyArray* myArray = run_test();
    
    cout << "Finishing Test Run" <<  endl;
    
    cout << "Showing Data in the List:" << endl;
    for(int i =0; i < myArray->list_size; i++)
        cout << myArray->array[i] <<  "  ";
    
    cout << endl << "Program Ended ...." <<  endl;
    return 0;
}

MyArray* run_test() {
    const static  string prompt = " >> ";
    string comment;
    string command;
    int cnt = 0;
    MyArray* object = nullptr;
    getline(cin, comment);
    
    cin >> command;
    
    if (  cin.eof() ) {
        cout << "Exiting..." <<  endl;
        return object;
    }
    
    cout << "Line " << ++cnt << prompt;
    
    
    if ( command == "initialize" ) {
        object = new MyArray();
        initialize(object);
        cout << " Passed" <<  endl;
    }
    else {
        cout << "\nNo object was created... ";
        exit(1);
    }
    
    while ( true ) {
        cin >> command;
        
        if (  cin.eof() ) {
            cout << "Exiting..." <<  endl;
            return object;
        }
        
        cout << "Line "<< ++cnt << prompt;
        
        if ( command == "size" ) {
            int expected_size;
            cin >> expected_size;
            int actual_size = size(object);
            
            if ( actual_size == expected_size ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in size(): expected value is " << expected_size << ", not " << actual_size <<  endl;
            }
        } else if ( command == "isEmpty" ) {
            bool expected_empty;
            cin >> expected_empty;
            bool actual_empty;
            actual_empty= isEmpty(object);
            
            if ( actual_empty == expected_empty ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in is_empty(): expected value is " << expected_empty << ", not " << actual_empty <<  endl;
            }
        } else if ( command == "retrieve_at" ) {
            // checks if the first object in the linked list equals the next object read
            
            int index;
            
            int expected_value;
            
            cin >> index >> expected_value;
            
            int actual_front = retrieve_at(object, index);
            
            if ( actual_front == expected_value ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in retrieve_at: expected value is " << expected_value << ", not " << actual_front <<  endl;
            }
        }
        else if ( command == "count" ) {
            // check if the next object read in is in the linked list
            
            int value;
            int expected_count;
            int actual_count;
            
            cin >> value;
            cin >> expected_count;
            actual_count = count(object, value);
            
            if (actual_count == expected_count ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in count(): expected value is " << expected_count << ", not " << actual_count <<  endl;
            }
        }
        else if ( command == "insert_at" ) {
            int index;
            int n;
            cin >> index >> n;
            insert_at(object, index, n );
            
            if(object->array[index] == n)
                cout << " Passed" <<  endl;
            else
                cout << "Failed in insert_at" << endl;
        }
        
        else if ( command == "remove_at" ) {
            // pop the first object from the linked list
            int index;
            int expected_removed_element;
            
            cin >> index >> expected_removed_element;
            
            int actual_popped_element = remove_at(object, index);
            
            if ( actual_popped_element == expected_removed_element ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in removed_at(): expected value is " << expected_removed_element << " not " << actual_popped_element <<  endl;
            }
        } else if ( command == "retrieve_at" ) {
            int index;
            int expected_value;
            cin >> index >> expected_value;
            int actual_value = retrieve_at(object, index);
            
            if(index < 0 || index > size(object) ){
                cout << "Function retrieve_at REQUIRES 0 <= index < size()";
            }
            else if (actual_value == expected_value ) {
                cout << " Passed" <<  endl;
            }
            else {
                cout << " Failed in retrieve_at(): nexpected value is " << expected_value << ", not " << actual_value  <<  endl;
            }
        }
    }
    return object;
}
