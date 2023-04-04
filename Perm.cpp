//
// Created by Sergey Pankevich on 08.12.2021.
//

#include "Perm.h"
#include <numeric>


Perm::Perm(const std::vector<int> &a) {
    this->p_ = a;
}

Perm::Perm(int n) {
    p_.resize(n);
    std::iota(p_.begin(), p_.end(), 0);
}

int Perm::operator[](int i) const {
    return p_[i];
}

size_t Perm::Size() const {
    return p_.size();
}

Perm Perm::operator*(const Perm &rhs) const {
    if (rhs.Size() != this->Size()) {
        throw std::logic_error("can't multiply permutations of different lengths");
    }
    Perm res(rhs.Size());
    for (int i = 0; i < rhs.Size(); ++i) {
        res.p_[i] = p_[rhs[i]];
    }
    return res;
}

Perm Perm::operator^(int a) const {
    if (a == -1) {
        Perm res(this->Size());
        for (int i = 0; i < this->Size(); ++i) {
            res.p_[p_[i]] = i;
        }
        return res;
    }
    if (a < 0) {
        return (*this ^ (-1)) ^ (-a);
    }
    Perm res(this->Size());
    Perm help = *this;
    while (a != 0) {
        if (a & 1) {
            res *= help;
        }
        a /= 2;
        help *= help;
    }
    return res;
}

void Perm::operator*=(const Perm &rhs) {
    *this = *this * rhs;
}

void Perm::operator^=(int a) {
    *this = *this ^ a;
}

std::istream &operator>>(std::istream &is, Perm &p) {
    for (int &x : p.p_) {
        is >> x;
    }
    return is;
}

std::ostream &operator<<(std::ostream &os, const Perm &p) {
    for (const int x : p.p_) {
        os << x << ' ';
    }
    return os;
}

Perm::Perm(const std::vector<std::vector<int>> &cycles) {

    for (const auto &cycle : cycles) {
        for (int x : cycle) {
            if (p_.size() <= x) {
                p_.resize(x + 1, -1);
            }
        }
        for (int i = 0; i < cycle.size(); ++i) {
            if (i == 0) {
                p_[cycle.back()] = cycle[i];
            } else {
                p_[cycle[i - 1]] = cycle[i];
            }
        }
    }
    for (int i = 0; i < p_.size(); ++i) {
        if (p_[i] == -1) {
            p_[i] = i;
        }
    }
}

bool Perm::operator==(const Perm &rhs) const {
    return p_ == rhs.p_;
}

void Perm::IncrementElements() {
    for (int &x : p_) {
        ++x;
    }
}

void Perm::DecrementElements() {
    for (int &x : p_) {
        --x;
    }
}

bool Perm::NextPermutation() {
    for (int i = static_cast<int>(p_.size()) - 1; i >= 0; --i) {
        if (i == 0) {
            std::reverse(p_.begin(), p_.end());
            return false;
        }
        if (p_[i - 1] > p_[i]) {
            continue;
        }
        int first_less = this->Size();
        for (int j = i; j < p_.size(); ++j) {
            if (p_[j] < p_[i - 1]) {
                first_less = j;
                break;
            }
        }
        std::swap(p_[i - 1], p_[first_less - 1]);
        std::reverse(p_.begin() + i, p_.end());
        return true;
    }
    return false;
}

std::vector<std::vector<int>> Perm::GetCycles() const {
    std::vector<char> used(this->Size());
    std::vector<std::vector<int>> cycles;
    for (int i = 0; i < this->Size(); ++i) {
        if (!used[i]) {
            auto &cycle = cycles.emplace_back();
            int j = i;
            while (!used[j]) {
                cycle.push_back(j);
                used[j] = 1;
                j = p_[j];
            }
        }
    }
    return cycles;
}

int Perm::Sgn() const {
    if (GetCycles().size() % 2 == this->Size() % 2) {
        return 1;
    }
    return -1;
}
