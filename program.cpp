#include "util.h"
#include "tree.cpp"

using namespace std;


void test_bitree() {
    vector<int> v1 = {2,1,5,4,9,11,34,3,4,7,19};
    print_vector(v1);

    BIT b1 = construct_BIT(v1);
//    cout << b1.rsq(0,2) << endl;

    cout << b1.repr() << endl;
}


int main() {


    test_bitree();

    return 0;
}

