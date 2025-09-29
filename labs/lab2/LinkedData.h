#ifndef LINKEDDATA_HEADER
#define LINKEDDATA_HEADER
#include <vector>
#include "Node.h"

template <class ItemType>
class LinkedData {
public:
    LinkedData();
    ~LinkedData();


    LinkedData(const LinkedData&) = delete;
    LinkedData& operator=(const LinkedData&) = delete;


    int  size()  const;
    bool empty() const;
    std::vector<ItemType> toVector() const;

    // ---- Modifiers (implemented) ----

    
    void push_front(const ItemType& x); //adds a new node at the beginning
    void push_back(const ItemType& x);  //adds a new node at the end
    bool remove_first(const ItemType& x);  //remove the first node whose item equals x
    void clear();

    // ---- STUDENT TASKS (TODOs in .cpp) ----
    // getAt: return value at index [0..size()-1]; 
    // if out of range, throw std::out_of_range.
    ItemType getAt(int index) const;

    // insertAt: insert value at index [0..size()]. Return true on success, false otherwise.
    bool insertAt(int index, const ItemType& value);

    // removeAt: erase node at index [0..size()-1]. Return true on success, false otherwise.
    bool removeAt(int index);

private:
    Node<ItemType>* head_ = nullptr;
    Node<ItemType>* tail_ = nullptr;
    int             size_ = 0;
};

// Include template method definitions
#include "LinkedData.cpp"
#endif