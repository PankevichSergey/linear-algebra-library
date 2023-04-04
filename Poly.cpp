#include "Poly.h"

#include <algorithm>

int64_t Binpow(int64_t x, int64_t power) {
    if (power == 0) {
        return 1;
    }
    if (power & 1) {
        return x * Binpow(x, power - 1);
    }
    return Binpow(x * x, power / 2);
}

Poly::Mono::Mono(int64_t power, int64_t multiplier) : power(power), multiplier(multiplier) {
}

int64_t Poly::Mono::operator()(int64_t x) const {
    return multiplier * Binpow(x, power);
}

int64_t Poly::operator()(int64_t x) const {
    int64_t result = 0;
    for (const Mono& mono : poly_) {
        result += mono(x);
    }
    return result;
}

bool Poly::Mono::operator!=(const Mono& rhs) const {
    return multiplier != rhs.multiplier || power != rhs.power;
}

bool Poly::Mono::operator<(const Mono& rhs) const {
    return power < rhs.power;
}

Poly::Mono Poly::Mono::operator+(const Mono& rhs) const {
    return Mono(power, multiplier + rhs.multiplier);
}

Poly::Mono Poly::Mono::operator*(const Mono& rhs) const {
    return Mono(power + rhs.power, multiplier * rhs.multiplier);
}

void Poly::Normalize() {
    std::vector<Mono> normalized;
    std::sort(poly_.begin(), poly_.end());
    for (const Mono& mono : poly_) {
        if (normalized.empty() || normalized.back().power < mono.power) {
            normalized.push_back(mono);
        } else {
            normalized.back() = normalized.back() + mono;
        }
        if (normalized.back().multiplier == 0) {
            normalized.pop_back();
        }
    }
    poly_ = std::move(normalized);
}

Poly::Poly(const std::vector<Mono>& monos) {
    poly_ = monos;
    Normalize();
}

Poly::Poly(std::vector<Mono> &&monos) {
    poly_ = std::move(monos);
    Normalize();
}

Poly::Poly(const std::vector<int64_t>& coef) {
    for (size_t i = 0; i < coef.size(); ++i) {
        poly_.emplace_back(i, coef[i]);
    }
    Normalize();
}

bool Poly::operator==(const Poly& rhs) const {
    if (rhs.poly_.size() != poly_.size()) {
        return false;
    }
    for (size_t i = 0; i < poly_.size(); ++i) {
        if (poly_[i] != rhs.poly_[i]) {
            return false;
        }
    }
    return true;
}

bool Poly::operator!=(const Poly& rhs) const {
    return !(*this == rhs);
}

Poly Poly::operator-() const {
    std::vector<Mono> monos;
    for (const Mono& mono : poly_) {
        monos.emplace_back(mono.power, -mono.multiplier);
    }
    return Poly(monos);
}

Poly Poly::operator+(const Poly& rhs) const {
    std::vector<Mono> monos = poly_;
    monos.insert(monos.end(), rhs.poly_.begin(), rhs.poly_.end());
    return Poly(monos);
}

Poly Poly::operator-(const Poly& rhs) const {
    return *this + -rhs;
}

void Poly::operator+=(const Poly& rhs) {
    *this = *this + rhs;
}

void Poly::operator-=(const Poly& rhs) {
    *this = *this - rhs;
}

Poly Poly::operator*(const Poly& rhs) const {
    std::vector<Mono> monos;
    for (const Mono& left_mono : poly_) {
        for (const Mono& right_mono : rhs.poly_) {
            monos.push_back(left_mono * right_mono);
        }
    }
    return Poly(monos);
}

std::ostream& operator<<(std::ostream& out, const Poly::Mono& mono) {
    out << mono.multiplier;
    if (mono.power) {
        out << "x^" << mono.power;
    }
    return out;
}
std::ostream& operator<<(std::ostream& out, const Poly& poly) {
    if (poly.poly_.empty()) {
        out << " 0";
    } else {
        out << " " << poly.poly_.back();
        for (size_t i = 2; i <= poly.poly_.size(); ++i) {
            out << (poly.poly_[poly.poly_.size() - i].multiplier > 0 ? " + " : " ") << poly.poly_[poly.poly_.size() - i];
        }
    }
    return out;
}
