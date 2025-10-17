#pragma once

#ifndef ArrayStack_H
#define ArrayStack_H

template<class ItemType>
class ArrayStack {
  public:

  static const int DEFAULT_CAPACITY = 5;

  ArrayStack();

  // Copy constructor and destructor are supplied by the compiler

  bool isEmpty() const noexcept;
  bool push(const ItemType& someItem) noexcept;
  bool pop() noexcept;
  ItemType peek() const;

  private:
  int items[DEFAULT_CAPACITY];
  int top;
};

#include "ArrayStack.cpp"
#endif
