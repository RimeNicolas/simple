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
