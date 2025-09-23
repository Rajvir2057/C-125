#include <iostream>
#include <vector>

template<class ItemType>
class BagInterface{

    public:

    virtual int getCurrentSize() const = 0; 
    //we use virtual to override and 0 is to leave it as default.
    //This one will get the current number of entries in the bag and return
    // the integer number.
    //const means read only, and avoids all objects from manipulating data.

    virtual bool isEmpty() const = 0;
    //will see if  the bag is empty.

    virtual bool add(const ItemType& someItem) = 0;
    //successful entries will be stored in the bag.

    virtual bool remove(const ItemType& target) = 0;
    //removes anything selected
   
    virtual void  clear() = 0;
    //removes all entires from this bag.So bag contains no items and the count of items is 0.

    virtual int getFrequencyOf(const ItemType& target) const = 0;
    //countd the times a given number of items are added to the bag.

    virtual bool contains(const ItemType& taarget) const = 0;
    //tests if the bbag has a given entry.

    virtual std :: vector<ItemType> tovector() const = 0;
    //vctor with all the entries in the bag.

    virtual ~BagInterface(){}
    //Destroys object and frees memory.
};

// all virtual functions must be implemented. the complier can not find and run.