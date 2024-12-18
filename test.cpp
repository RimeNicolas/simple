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

void test_mergesort() {
    vector<int> v1 = {1,4,2,3};
    mergesort(v1, 0, v1.size() - 1);
    print_vector(v1);

    v1 = {3,1,2};
    mergesort(v1, 0, v1.size() - 1);
    print_vector(v1);

    v1 = {3,2,4,1};
    mergesort(v1, 0, v1.size() - 1);
    print_vector(v1);

    v1 = {5,3,2,4,1};
    mergesort(v1, 0, v1.size() - 1);
    print_vector(v1);
}

void test_heapsort() {
    vector<int> v1 = {1,4,2,3};
    heapsort(v1);
    print_vector(v1);

    v1 = {3,1,2};
    heapsort(v1);
    print_vector(v1);

    v1 = {3,2,4,1};
    heapsort(v1);
    print_vector(v1);

    v1 = {5,3,2,4,1};
    heapsort(v1);
    print_vector(v1);
}
