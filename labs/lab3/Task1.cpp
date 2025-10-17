#include <iostream>
#include <vector>
#include "ArrayStack.h"

template <class ItemType>
std :: vector<ItemType> toVector(ArrayStack<ItemType>& aStack){

    std :: vector<ItemType> newvector;
    ArrayStack<ItemType> stackback;

    while(!aStack.isEmpty()) {
        ItemType item = aStack.peek();
        newvector.push_back(item);
        stackback.push(item);
        aStack.pop();
    }
   

    while(!stackback.isEmpty()){
        ItemType normal = stackback.peek();
        aStack.push(normal);
        stackback.pop();

    }
     return newvector;
    //This is O(n)
}

