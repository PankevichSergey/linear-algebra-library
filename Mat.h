//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <iostream>
#include <vector>
#include "Num.h"
#include "Vec.h"


class Mat {
public:
    static Mat Identity(size_t n);
    explicit Mat(size_t n);
    Mat(size_t m, size_t n);
    Mat(const std::vector<Vec>& mat);
    Mat(const std::vector<std::vector<ll>>& mat);
    Mat operator + (const Mat& rhs) const;
    Mat operator - (const Mat& rhs) const;
    Mat operator * (const Mat& rhs) const;
    Mat operator * (const Num& x) const;
    Mat operator ^ (ll p) const;
    Mat& operator^= (ll p);
    Mat& operator *= (const Num& x) ;
    Mat& operator += (const Mat& rhs);
    Mat& operator -= (const Mat& rhs);
    Mat& operator *= (const Mat& rhs);
    const Vec& operator[](size_t i) const;
    Vec& operator[](size_t i);
    bool operator == (const Mat& rhs) const;
    bool operator != (const Mat& rhs) const;
    size_t Height() const;
    size_t Width() const;
    friend std::ostream& operator << (std::ostream& os, const Mat& mat);
    friend std::istream& operator >> (std::istream& is, Mat& mat);
    void Eliminate();
    Num Trace() const;
private:
    size_t m_ = 0;
    size_t n_ = 0;
    std::vector<Vec> t_;
};



