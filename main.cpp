#include <iostream>
#include "Mat.h"

using namespace std;

int main() {
    Vec v1({1, 1, 1});
    Vec v2({1, 2, 0});
    Vec v3({5, 8, 2});
    Vec v4({-1, -2, 1});
    Vec v5({3, 5, -1});
    Mat a = Mat::ByCols({v1, v2, v4});
    cout << Mat({v1, v2, v3}).Rank() << '\n';
    cout << Mat({v1, v2, v4}).Rank() << '\n';
    Mat x({{{1, 2}}, {{2, 3}}});
}