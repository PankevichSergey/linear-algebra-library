//
// Created by Sergey Pankevich on 25.10.2021.
//

#include "Num.h"
#include <algorithm>

ll gcd(ll a, ll b) {
    a = std::abs(a);
    b = std::abs(b);
    while (b) {
        a %= b;
        std::swap(a, b);
    }
    return a;
}

Num::Num(): num_(0), den_(1) {}

Num::Num(ll x): num_(x), den_(1) {}

Num::Num(ll num, ll den): num_(num), den_(den) {
    Reduce();
}

Num Num::operator-() const {
    return Num(-num_, den_);
}

Num Num::operator+(const Num &rhs) const {
    return Num(num_ * rhs.den_ + rhs.num_ * den_, den_ * rhs.den_);
}

Num Num::operator-(const Num &rhs) const {
    return *this + (-rhs);
}

Num Num::operator*(const Num &rhs) const {
    return Num(num_ * rhs.num_, den_ * rhs.den_);
}

Num Num::operator/(const Num &rhs) const {
    if (rhs.num_ == 0) {
        throw std::logic_error("division by zero");
    }
    return Num(num_ * rhs.den_, den_ * rhs.num_);
}

Num& Num::operator+=(const Num &rhs) {
    num_ *= rhs.den_;
    num_ += rhs.num_ * den_;
    den_ *= rhs.den_;
    Reduce();
    return *this;
}

Num& Num::operator-=(const Num &rhs) {
    num_ *= rhs.den_;
    num_ -= rhs.num_ * den_;
    den_ *= rhs.den_;
    Reduce();
    return *this;
}

Num& Num::operator*=(const Num &rhs) {
    num_ *= rhs.num_;
    den_ *= rhs.den_;
    Reduce();
    return *this;
}

Num& Num::operator/=(const Num &rhs) {
    if (rhs.num_ == 0) {
        throw std::logic_error("division by zero");
    }
    num_ *= rhs.den_;
    den_ *= rhs.num_;
    Reduce();
    return *this;
}

std::ostream &operator<<(std::ostream &os, const Num &num) {
    os << num.num_;
    if (num.den_ != 1) {
        os << '/' << num.den_;
    }
    return os;
}

void Num::Reduce() {
    ll g = gcd(num_, den_);
    num_ /= g;
    den_ /= g;
    if (den_ < 0) {
        den_ *= -1;
        num_ *= -1;
    }
}

std::istream &operator>>(std::istream &is, Num &num) {
    is >> num.num_;
    num.den_ = 1;
    return is;
}

bool Num::operator==(const Num &rhs) const {
    return num_ == rhs.num_ && den_ == rhs.den_;
}

bool Num::operator!=(const Num &rhs) const {
    return num_ != rhs.num_ || den_ != rhs.den_;
}

ll Num::Toll() const {
    if (den_ != 1) {
        throw std::logic_error("can't cast rational to integer");
    }
    return num_;
}


