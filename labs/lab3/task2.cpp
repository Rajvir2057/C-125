   #include <iostream>
   #include "LinkedStack.h"
   #include "StackInterface.h"
   
   
   
   class MinStack {
        private:
            Stack<int> dataStack; // normal stack
            Stack<int> minStack; // tracks current minimums

        public:
            void push(const int& x) {
                // TODO
            }
            void pop() {
                // TODO
            }
            void top() const {
                // TODO
            }
            void getMin() const {
                // TODO
            }

            bool empty() const {
                return dataStack.isEmpty();
            }
    };
