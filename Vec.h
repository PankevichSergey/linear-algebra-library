//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <vector>

template <typename T>
class Vec {
public:
    Vec() = default;

    explicit Vec(size_t n);

    explicit Vec(const std::vector<T> &vec);

    explicit Vec(std::vector<T> &&vec);

    size_t size() const;

    Vec operator-() const;

    Vec operator+(const Vec &vec) const;

    Vec operator-(const Vec &vec) const;

    Vec operator*(const T &x) const;

    Vec operator/(const T &x) const;

    Vec &operator+=(const Vec &vec);

    Vec &operator-=(const Vec &vec);

    Vec &operator*=(const T &x);

    Vec &operator/=(const T &x);

    T operator^(const Vec &vec) const;

    const T &operator[](size_t i) const;

    T &operator[](size_t i);

    template <typename T1>
    friend std::ostream &operator<<(std::ostream &os, const Vec<T1> &vec);

    template <typename T1>
    friend std::istream &operator>>(std::istream &is, Vec<T1> &vec);

private:
    std::vector<T> a_;
};


template<typename T>
Vec<T>::Vec(size_t n) : a_(n, T()) {}

template<typename T>
Vec<T>::Vec(const std::vector<T> &vec) {
    a_ = vec;
}

template<typename T>
Vec<T>::Vec(std::vector<T> &&vec) {
    a_ = std::move(vec);
}
template<typename T>
Vec<T> Vec<T>:: operator-() const {
    Vec result;
    result.a_.reserve(a_.size());
    for (const T &x : a_) {
        result.a_.push_back(-x);
    }
    return result;
}

template<typename T>
Vec<T> Vec<T>::operator+(const Vec &vec) const {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors of different length");
    }
    Vec result(a_);
    for (size_t i = 0; i < vec.size(); ++i) {
        result[i] += vec[i];
    }
    return result;
}

template<typename T>
Vec<T> Vec<T>::operator-(const Vec &vec) const {
    return *this + (-vec);
}

template<typename T>
Vec<T> Vec<T>::operator*(const T &x) const {
    Vec result(a_);
    for (T &num : result.a_) {
        num *= x;
    }
    return result;
}

template<typename T>
Vec<T> Vec<T>::operator/(const T &x) const {
    Vec result(a_);
    for (T &num : result.a_) {
        num /= x;
    }
    return result;
}
template<typename T>
Vec<T>& Vec<T>::operator+=(const Vec &vec) {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors with different lengths");
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        a_[i] += vec[i];
    }
    return *this;
}

template<typename T>
Vec<T>& Vec<T>::operator-=(const Vec &vec) {
    if (this->size() != vec.size()) {
        throw std::logic_error("can't add and subtract vectors with different lengths");
    }
    for (size_t i = 0; i < vec.size(); ++i) {
        a_[i] -= vec[i];
    }
    return *this;
}
template<typename T>
Vec<T>& Vec<T>::operator*=(const T &x) {
    for (T &num: a_) {
        num *= x;
    }
    return *this;
}


template <typename T>
Vec<T> &Vec<T>::operator/=(const T &x) {
    for (T &num : a_) {
        num /= x;
    }
    return *this;
}


template <typename T>
T Vec<T>::operator^(const Vec<T> &vec) const {
    if (this->size() != vec.size()) {
        throw std::logic_error("dot product of vectors with different lengths doesn't exists");
    }
    T result;
    for (size_t i = 0; i < vec.size(); ++i) {
        result += a_[i] * vec[i];
    }
    return result;
}


template <typename T>
const T& Vec<T>::operator[](size_t i) const {
    return a_[i];
}


template <typename T>
T& Vec<T>::operator[](size_t i) {
    return a_[i];
}


template <typename T>
std::ostream &operator<<(std::ostream &os, const Vec<T> &vec) {
    for (const T &num : vec.a_) {
        os << num << ' ';
    }
    return os;
}


template <typename T>
std::istream &operator>>(std::istream &is, Vec<T> &vec) {
    for (T &num : vec.a_) {
        is >> num;
    }
    return is;
}


template <typename T>
size_t Vec<T>::size() const {
    return a_.size();
}