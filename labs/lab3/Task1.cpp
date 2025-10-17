#include <iostream>
#include <vector>
#include "ArrayStack.h"

template <class ItemType>
std :: vector<ItemType> toVector(ArrayStack<ItemType>& aStack){

    std :: vector<ItemType> newvector;

    while(!aStack.isEmpty()) {
        ItemType item = aStack.peek();
        newvector.push_back(item);
        aStack.pop();
    }

    int i = newvector.size() - 1;
    while(i >= 0) {
        aStack.push(newvector[i]);
        i--;
    }
    return newvector;

    //This is O(n)
}

