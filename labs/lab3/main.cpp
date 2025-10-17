#include <iostream>
#include "ArrayStack.h"

int main() {
    ArrayStack<int> aStack;
    aStack.push(10);
    aStack.push(20);
    aStack.push(30);

    std::cout << "Top of aStack: " << aStack.peek() << '\n';

    aStack.pop();
    std::cout << "After one pop, top: " << aStack.peek() << '\n';

    ArrayStack<int> bStack;
    std::cout << "Is bStack empty? " << std::boolalpha << bStack.isEmpty() << '\n';

    ArrayStack<int> cStack;
    cStack.push(5);
    std::cout << "Top of cStack: " << cStack.peek() << '\n';
}
