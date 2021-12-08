#pragma once

#include <iostream>
#include <vector>

int64_t Binpow(int64_t x, int64_t power);

class Poly {
public:
    struct Mono {
        int64_t power;
        int64_t multiplier;
        Mono(int64_t power, int64_t multiplier);
        int64_t operator()(int64_t x) const;
        bool operator!=(const Mono& rhs) const;
        bool operator<(const Mono& rhs) const;
        Mono operator+(const Mono& rhs) const;
        Mono operator*(const Mono& rhs) const;
    };
    Poly(const std::vector<int64_t>& coef);
    Poly(const std::vector<Mono>& monos);
    Poly() = default;
    int64_t operator()(int64_t x) const;
    bool operator==(const Poly& rhs) const;
    bool operator!=(const Poly& rhs) const;
    Poly operator-() const;
    Poly operator+(const Poly& rhs) const;
    Poly operator-(const Poly& rhs) const;
    void operator+=(const Poly& rhs);
    void operator-=(const Poly& rhs);
    Poly operator*(const Poly& rhs) const;
    friend std::ostream& operator<<(std::ostream& out, const Poly& poly);

private:
    std::vector<Mono> poly_;
    void Normalize();
};
