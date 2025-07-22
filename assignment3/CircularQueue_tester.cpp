//
//  main.cpp
//  Circular Queue
//
//  Created by Mahmood Moussavi on 2024-04-09.
#if 0
#include "CircularQueue.h"

int main() {
    CircularQueue q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.displayQueue();

    std::cout << "Deleted value = " << q.dequeue() << std::endl;
    std::cout << "Deleted value = " << q.dequeue() << std::endl;

    q.displayQueue();

    q.enqueue(50);
    q.enqueue(60);
    q.displayQueue();

    return 0;
}
#endif

/*
 IMPORTANT NOTE: STUDENTS ARE NOT SUPPOESED TO MAKE ANY CHANGES TO THIS FILE
 */

#include <iostream>
#include <cstring>
using namespace std;
#include "CircularQueue.h"
// STUDENT MUST USE THE FULL PATH FOR YOUR WORKING DIRECTOR IN THE FOLLOWING LINE
const char* input_file_full_path = "full_patH_for_your_working_director/data1.txt";

CircularQueue* run_test();

int main( void ) {
    freopen(input_file_full_path, "r", stdin);
    cout << "Starting Test Run. Using input file." <<  endl;
    // testing functions that use CircularQueue objects
    CircularQueue* circularQueue = run_test();
    std::cout << "Here is the content of the circular queue at the end of program:\n";
    circularQueue->displayQueue();
    cout << "Finishing Test Run" <<  endl;
    cout << endl << "Program Ended ...." <<  endl;
    return 0;
}

CircularQueue* run_test() {
    const static  string prompt = " >> ";
    string command;
    int cnt = 0;
    CircularQueue* object = nullptr;
    cin >> command;
    
    if (  cin.eof() ) {
        cout << "Exiting..." <<  endl;
        return object;
    }
    
    cout << "Line " << ++cnt << prompt;
    
    
    if ( command == "new" ) {
        object = new CircularQueue();
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
        
        if ( command == "isEmpty" ) {
            bool expected_value;
            cin >> expected_value;
            bool actual_value;
            actual_value= object->isEmpty();
            
            if ( actual_value == expected_value ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in isEmpty(): expected value is " << expected_value << ", not " << actual_value <<  endl;
            }
        } 
        else if ( command == "isFull" ) {
            bool expected_value;
            cin >> expected_value;
            bool actual_value;
            actual_value= object->isFull();
            
            if ( actual_value == expected_value ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in is_Full(): expected value is " << expected_value << ", not " << actual_value <<  endl;
            }
        }
        else if ( command == "count" ) {
            int expected_count;
            int actual_count;

            cin >> expected_count;
            actual_count = object->counter();
            
            if (actual_count == expected_count ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed in count(): expected value is " << expected_count << ", not " << actual_count <<  endl;
            }
        }
        else if ( command == "enqueue" ) {

            int value, tail;
            cin >> value;
            tail = object->enqueue(value);
            if(object->get_arr()[tail] == value)
                cout << " Passed" <<  endl;
            else
                cout << "Failed in enqueue" << endl;
        }
        
        else if ( command == "dequeue" ) {
            int expected_value;
            
            cin >> expected_value;
            
            int head = object->dequeue();
            
            if ( object->get_arr()[head] == expected_value ) {
                cout << " Passed" <<  endl;
            } else {
                cout << " Failed dequeue(): expected value is " << expected_value << " not " << object->get_arr()[head]<<  endl;
            }
        }
    }
    return object;
}

