#include <iostream>
#include "Mat.h"
#include "Perm.h"
#include "Poly.h"

using namespace std;

void task1() {
    cout << "Task 1 info:\n\n";
    // all permutations are 0-based before printing
    Perm a({7, 4, 5, 2, 6, 3, 1, 0});
    Perm b({1, 3, 2, 7, 0, 6, 5, 4});
    Perm c({{0, 7, 4, 1, 6}, {2, 3, 5}});
    b ^= 11;
    a ^= -1;
    Perm rhs = (a * b) ^ 185;
    Perm sigma(8);
    do {
        if (sigma * (c * sigma) == rhs) {
            sigma.Add1();
            cout << sigma << "is a solution\n";
            sigma.Subtract1();
        }
    } while (sigma.NextPermutation());

}
void task2() {
    cout << "Task 2 info:\n\n";
    Mat A = vector<vector<ll>>{{-3, -3, 3,  -1},
                               {-1, -1, 3,  -3},
                               {-1, -1, -3, 1},
                               {2,  3,  3,  -1}};
    Mat B = vector<vector<ll>>{{-2, 2,  1,  2},
                               {-2, 2,  -1, 1},
                               {-2, -3, 3,  -2},
                               {-1, -1, 1,  -2}};
    Mat C = vector<vector<ll>>{{1,  1,  -1, 1},
                               {1,  2,  -2, 2},
                               {-1, -2, 3,  -1},
                               {1,  2,  -3, 2}};
    Mat Y = vector<vector<ll>>{{-8, 3,  -7,  5},
                               {4,  -1, 2,   -4},
                               {7,  -4, 7,   -10},
                               {3,  -6, -10, -1}};
    if (A.HasInverse() && B.HasInverse() && C.HasInverse()) {
        cout << "A, B, C are invertible\n";
    }
    cout << "X:\n" << (B * C.GetInverse() * A) - Y << '\n';

}

Poly CalcDet(const vector<vector<Poly>>& A) {
    Perm p(A.size());
    Poly det;
    do {
        Poly cur({1});
        for (int i = 0; i < A.size(); ++i) {
            cur = cur * A[i][p[i]];
        }
        if (p.Sgn() == -1) {
            det -= cur;
        } else {
            det += cur;
        }
    } while (p.NextPermutation());
    return det;
}

void task3() {
    cout << "Task 3 info:\n\n";
    Mat A = vector<vector<ll>>{{3, 4, 2, -1},
                               {-5, -3, 5, 3},
                               {2, 4, 4, -1},
                               {0, 0, 1, 2}};

    cout << A.GetPoly() << "\n\n";
    A ^= 2;
    A -= Mat::Identity(4) * 4;
    cout << Num(1) / (A.Det() * A.Det()) << '\n';
}

void task4() {
    cout << "Task 4 info:\n\n";
    vector<vector<Poly>> A = {{Poly({0, 1}), Poly({-6}), Poly({-1}), Poly({-3}), Poly({2}), Poly({-2}), Poly({-8})},
                              {Poly({8}), Poly({7}), Poly({-3}), Poly({5}), Poly({-2}), Poly({7}), Poly({0, 1})},
                              {Poly({4}), Poly({0, 1}), Poly({-7}), Poly({-3}), Poly({5}), Poly({0, 1}), Poly({-3})},
                              {Poly({-4}), Poly({-3}), Poly({3}), Poly({0, 1}), Poly({6}), Poly({-5}), Poly({7})},
                              {Poly({-5}), Poly({-2}), Poly({0, 1}), Poly({1}), Poly({8}), Poly({-9}), Poly({5})},
                              {Poly({-1}), Poly({7}), Poly({9}), Poly({0, 1}), Poly({-4}), Poly({5}), Poly({-3})},
                              {Poly({-2}), Poly({2}), Poly({3}), Poly({5}), Poly({0, 1}), Poly({-6}), Poly({-5})}};

    cout << CalcDet(A) << '\n';
}

void task5() {
    cout << "Task 5 info:\n\n";
    Mat A = vector<vector<ll>>{{4, 8},
                               {-4, -8},
                               {-1, -2},
                               {2, 4},
                               {3, 6}};
    Mat B = vector<vector<ll>>{{-2, 2, 1, -1, 3},
                               {3, 1, -1, 2, -3}};
    Mat C = A * B;
    cout << C << '\n';
    cout << C.GetPoly() << '\n';
}


int main() {
    task1();
    task2();
    task3();
    task4();
    task5();
}