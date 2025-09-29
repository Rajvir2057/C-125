#ifndef NODE_HEADER
#define NODE_HEADER
template <class ItemType>
class Node {
public:
     Node(const ItemType& item, Node<ItemType>* next = nullptr);

    // Accessors / mutators
    ItemType getItem() const;

    void setItem(const ItemType& item);

    Node<ItemType>* getNext() const;
    void            setNext(Node<ItemType>* next);

private:
    ItemType        item_;
    Node<ItemType>* next_;
};

#include "Node.cpp"

#endif