// TaskBST.hpp
#pragma once
#include "Task.hpp"

class TaskBST {
private:
    class Node {
    public:
        Task data;
        Node* left;
        Node* right;
        Node(const Task& t) : data(t), left(nullptr), right(nullptr) {}
    };

    Node* root;

    // --- private helper functions ---
    Node* insert(Node* node, const Task& t); // given

    // TODO: implement these three helpers in TaskBST.cpp
    const Task* getNextTask(Node* node, int now,
        const Task* bestSoFar) const;
    
    Node* removeOverdueTasks(Node* node, int now, 
        int& removedCount);
    
    void printInOrderByDay(Node* node, 
        int& currentDay) const;

    void clear(Node* node); // given

public:
    TaskBST() : root(nullptr) {}
    ~TaskBST() { clear(root); }

    bool isEmpty() const { return root == nullptr; }

    // given: public wrapper that calls the private insert helper
    void insert(const Task& t) { root = insert(root, t); }

    // public wrappers that call the private helpers (your TODOs)
    const Task* getNextTask(int now) const {
        return getNextTask(root, now, nullptr);
    }

    int removeOverdueTasks(int now) {
        int removedCount = 0;
        root = removeOverdueTasks(root, now, removedCount);
        return removedCount;
    }

    void printByDay() const {
        int currentDay = -1;
        printInOrderByDay(root, currentDay);
    }
};