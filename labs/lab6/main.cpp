// main.cpp
#include <iostream>
#include "TaskBST.hpp"

int main() {
    TaskBST tree;

    // Example tasks for initial testing.
    // You can modify this list to match the test cases below.
    tree.insert(Task(2026021514, "Lab 3 submissions"));
    tree.insert(Task(2026021510, "Study for the exam"));
    tree.insert(Task(2026021418, "Buy groceries"));

    std::cout << "Tasks grouped by day:\n";
    tree.printByDay();

    int now;
    std::cout << "\nEnter 'now' time (YYYYMMDDHH): ";
    std::cin >> now;

    const Task* next = tree.getNextTask(now);
    if (next) {
        std::cout << "Next task at or after " << now << ":\n";
        printTask(*next);
        std::cout << "\n";
    } else {
        std::cout << "No tasks at or after " << now << ".\n";
    }

    int removed = tree.removeOverdueTasks(now);
    std::cout << "\nRemoved " << removed << " overdue tasks.\n";
    std::cout << "Remaining tasks:\n";
    tree.printByDay();

    return 0;
}