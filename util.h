#pragma once

#include <math.h>
#include <iostream> 

#include <vector> 
#include <queue>
#include <stack>
#include <array>
#include <set>
#include <unordered_set>
#include <unordered_map>

#include <algorithm>
#include <random>
#include <thread>
#include <mutex>
#include <functional>


template<class T>
void print_vector(std::vector<T> v) {
    std::cout << '(';
    for (size_t i(0); i < v.size() - 1; i++)
        std::cout << v[i] << ',';
    std::cout << v.back() << ')' << std::endl;
}

std::string bin_repr(int n); 

