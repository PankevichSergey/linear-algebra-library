#include <iostream>
#include "Mat.h"

using namespace std;

int main() {

    vector<float> a = {0.2, 0.5};
    vector<float> b = {0.1, 0.2};
    Vec<float> av(a);
    Vec<float> bv(b);
    Mat<float> M = Mat<float>::ByCols({av, bv});
    cout << (M ).GetInverse() << '\n';
}