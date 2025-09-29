#include "Node.h"
template <class ItemType>
Node<ItemType>::Node(const ItemType& item, Node<ItemType>* next)
    : item_(item), next_(next) {}

template <class ItemType>
 ItemType Node<ItemType>::getItem() const { return item_; }

template <class ItemType>
void Node<ItemType>::setItem(const ItemType& item) { item_ = item; }

template <class ItemType>
Node<ItemType>* Node<ItemType>::getNext() const { return next_; }

template <class ItemType>
void Node<ItemType>::setNext(Node<ItemType>* next) { next_ = next; }
