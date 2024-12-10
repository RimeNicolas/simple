#include "util.h"
#include "tree.cpp"

using namespace std;

void test_tree() {
    const vector<int> v1 = {2,1,5,4,9,11,34,3,4,7,19};
    print_vector(v1);

    BIT b1(v1);
    SegmentTree st1(v1);

    cout << b1.rsq(1,2) << endl;
    cout << b1.rsq(0,2) << endl;
    cout << b1.rsq(1,4) << endl;
    cout << st1.rsq(1,2) << endl;
    cout << st1.rsq(0,2) << endl;
    cout << st1.rsq(1,4) << endl;

    cout << b1.repr() << endl;
}
