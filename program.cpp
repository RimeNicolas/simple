#include "util.h"

using namespace std;


void test_bitree() {
    vector<int> v1 = {2,1,5};

    BIT b1 = construct_BIT(v1);
    cout << b1.rsq(0,2) << endl;
    cout << b1.rsq(0,3) << endl;
}


int main() {

    test_bitree();

    return 0;
}

