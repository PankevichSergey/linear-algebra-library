//
// Created by Sergey Pankevich on 25.10.2021.
//

#include "Vec.h"


Vec::Vec(size_t n) : a_(n, Num()) {}

Vec::Vec(const std::vector<Num> &vec) {
    a_ = vec;
}

Vec::Vec(std::vector<Num> &&vec) {
    a_ = std::move(vec);
}

Vec Vec::operator-() const {
    Vec result;
    result.a_.reserve(a_.size());
    for (const Num &x : a_) {
        result.a_.push_back(-x);
    }
    return result;
}

Vec Vec::operator+(const Vec &vec) const {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors of different length");
    }
    Vec result(a_);
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] += vec[i];
    }
    return result;
}

Vec Vec::operator-(const Vec &vec) const {
    return *this + (-vec);
}

Vec Vec::operator*(const Num &x) const {
    Vec result(a_);
    for (Num &num : result.a_) {
        num *= x;
    }
    return result;
}

Vec Vec::operator/(const Num &x) const {
    Vec result(a_);
    for (Num &num : result.a_) {
        num /= x;
    }
    return result;
}

Vec &Vec::operator+=(const Vec &vec) {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors with different lengths");
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        a_[i] += vec[i];
    }
    return *this;
}

Vec &Vec::operator-=(const Vec &vec) {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors with different lengths");
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        a_[i] -= vec[i];
    }
    return *this;
}

Vec &Vec::operator*=(const Num &x) {
    for (Num &num: a_) {
        num *= x;
    }
    return *this;
}

Vec &Vec::operator/=(const Num &x) {
    for (Num &num : a_) {
        num /= x;
    }
    return *this;
}

Num Vec::operator^(const Vec &vec) const {
    if (this->size() != vec.size()) {
        throw std::logic_error("dot product of vectors with different lengths doesn't exists");
    }
    Num result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += a_[i] * vec[i];
    }
    return result;
}

const Num &Vec::operator[](size_t i) const {
    return a_[i];
}

Num &Vec::operator[](size_t i) {
    return a_[i];
}

std::ostream &operator<<(std::ostream &os, const Vec &vec) {
    for (const Num &num : vec.a_) {
        os << num << ' ';
    }
    return os;
}

std::istream &operator>>(std::istream &is, Vec &vec) {
    for (Num &num : vec.a_) {
        is >> num;
    }
    return is;
}

size_t Vec::size() const {
    return a_.size();
}







