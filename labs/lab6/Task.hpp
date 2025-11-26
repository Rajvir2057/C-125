// Task.hpp
#pragma once
#include <string>
#include <iostream>

class Task {
public:
    int due;              // format: YYYYMMDDHH, e.g., 2026021514
    std::string desc;     // e.g., "Finish CSCI 225 Lab"

    Task() : due(0), desc("") {}
    Task(int d, const std::string& s) : due(d), desc(s) {}
};

inline void printTask(const Task& t) {
    std::cout << "[" << t.due << "] " << t.desc;
}