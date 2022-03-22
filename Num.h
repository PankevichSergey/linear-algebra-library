//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <cstdint>
#include <iostream>

using ll = int64_t;


class Num {
public:
    Num(ll num, ll den);
    Num(ll x);
    Num();
    Num operator - () const;
    Num operator + (const Num& rhs) const;
    Num operator - (const Num& rhs) const;
    Num operator * (const Num& rhs) const;
    Num operator / (const Num& rhs) const;
    Num& operator += (const Num& rhs);
    Num& operator -= (const Num& rhs);
    Num& operator *= (const Num& rhs);
    Num& operator /= (const Num& rhs);
    bool operator == (const Num& rhs) const;
    bool operator != (const Num& rhs) const;
    bool operator < (const Num& rhs) const;
    Num Abs() const;
    friend std::ostream& operator << (std::ostream& os, const Num& num);
    friend std::istream& operator >> (std::istream& is, Num& num);
    ll Toll() const;
private:
    void Reduce();
    ll num_;
    ll den_;
};


