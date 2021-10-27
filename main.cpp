#include <iostream>
#include "Mat.h"

using namespace std;


void task1() {
    cout << "Task1 info:\n";
    Mat a = vector<vector<ll>>{{2,  -1, -1},
                               {-2, -4, 6},
                               {-1, 3,  -2},
                               {1,  2,  -3},
                               {3,  4,  -7}
    };
    Mat b = vector<vector<ll>>{{-2, 0, 0, 1},
                               {2,  0, 1, 0},
                               {1,  1, 0, 0}
    };
    Mat c = a * b;
    cout << c << '\n';
    c.Eliminate();
    cout << c << '\n';
}

void task5() {
    cout << "Task5 info:\n";
    Mat a = vector<vector<ll>>{{4,  0},
                               {1,  0},
                               {-2, 0}
    };
    Mat b = vector<vector<ll>>{{0, 0,  0},
                               {3, -4, 4}
    };
    Mat A = vector<vector<ll>>{{1, 8,  -8},
                               {7, -7, 7},
                               {1, -6, 6}
    };
    for (a[0][1] = -2; a[0][1] != 3; a[0][1] += 1) {
        for (a[1][1] = -2; a[1][1] != 3; a[1][1] += 1) {
            for (a[2][1] = -2; a[2][1] != 3; a[2][1] += 1) {
                for (b[0][0] = -2; b[0][0] != 3; b[0][0] += 1) {
                    for (b[0][1] = -2; b[0][1] != 3; b[0][1] += 1) {
                        for (b[0][2] = -2; b[0][2] != 3; b[0][2] += 1) {
                            if (a * b == A) {
                                cout << a << '\n';
                                cout << b << '\n';
                                cout << b * a << '\n';
                                cout << (A^2) * Num(1, 7) << '\n';
                                return;
                            }
                        }
                    }
                }
            }
        }
    }

}

void task3() {
    cout << "Task3 info:\n";
    Mat h = vector<vector<ll>>{{9,  2,  -3, 0,  0,  0},
                               {-9, -7, -6, 0,  0,  0},
                               {0,  0,  0,  9,  2,  -3},
                               {0,  0,  0,  -9, -7, -6}
    };
    cout << h << '\n';
    h.Eliminate();
    cout << h << '\n';
}

void task2() {
    cout << "Task2 info\n";

    // t = 0 solver
    auto build = [](int t) {
        cout << "t = " << t << " :\n";
        return vector<vector<ll>>{{3, 0, -4 * t},
                                  {-2, 3, -8 - 2 * t},
                                  {0, 0, 3 + t}
        };
    };
    {
        Mat A = build(0);
        cout << A << '\n';
        cout << (A^2) << '\n';
        Mat c = vector<vector<ll>>{{1, 3,  9},
                                   {0, -2, -12},
                                   {0, -8, -48}
        };
        c.Eliminate();
        cout << c << '\n';
    }

}

int main() {
    task1();
    task2();
    task3();
    task5();
}