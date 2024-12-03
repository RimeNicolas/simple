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


std::string bin_repr(int n) {
    bool is_neg(n < 0);
    if (is_neg) n = -n;
    std::cout << n << std::endl;
    std::string repr;
    while(n > 0) {
        if (n & 1) repr = "1" + repr;
        else repr = "0" + repr;
        n >>= 1;
    }
    while (repr.size() < 31) {
        repr = "0" + repr;
    }
    if (is_neg) repr = "1" + repr;
    else repr = "0" + repr;
    return repr;
}



// Binary Indexed Tree (Fenwick tree)
class BIT {
    private:
        std::vector<int> data;
    public:
        BIT(int size) : data(size+1, 0) {}

        void insert(int idx, int val) {
            while (idx < data.size()) {
                data[idx] += val;
                idx += idx & (-idx);
            }
        }

        int rsq(int from, int to) {
            return getSum(to) - getSum(from);
        }

        int getSum(int idx) {
            int val(0);
            while(idx != 0) {
                val += data[idx];
                idx -= idx & (-idx);
            }
            return val;
        }
};


BIT construct_BIT(const std::vector<int>& v) {
    BIT b(v.size()+1);

    for (size_t i(0); i < v.size(); i++) {
        b.insert(i+1, v[i]);
    }
    return b;
}

