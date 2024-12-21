#include "util.h"
#include "tree.cpp"

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

