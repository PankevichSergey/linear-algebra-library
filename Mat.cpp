//
// Created by Sergey Pankevich on 25.10.2021.
//

#include "Mat.h"

Mat::Mat(size_t n): n_(n), m_(n), t_(std::vector<Vec>(n, Vec(n))) {
    if (n == 0) {
        throw std::logic_error("can't create empty matrix");
    }
}

Mat::Mat(size_t m, size_t n): m_(m), n_(n), t_(std::vector<Vec>(m, Vec(n))) {
    if (n == 0 || m == 0) {
        throw std::logic_error("can't create empty matrix");
    }
}

Mat::Mat(const std::vector<Vec> &mat) {
    if (mat.size() == 0 || mat[0].size() == 0) {
        throw std::logic_error("can't create empty matrix");
    }
    m_ = mat.size();
    n_ = mat[0].size();
    t_.reserve(m_);
    for (const Vec& vec : mat) {
        if (vec.size() != n_) {
            throw std::logic_error("can't create matrix with different rows' sizes");
        }
        t_.push_back(vec);
    }
}

Mat Mat::operator+(const Mat &rhs) const {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't add matrices of different size");
    }
    Mat result(m_, n_);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            result[i][j] = t_[i][j] + rhs[i][j];
        }
    }
    return result;
}

Mat Mat::operator-(const Mat &rhs) const {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't subtract matrices of different size");
    }
    Mat result(m_, n_);
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            result[i][j] = t_[i][j] - rhs[i][j];
        }
    }
    return result;
}

Mat Mat::operator*(const Mat &rhs) const {
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

Mat Mat::operator*(const Num &x) const {
    Mat result(t_);
    for (Vec& vec : result.t_) {
        for (size_t j = 0; j < n_; ++j) {
            vec[j] *= x;
        }
    }
    return result;
}

Mat Mat::operator^(ll p) const {
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

Mat &Mat::operator^=(ll p) {
    return *this = *this ^ p;
}

Mat &Mat::operator*=(const Num &x)  {
    for (Vec& vec : t_) {
        for (size_t j = 0; j < n_; ++j) {
            vec[j] *= x;
        }
    }
    return *this;
}

Mat &Mat::operator+=(const Mat &rhs) {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't add matrices of different size");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++j) {
            t_[i][j] += rhs.t_[i][j];
        }
    }
    return *this;
}

Mat &Mat::operator-=(const Mat &rhs) {
    if (this->Height() != rhs.Height() || this->Width() != rhs.Width()) {
        throw std::logic_error("can't subtract matrices of different size");
    }
    for (size_t i = 0; i < m_; ++i) {
        for (size_t j = 0; j < n_; ++i) {
            t_[i][j] -= rhs.t_[i][j];
        }
    }
    return *this;
}

size_t Mat::Height() const {
    return m_;
}

size_t Mat::Width() const {
    return n_;
}

const Vec &Mat::operator[](size_t i) const {
    return t_[i];
}

Vec &Mat::operator[](size_t i) {
    return t_[i];
}

Mat Mat::Identity(size_t n) {
    Mat result(n, n);
    for (size_t i = 0; i < n; ++i) {
        result[i][i] = 1;
    }
    return result;
}

Mat &Mat::operator*=(const Mat &rhs) {
    return *this = *this * rhs;
}

std::ostream &operator<<(std::ostream &os, const Mat &mat) {
    for (const Vec& vec : mat.t_) {
        os << vec << std::endl;
    }
    return os;
}

std::istream &operator>>(std::istream &is, Mat &mat) {
    for (Vec& vec : mat.t_) {
        is >> vec;
    }
    return is;
}

void Mat::Eliminate() {
    size_t done = 0;
    for (size_t j = 0; j < n_; ++j) {
        for (size_t i = done; i < m_; ++i) {
            if (t_[i][j] == 0) {
                continue;
            }
            std::swap(t_[i], t_[done]);
            for (size_t i1 = i + 1; i1 < m_; ++i1) {
                t_[i1] -= t_[i] * (t_[i1][j] / t_[i][j]);
            }
            ++done;
        }
    }
    for (size_t i1 = 0; i1 < done; ++i1) {
        size_t i = done - i1 - 1;
        for (size_t j = 0; j < n_; ++j) {
            if (t_[i][j] != 0) {
                t_[i] /= Num(t_[i][j]);
                for (size_t i2 = i1 + 1; i2 < done; ++i2) {
                    size_t ip = done - i2 - 1;
                    t_[ip] -= t_[i] * t_[ip][j];
                }
                break;
            }
        }
    }
}

Mat::Mat(const std::vector<std::vector<ll>> &mat) {
    if (mat.empty() || mat[0].empty()) {
        throw std::logic_error("can't create empty matrix");
    }
    m_ = mat.size();
    n_ = mat[0].size();
    t_.reserve(m_);
    for (const auto& vec : mat) {
        if (vec.size() != n_) {
            throw std::logic_error("can't create matrix with different rows' sizes");
        }
        t_.emplace_back(vec);
    }
}

bool Mat::operator==(const Mat &rhs) const {
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

bool Mat::operator!=(const Mat &rhs) const {
    return !(*this == rhs);
}

Num Mat::Trace() const {
    if (n_ != m_) {
        throw std::logic_error("trace of not square matrix doesn't exist");
    }
    Num result;
    for (size_t i = 0; i < n_; ++i) {
        result += t_[i][i];
    }
    return result;
}