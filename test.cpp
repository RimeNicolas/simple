#include "util.h"
#include "tree.cpp"
#include "cost_basis.cpp"

using namespace std;

void test_tree() {
    const vector<int> v1 = {2,1,9,8};
    print_vector(v1);

    BITree b1(v1);
    SegmentTree st1(v1);

    cout << b1.rq(1,2) << endl;
    cout << b1.rq(0,2) << endl;
    cout << b1.rq(0,v1.size()) << endl;
    cout << st1.rq(1,2) << endl;
    cout << st1.rq(0,2) << endl;
    cout << st1.rq(0,v1.size()) << endl;

    cout << b1.repr() << endl;


    print_vector(st1.traversal(BinaryTree::TypeTraversal::preorder));
    print_vector(st1.traversal(BinaryTree::TypeTraversal::inorder));
    print_vector(st1.traversal(BinaryTree::TypeTraversal::postorder));
    print_vector(st1.traversal(BinaryTree::TypeTraversal::level));
}


void test_sort() {
    std::vector<std::vector<int>> v_list;
    v_list.push_back({1,4,2,3});
    v_list.push_back({3,1,2});
    v_list.push_back({3,2,4,1});
    v_list.push_back({5,3,2,4,1});

    for (auto el : v_list) {
        mergesort(el);
        print_vector(el);
    }
    for (auto el : v_list) {
        heapsort(el);
        print_vector(el);
    }
    for (auto el : v_list) {
        quicksort(el);
        print_vector(el);
    }
}


string print(Lot lot) {
    return "qty: " + to_string(lot.qty) + ", price: " + to_string(lot.price) + ", fees: " + to_string(lot.fees);
}


void test_avg(const vector<Lot>& v_lots, const Lot& redu) {
    vector<Lot> lots(v_lots);
    cout << "gain avg: " << redu_avg(lots, redu) << endl;
    cout << "avg cost basis: " << print(avg(lots)) << endl;
    lots.push_back(Lot(5, 25));
    cout << "avg cost basis: " << print(avg(lots)) << endl;
}


void test_fifo(const vector<Lot>& v_lots, const Lot& redu) {
    queue<Lot> lots;
    for (const auto el : v_lots) {
        lots.push(el);
    }
    cout << "gain fifo: " << redu_fifo(lots, redu) << endl;
    cout << "remaining lot: " << print(lots.front()) << endl;
}


void test_lifo(const vector<Lot>& v_lots, const Lot& redu) {
    stack<Lot> lots;
    for (const auto el : v_lots) {
        lots.push(el);
    }
    cout << "gain lifo: " << redu_lifo(lots, redu) << endl;
    cout << "remaining lot: " << print(lots.top()) << endl;
}


void test_lkm() {
    vector<Lot> lots;
    //buy 10 at 10$
    lots.push_back(Lot(10, 10, 1));
    //buy 10 at 20$
    lots.push_back(Lot(10, 20, 2));
    cout << "avg cost basis: " << print(avg(lots)) << endl;
    //sell 15 at 25$
    Lot redu(15, 25, 0);
    cout << "AVG" << endl;
    test_avg(lots, redu);
    cout << "FIFO" << endl;
    test_fifo(lots, redu);
    cout << "LIFO" << endl;
    test_lifo(lots, redu);
}
