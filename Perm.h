//
// Created by Sergey Pankevich on 08.12.2021.
//

#ifndef LINAL_PERM_H
#define LINAL_PERM_H

#include <vector>
#include <iostream>

class Perm {
public:
    explicit Perm(const std::vector<int> &a);

    explicit Perm(const std::vector<std::vector<int>> &cycles);

    explicit Perm(size_t n);

    int operator[](int i) const;

    size_t Size() const;

    int Sgn() const;

    std::vector<std::vector<int>> GetCycles() const;

    Perm operator*(const Perm &rhs) const;

    Perm operator^(int a) const;

    void operator*=(const Perm &rhs);

    void operator^=(int a);

    friend std::istream &operator>>(std::istream &is, Perm &p);

    friend std::ostream &operator<<(std::ostream &os, const Perm &p);

    bool operator==(const Perm &rhs) const;

    void IncrementElements();

    void DecrementElements();

    bool NextPermutation();

private:
    std::vector<int> p_;
};


#endif //LINAL_PERM_H
