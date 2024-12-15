#include "util.h"

std::string bin_repr(int n) {
    const bool is_neg(n < 0);
    if (is_neg) n = -n;
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


void merge(std::vector<int>& v, const size_t l, const size_t m, const size_t r) {
    size_t i(l), j(m+1);

    while (i <= m && j <= r) {
        if (v[i] <= v[j]) {
            i++;
        }
        else {
            std::swap(v[i], v[j]);
            j++;
        }
    }
}


void mergesort(std::vector<int>& v, const size_t l, const size_t r) {
    if (l >= r) return;
    const size_t m(l + (r - l) / 2);

    mergesort(v, l, m);
    mergesort(v, m+1, r);

    //print_vector(v);
    merge(v, l, m, r);
}
