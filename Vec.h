//
// Created by Sergey Pankevich on 25.10.2021.
//

#pragma once

#include <vector>
#include "Num.h"

class Vec {
public:
    Vec() = default;
    explicit Vec(size_t n);
    Vec(const std::vector<Num>& vec);
    Vec(const std::vector<ll>& vec);
    Vec(std::vector<Num>&& vec);
    size_t size() const;
    Vec operator-() const;
    Vec operator+ (const Vec& vec) const;
    Vec operator- (const Vec& vec) const;
    Vec operator* (const Num& x) const;
    Vec operator/ (const Num& x) const;
    Vec& operator+= (const Vec& vec);
    Vec& operator-= (const Vec& vec);
    Vec& operator*= (const Num& x);
    Vec& operator/= (const Num& x);
    Num operator^ (const Vec& vec) const;
    const Num& operator[](size_t i) const;
    Num& operator[](size_t i);
    friend std::ostream& operator << (std::ostream& os, const Vec& vec);
    friend std::istream& operator >> (std::istream& is, Vec& vec);

private:
    std::vector<Num> a_;
};
