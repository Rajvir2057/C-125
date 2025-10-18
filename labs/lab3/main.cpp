#include <iostream>
#include <vector>
#include "ArrayStack.h"
#include "Task1.cpp"
#include "task2.cpp"
#include "LinkedStack.h"

int main(){
    
    //implementing task1.. this has O(n) output, why : we have two different while loops and each has valuve of n. 
    //if it was nested then the output would be O(n^2)
    
    //creating the T1.1 where we push 10 20 30 and get 30 20 10.
    ArrayStack <int> Stack1;
    
    Stack1.push(10);
    Stack1.push(20);
    Stack1.push(30);
    
    //creating a loop to see all and run.
    std :: vector <int> T1 =  toVector(Stack1);
    for(int i : T1){
        std:: cout << i << ",";
    }
    
    std:: cout << "\n" << "Returned to normal" << "\n"; 
    
    for(int i : T1){
    std:: cout << Stack1.peek() << "," ;
    Stack1.pop();
    }
    std:: cout << "\n";
    
    //making T1.2 return an empty stack.
    ArrayStack <int> Stack2;

    std :: vector <int> T2 = toVector(Stack2);
    if(T2.empty()){
        std:: cout << "empty" << "\n";
    }
    
    //T1.3 giving 5 to the stack 
    ArrayStack <int> Stack3;

    Stack3.push(5);

    std:: vector <int> T3 = toVector(Stack3);

    std :: cout << Stack3.peek() << "\n";

    // all the above use O(n) since we have single uses of while and if statements to trigger output.

    //task 2 implementation.

    // Even this has O(n) , why : we are not using nested and just simply using a linkedchain to pop and peek with if logic from Task2.
    //okie now we gonna get a min value after pushing.

    MinStack smallvalue;

    smallvalue.push(5);
    smallvalue.push(2);
    smallvalue.push(3);

    std :: cout << "Small value is : " << smallvalue.getMin() << "\n";

    //T2.2

    MinStack value;

    value.push(7);
    value.pop();

    if(value.isEmpty()){
        std:: cout <<"Removed the digit 7." << "\n";
    }

    value.push (4);

    std :: cout << value.getMin() <<"\n";

    //t2.3
    MinStack lasttest;

    lasttest.push(8);
    lasttest.push(6);

    lasttest.pop();

    lasttest.push(1);
    
    std :: cout << "get min = " << lasttest.getMin() << "\n";

    // even this is o(n) , simple pop and push is used from single if statements.
}
