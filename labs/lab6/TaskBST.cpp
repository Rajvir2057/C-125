// TaskBST.cpp

#include "TaskBST.hpp"
#include <iostream>

// ==============================
// Given helper functions
// Do NOT modify these.
// ==============================

// insert: standard BST insertion by due time
TaskBST::Node* TaskBST::insert(Node* node, const Task& t) {
    if (!node) {
        return new Node(t);
    }
    if (t.due < node->data.due) {
        node->left = insert(node->left, t);
    } else if (t.due > node->data.due) {
        node->right = insert(node->right, t);
    } else {
        // if duplicate time, you can decide:
        // for this lab, keep the first, ignore duplicates
        std::cerr << "Warning: duplicate due time " << t.due 
        << " ignored.\n";
    }
    return node;
}

// clear: delete all nodes in the tree
void TaskBST::clear(Node* node) {
    if (!node) return;
    clear(node->left);
    clear(node->right);
    delete node;
}

// ==============================
// TODO: Implement the following three functions
//       using the BST property and recursion.
// ==============================

// ----------- getNextTask (TODO) -----------
// Return pointer to the Task with smallest due >= now.
const Task* TaskBST::getNextTask(Node* node, int now, const Task* bestSoFar) const {
    // TODO: search the subtree rooted at 'node' for the 
    //       earliest task with due >= now. Use the BST 
    //       ordering and update bestSoFar as needed.
    if (node == nullptr) {
        return bestSoFar;
    }

    if (node->data.due < now) {
        return getNextTask(node->right, now, bestSoFar);
    } else {
        return getNextTask(node->left, now, &node->data);
    }
}

// ----------- removeOverdueTasks (TODO) -----------
// Remove all nodes with due < now.
// Return new subtree root and update removedCount.
TaskBST::Node* TaskBST::removeOverdueTasks(Node* node,int now,int& removedCount) {
    // TODO: recursively remove all tasks with due < now
    //       while keeping the tree a valid BST and
    //       counting how many nodes are deleted.
    if (node == nullptr) {
        return nullptr;
    }

    if (node->data.due < now) {
        node->left = removeOverdueTasks(node->left, now, removedCount);
        Node* newRoot = removeOverdueTasks(node->right, now, removedCount);
        
        delete node;
        removedCount++;
        
        return newRoot;
    } else {
        node->left = removeOverdueTasks(node->left, now, removedCount);
        return node;
    }
}

// ----------- printInOrderByDay (TODO) -----------
// Print tasks in order, grouped by date (YYYYMMDD).
// Hint: day = node->data.due / 100
void TaskBST::printInOrderByDay(Node* node,int& currentDay) const {
    // TODO: in-order traversal. When the date (YYYYMMDD)
    //       changes, print a new day header, then the task.
    if (node == nullptr) {
        return;
    }

    printInOrderByDay(node->left, currentDay);

    int thisDay = node->data.due / 100;

    if (thisDay != currentDay) {
        std::cout << "=== " << thisDay << " ===\n";
        currentDay = thisDay;
    }

    std::cout << "[" << node->data.due << "] " << node->data.desc << "\n";

    printInOrderByDay(node->right, currentDay);
}
