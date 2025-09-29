#include "Node.h"

template<class ItemType>
Node<ItemType> :: Node()
                        :next(nulptr)
                        {}//ending the defualt constructor.

template<class ItemType>
Node<ItemType> :: Node(const ItemType& anItem)
                                             :item (anItem), next(nullptr)
                                             {}// end constructor.
        
template<class ItemType> 
Node<ItemType> :: Node(const ItemType& anItem)
                                             :item (anItem), next (nullptr)
                                             {}//end constructor.

//forming  getters and setters.
template<class ItemType>
ItemType Node<ItemType> :: getItem() const
                                        {
                                            return item;
                                        }

template <class ItemType>
Node<ItemType>* Node<ItemType> ::  getNext() const
                                            {
                                                return next;
                                            }
