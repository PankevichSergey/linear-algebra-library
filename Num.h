//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <cstdint>
#include <iostream>


class Num {
public:
    Num(int64_t num, int64_t den);

    Num(int64_t x);

    Num();

    Num operator-() const;

    Num operator+(const Num &rhs) const;

    Num operator-(const Num &rhs) const;

    Num operator*(const Num &rhs) const;

    Num operator/(const Num &rhs) const;

    Num &operator+=(const Num &rhs);

    Num &operator-=(const Num &rhs);

    Num &operator*=(const Num &rhs);

    Num &operator/=(const Num &rhs);

    bool operator==(const Num &rhs) const;

    bool operator!=(const Num &rhs) const;

    bool operator<(const Num &rhs) const;

    Num Abs() const;

    friend std::ostream &operator<<(std::ostream &os, const Num &num);

    friend std::istream &operator>>(std::istream &is, Num &num);

    int64_t Toll() const;

private:
    void Reduce();

    int64_t num_;
    int64_t den_;
};


