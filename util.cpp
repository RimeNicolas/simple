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

void mergesort(std::vector<int>& v) {
    mergesort(v, 0, v.size() - 1);
}


void heapify(std::vector<int>& v, size_t n, size_t i) {
    size_t largest(i), l(2*i + 1), r(2*i + 2);

    if (l < n && v[l] > v[largest]) largest = l;
    if (r < n && v[r] > v[largest]) largest = r;

    if (largest != i) {
        std::swap(v[i], v[largest]);
        heapify(v, n, largest);
    }
}

    
void maxheap(std::vector<int>& v) {
    for (int i(v.size()/2 - 1); i >= 0; i--) {
        heapify(v, v.size(), i);
    }
}


void heapsort(std::vector<int>& v) {
    maxheap(v);
    for (int i(v.size() - 1); i > 0; i--) {
        std::swap(v[0], v[i]);
        heapify(v, i, 0);
    }
}


int partition(std::vector<int>& v, const int l, const int r) {
    int pivot = v[r];
    int i(l);

    for (int j(l); j < r; j++) {
        if(v[j] < pivot) {
            std::swap(v[i++], v[j]);
        }
    }

    std::swap(v[i], v[r]);
    return i;
}


void quicksort(std::vector<int>& v, int l, int r) {
    if (l < r) {
        int p = partition(v, l, r);
        quicksort(v, l, p - 1);
        quicksort(v, p + 1, r);
    }
}


void quicksort(std::vector<int>& v) {
    int v_size(v.size());
    quicksort(v, 0, v_size - 1);
}

double f1(std::vector<std::vector<double>> trx) {
    double avg_price(0);
    int sum_qty(0);
    for (const auto el : trx) {
        avg_price += el[0] * el[1];
        sum_qty += el[0];
    }
    avg_price /= sum_qty;
    return avg_price;
}

