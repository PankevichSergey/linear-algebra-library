//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <iostream>
#include <vector>
#include "Vec.h"
#include "Perm.h"
#include "Poly.h"
#include "Num.h"


template<typename T>
class Mat {
public:
    static Mat<T> ByCols(const std::vector<Vec<T>> &mat);

    static Mat<T> ByCol(const Vec<T> &vec);

    static Mat<T> Identity(size_t n);

    explicit Mat(size_t n);

    explicit Mat(size_t m, size_t n);

    explicit Mat(const std::vector<Vec<T>> &mat);

    explicit Mat(std::vector<Vec<T>> &&mat);

    Mat operator+(const Mat &rhs) const;

    Mat operator-(const Mat &rhs) const;

    Mat operator*(const Mat &rhs) const;

    Mat operator*(const T &x) const;

    Mat operator^(int64_t p) const;

    Mat &operator^=(int64_t p);

    Mat &operator*=(const T &x);

    Mat &operator+=(const Mat &rhs);

    Mat &operator-=(const Mat &rhs);

    Mat &operator*=(const Mat &rhs);

    const Vec<T> &operator[](size_t i) const;

    Vec<T> &operator[](size_t i);

    bool operator==(const Mat &rhs) const;

    bool operator!=(const Mat &rhs) const;

    Mat ConRight(const Mat &rhs) const;

    Mat ConDown(const Mat &rhs) const;

    bool HasInverse() const;

    Mat GetInverse() const;

    Mat SliceRows(size_t l, size_t r) const;

    Mat SliceCols(size_t l, size_t r) const;

    size_t Height() const;

    size_t Width() const;

    template<typename T1>
    friend std::ostream &operator<<(std::ostream &os, const Mat<T1> &mat);

    template<typename T1>
    friend std::istream &operator>>(std::istream &is, Mat<T1> &mat);

    void Eliminate();

    T Trace() const;

    T Det() const;

    std::vector<size_t> GetColBasis() const;

    size_t Rank();

protected:
    size_t n_ = 0;
    size_t m_ = 0;
    std::vector<Vec<T>> t_;
};


class NumMat : public Mat<Num> {
public:
    Poly GetCharPoly() const;
};

template<typename T>
Mat<T>::Mat(size_t n) : n_(n), m_(n), t_(std::vector<Vec<T>>(n, Vec<T>(n))) {
    if (n == 0) {
        throw std::logic_error("can't create empty matrix");
    }
}

template<typename T>
Mat<T>::Mat(size_t m, size_t n) : m_(m), n_(n), t_(std::vector<Vec<T>>(m, Vec<T>(n))) {
    if (n == 0 || m == 0) {
        throw std::logic_error("can't create empty matrix");
    }
}

template<typename T>
Mat<T>::Mat(const std::vector<Vec<T>> &mat) {
    if (mat.empty() == 0 || mat[0].size() == 0) {
        throw std::logic_error("can't create empty matrix");
    }
    m_ = mat.size();
    n_ = mat[0].size();
    t_.reserve(m_);
    for (const Vec<T> &vec : mat) {
        if (vec.size() != n_) {
            throw std::logic_error("can't create matrix with different rows' sizes");
        }
        t_.push_back(vec);
    }
}

template<typename T>
Mat<T>::Mat(std::vector<Vec<T>> &&mat) {
    if (mat.size() == 0 || mat[0].size() == 0) {
        throw std::logic_error("can't create empty matrix");
    }
    m_ = mat.size();
    n_ = mat[0].size();
    t_.reserve(m_);
    for (const Vec<T> &vec : mat) {
        if (vec.size() != n_) {
            throw std::logic_error("can't create matrix with different rows' sizes");
        }
        t_.emplace_back(vec);
    }
}

template<typename T>
Mat<T> Mat<T>::operator+(const Mat<T> &rhs) const {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't add matrices with different size");
    }
    Mat result(m_, n_);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            result[i][j] = t_[i][j] + rhs[i][j];
        }
    }
    return result;
}

template<typename T>
Mat<T> Mat<T>::operator-(const Mat<T> &rhs) const {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't subtract matrices with different size");
    }
    Mat result(m_, n_);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            result[i][j] = t_[i][j] - rhs[i][j];
        }
    }
    return result;
}


template<typename T>
Mat<T> Mat<T>::operator*(const Mat<T> &rhs) const {
    if (this->Width() != rhs.Height()) {
        throw std::logic_error("can't multiply matrices with different width and height");
    }
    Mat result(m_, rhs.n_);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < rhs.n_; ++j) {
            for (size_t k = 0; k < n_; ++k) {
                result[i][j] += t_[i][k] * rhs[k][j];
            }
        }
    }
    return result;
}


template<typename T>
Mat<T> Mat<T>::operator*(const T &x) const {
    Mat result(t_);
    for (Vec<T> &vec : result.t_) {
        for (size_t j = 0; j < n_; ++j) {
            vec[j] *= x;
        }
    }
    return result;
}

template<typename T>
Mat<T> Mat<T>::operator^(int64_t p) const {
    Mat result = Identity(m_);
    Mat power = *this;
    while (p > 0) {
        if (p & 1) {
            result = result * power;
        }
        p /= 2;
        if (p == 0) {
            break;
        }
        power = power * power;
    }
    return result;
}


template<typename T>
Mat<T> &Mat<T>::operator^=(int64_t p) {
    return *this = *this ^ p;
}

template<typename T>
Mat<T> &Mat<T>::operator*=(const T &x) {
    for (Vec<T> &vec : t_) {
        for (size_t j = 0; j < n_; ++j) {
            vec[j] *= x;
        }
    }
    return *this;
}

template<typename T>
Mat<T> &Mat<T>::operator+=(const Mat<T> &rhs) {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't multiply matrices with different width and height");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            t_[i][j] += rhs.t_[i][j];
        }
    }
    return *this;
}

template<typename T>
Mat<T> &Mat<T>::operator-=(const Mat &rhs) {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't subtract matrices with different size");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            t_[i][j] -= rhs.t_[i][j];
        }
    }
    return *this;
}


template<typename T>
size_t Mat<T>::Height() const {
    return m_;
}


template<typename T>
size_t Mat<T>::Width() const {
    return n_;
}


template<typename T>
const Vec<T> &Mat<T>::operator[](size_t i) const {
    return t_[i];
}

template<typename T>
Vec<T> &Mat<T>::operator[](size_t i) {
    return t_[i];
}


template<typename T>
Mat<T> Mat<T>::Identity(size_t n) {
    Mat result(n, n);
    for (size_t i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    return result;
}

template<typename T>
Mat<T> &Mat<T>::operator*=(const Mat<T> &rhs) {
    return *this = *this * rhs;
}


template<typename T>
std::ostream &operator<<(std::ostream &os, const Mat<T> &mat) {
    for (const Vec<T> &vec : mat.t_) {
        os << vec << std::endl;
    }
    return os;
}

template<typename T>
std::istream &operator>>(std::istream &is, Mat<T> &mat) {
    for (Vec<T> &vec : mat.t_) {
        is >> vec;
    }
    return is;
}


template<typename T>
void Mat<T>::Eliminate() {
    size_t done = 0;
    for (size_t j = 0; j < n_; ++j) {
        for (size_t i = done; i < m_; ++i) {
            if (t_[i][j] == 0) {
                continue;
            }
            for (size_t i1 = i + 1; i1 < m_; ++i1) {
                t_[i1] -= t_[i] * (t_[i1][j] / t_[i][j]);
            }
            std::swap(t_[i], t_[done]);
            ++done;
        }
    }
    for (size_t i1 = 0; i1 < done; ++i1) {
        size_t i = done - i1 - 1;
        for (size_t j = 0; j < n_; ++j) {
            if (t_[i][j] != 0) {
                t_[i] /= T(t_[i][j]);
                for (size_t i2 = i1 + 1; i2 < done; ++i2) {
                    size_t ip = done - i2 - 1;
                    t_[ip] -= t_[i] * t_[ip][j];
                }
                break;
            }
        }
    }
}


template<typename T>
bool Mat<T>::operator==(const Mat<T> &rhs) const {
    if (n_ != rhs.n_ || m_ != rhs.m_) {
        return false;
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            if (t_[i][j] != rhs[i][j]) {
                return false;
            }
        }
    }
    return true;
}

template<typename T>
bool Mat<T>::operator!=(const Mat<T> &rhs) const {
    return !(*this == rhs);
}

template<typename T>
T Mat<T>::Trace() const {
    if (n_ != m_) {
        throw std::logic_error("trace of not square matrix doesn't exist");
    }
    T result;
    for (size_t i = 0; i < n_; ++i) {
        result += t_[i][i];
    }
    return result;
}

template<typename T>
Mat<T> Mat<T>::ConRight(const Mat<T> &rhs) const {
    assert(rhs.Height() == this->Height());
    Mat res(m_, n_ + rhs.n_);
    for (int i = 0; i < m_; ++i) {
        for (int j = 0; j < n_; ++j) {
            res[i][j] = t_[i][j];
        }
        for (int j = 0; j < rhs.n_; ++j) {
            res[i][n_ + j] = rhs[i][j];
        }
    }
    return res;
}


template<typename T>
Mat<T> Mat<T>::ConDown(const Mat<T> &rhs) const {
    assert(rhs.Width() == this->Width());
    Mat res(m_ + rhs.m_, n_);
    for (int j = 0; j < n_; ++j) {
        for (int i = 0; i < m_; ++i) {
            res[i][j] = t_[i][j];
        }
        for (int i = 0; i < rhs.m_; ++i) {
            res[i + m_][j] = rhs[i][j];
        }
    }
    return res;
}


template<typename T>
bool Mat<T>::HasInverse() const {
    if (n_ != m_) {
        throw std::logic_error("non-square matrix doesn't have inverse");
    }
    Mat help(*this);
    help.Eliminate();
    return help == Identity(m_);
}


template<typename T>
Mat<T> Mat<T>::GetInverse() const {
    if (!this->HasInverse()) {
        throw std::logic_error("can't get inverse of matrix that is not invertible");
    }
    Mat help = ConRight(Identity(m_));
    help.Eliminate();
    return help.SliceCols(n_, n_ + n_);
}

template<typename T>
Mat<T> Mat<T>::SliceRows(size_t l, size_t r) const {
    if (r <= l || r > m_) {
        throw std::logic_error("invalid slice bounds");
    }
    Mat help(r - l, n_);
    for (size_t i = 0; i < r - l; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            help[i][j] = t_[l + i][j];
        }
    }
    return help;
}

template<typename T>
Mat<T> Mat<T>::SliceCols(size_t l, size_t r) const {
    if (r <= l || r > n_) {
        throw std::logic_error("invalid slice bounds");
    }
    Mat help(m_, r - l);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < r - l; ++j) {
            help[i][j] = t_[i][l + j];
        }
    }
    return help;
}


template<typename T>
T Mat<T>::Det() const {
    if (n_ != m_) {
        throw std::logic_error("det of non-square matrix is not defined");
    }
    T det(1);
    std::vector<Vec<T>> t(t_);
    for (size_t j = 0; j < n_; ++j) {
        size_t best = n_;
        for (size_t i = j; i < n_; ++i) {
            if (t[i][j] == 0) {
                continue;
            }
            if (best == n_ || abs(t[best][j]) < abs(t[i][j])) {
                best = i;
            }
        }
        if (best == n_) {
            return 0;
        }
        if (best != j) {
            det *= -1;
            std::swap(t[best], t[j]);
        }
        for (size_t i = j + 1; i < n_; ++i) {
            t[i] -= t[j] * (t[i][j] / t[j][j]);
        }
        det *= t[j][j];
    }
    return det;
}


Poly PolyDet(const std::vector<std::vector<Poly>> &A) {
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


template<typename T>
Mat<T> Mat<T>::ByCols(const std::vector<Vec<T>> &mat) {
    if (mat.empty()) {
        throw std::logic_error("can't create empty matrix");
    }
    size_t m = mat[0].size();
    size_t n = mat.size();
    Mat res(m, n);
    for (size_t i = 0; i < m; ++i) {
        for (size_t j = 0; j < n; ++j) {
            res[i][j] = mat[j][i];
        }
    }
    return res;
}


template<typename T>
Mat<T> Mat<T>::ByCol(const Vec<T> &vec) {
    return ByCols({vec});
}

template<typename T>
std::vector<size_t> Mat<T>::GetColBasis() const {
    std::vector<size_t> res;
    Mat help(*this);
    help.Eliminate();
    size_t i = 0;
    for (size_t j = 0; j < n_ && i < m_; ++j) {
        if (help[i][j] != 0) {
            res.push_back(j);
            ++i;
        }
    }
    return res;
}


template<typename T>
size_t Mat<T>::Rank() {
    Mat help(*this);
    help.Eliminate();
    size_t rank = 0;
    size_t i = 0;
    for (size_t j = 0; j < n_ && i < m_; ++j) {
        if (help[i][j] != 0) {
            ++rank;
            ++i;
        }
    }
    return rank;
}

Poly NumMat::GetCharPoly() const {
    if (n_ != m_) {
        throw std::logic_error("characteristic polynomial of non-square matrix is not defined");
    }
    std::vector<std::vector<Poly>> help(n_, std::vector<Poly>(n_));
    for (int i = 0; i < n_; ++i) {
        for (int j = 0; j < n_; ++j) {
            if (i != j) {
                help[i][j] = Poly({-t_[i][j].Toll()});
            } else {
                help[i][j] = Poly({-t_[i][j].Toll(), 1});
            }
        }
    }
    return PolyDet(help);
}
