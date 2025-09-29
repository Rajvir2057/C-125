#include "LinkedData.h"

template <class ItemType>
LinkedData<ItemType>::LinkedData() = default;

template <class ItemType>
LinkedData<ItemType>::~LinkedData() { clear(); }

template <class ItemType>
int LinkedData<ItemType>::size() const  { return size_; }

template <class ItemType>
bool LinkedData<ItemType>::empty() const { return size_ == 0; }

template <class ItemType>
std::vector<ItemType> LinkedData<ItemType>::toVector() const {
    std::vector<ItemType> out;
    Node<ItemType>* cur = head_;
    while (cur != nullptr) {
        out.push_back(cur->getItem());
        cur = cur->getNext();
    }
    return out;
}
template <class ItemType>
void LinkedData<ItemType>::push_front(const ItemType& x) {
    head_ = new Node<ItemType>(x, head_);
    //if the list is empty, after adding a new node, head and tail are the same
    if (!tail_) tail_ = head_;
    ++size_;
}

template <class ItemType>
void LinkedData<ItemType>::push_back(const ItemType& x) {
    if (!head_) { push_front(x); return; }
    Node<ItemType>* n = new Node<ItemType>(x, nullptr);
    tail_->setNext(n);
    tail_ = n;
    ++size_;
}

template <class ItemType>
bool LinkedData<ItemType>::remove_first(const ItemType& x) {
    if (!head_) return false;

    if (head_->getItem() == x) {
        Node<ItemType>* d = head_;
        head_ = head_->getNext();
        d->setNext(nullptr);
        delete d;
        --size_;
        if (!head_) tail_ = nullptr;
        return true;
    }
    Node<ItemType>* prev = head_;
    Node<ItemType>* cur  = head_->getNext();
    while (cur) {
        if (cur->getItem() == x) {
            prev->setNext(cur->getNext());
            if (cur == tail_) tail_ = prev;
            cur->setNext(nullptr);
            delete cur;
            --size_;
            return true;
        }
        prev = cur;
        cur  = cur->getNext();
    }
    return false;
}

template <class ItemType>
void LinkedData<ItemType>::clear() {
    Node<ItemType>* cur = head_;
    while (cur) {
        Node<ItemType>* d = cur;
        cur = cur->getNext();
        d->setNext(nullptr);
        delete d;
    }
    head_ = tail_ = nullptr;
    size_ = 0;
}

// ------------------ STUDENT TODOs ------------------

// Return value at index [0..size()-1]. 
// If out of range, throw std::out_of_range.
// NOTE: This is a stub so the project compiles; implement it.
template <class ItemType>
ItemType LinkedData<ItemType>::getAt(int index) const {

    if (index < 0 || index >= size_) {

        throw std::out_of_range("Index out of range in getAt()");

    }

    Node<ItemType>* current = head_;

    for (int i = 0; i < index; i++) {

        current = current->getNext();

    }

    return current->getItem();

}
 
// Insert value at index [0..size()]. Return true on success; false if out of range.
// NOTE: Stub; implement: handle index==0 (front), index==size (back), and middle splice.
template <class ItemType>
bool LinkedData<ItemType>::insertAt(int index, const ItemType& value) {
   if (index < 0 || index > size_) {
       return false;
   }
   // Insert at beginning
   if (index == 0) {
       push_front(value);
       return true;
   }
   // Insert at end
   if (index == size_) {
       push_back(value);
       return true;
   }
   // Insert in middle
   Node<ItemType>* current = head_;
   for (int i = 0; i < index - 1; i++) {
       current = current->getNext();
   }
   Node<ItemType>* newNode = new Node<ItemType>(value, current->getNext());
   current->setNext(newNode);
   ++size_;
   return true;
}
// Erase node at index [0..size()-1]. Return true on success; false if out of range.
// NOTE: Stub; implement: handle index==0 (erase head), tail updates, middle unlink.
template <class ItemType>

bool LinkedData<ItemType>::removeAt(int index) {

    if (index < 0 || index >= size_) {

        return false;

    }

    // Remove from beginning

    if (index == 0) {

        Node<ItemType>* temp = head_;

        head_ = head_->getNext();

        temp->setNext(nullptr);

        delete temp;

        --size_;

        if (size_ == 0) {

            tail_ = nullptr;

        }

        return true;

    }

    // Remove from middle or end

    Node<ItemType>* current = head_;

    for (int i = 0; i < index - 1; i++) {

        current = current->getNext();

    }

    Node<ItemType>* nodeToDelete = current->getNext();

    current->setNext(nodeToDelete->getNext());

    // Update tail if we're removing the last element

    if (nodeToDelete == tail_) {

        tail_ = current;

    }

    nodeToDelete->setNext(nullptr);

    delete nodeToDelete;

    --size_;

    return true;

}
 