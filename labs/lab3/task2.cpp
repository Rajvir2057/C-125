   #include <iostream>
   #include "LinkedStack.h"
   #include "StackInterface.h"
   #include "Node.h"

   class MinStack {

        private:

            LinkedStack<int> dataStack; // normal stack
            LinkedStack<int> minStack; // tracks current minimums
        public:

            void push(const int& x) {

                dataStack.push(x); // here we will create all containing the x and min will take and keep the small one.
                //taking care of taking only less min.4

                if(minStack.isEmpty() || x <= minStack.peek() ){
                    minStack.push(x);
                }

            }

            void pop() {
                //peek to the top first.
                int y = dataStack.peek();
                dataStack.pop();
               if(y  == minStack.peek()) {
                    minStack.pop();
            }
            // pop is to remove and check for less here.here LIFO is applied 
            }

            int top() const {
                // here we will use peek just to look at the top element.

               return dataStack.peek();

            }

            int getMin() const {
                return minStack.peek();
            }

            bool isEmpty() const {
                return dataStack.isEmpty();
            }
    };
