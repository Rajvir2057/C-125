#ifndef _NODE
#define _NODE

template<class ItemType>
class Node{
    private: 
        ItemType          item;
        Node<ItemType>*   next;

    public:
        Node();
        Node(const ItemType& anItem);
        Node(const ItemType& anItem,
                        Node<ItemType>* nextNode);

        void setItem(const ItemType& anItem);
        void setNext(Node<ItemType>* nextNode);

        ItemType getItem() const;
        Node<ItemType>* getNext() const;
    
};
//end the node
#include "Node.cpp"
#endif 