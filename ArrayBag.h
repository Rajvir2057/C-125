#ifndef ARRAY_BAG_
#define ARRAY_BAG_
#include "BagInterface.h"
#include <vector>


template<class ItemType>
class ArrayBag : public BagInterface<ItemType>{

    private:

    static const int DEFAULT_CAPACITY = 6;
    ItemType items[DEFAULT_CAPACITY]; // bag items
    int itemCount; //counts the bag item
    int maxItems; //mx capacity of the bag.


    public:
    ArrayBag();
    int gotCurrentSize() const;
    bool isEmpty() const;
    bool add(const ItemType& someItem);
    bool remove(const ItemType& someItem);

};





#include "ArrayBag.cpp"
#endif
