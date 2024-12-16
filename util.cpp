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
    std::vector<int> v_l(v.begin() + l, v.begin() + m + 1);
    std::vector<int> v_r(v.begin() + m + 1, v.begin() + r + 1);
    size_t i(0), j(0), k(l);

    while (i < v_l.size() && j < v_r.size()) {
        if (v_l[i] <= v_r[j]) {
            v[k++] = v_l[i++];
        }
        else {
            v[k++] = v_r[j++];
        }
    }
    while (i < v_l.size()) {
        v[k++] = v_l[i++];
    }
    while (j < v_r.size()) {
        v[k++] = v_r[j++];
    }
}


void mergesort(std::vector<int>& v, const size_t l, const size_t r) {
    if (l >= r) return;
    const size_t m(l + (r - l) / 2);

    mergesort(v, l, m);
    mergesort(v, m+1, r);

    merge(v, l, m, r);
}
