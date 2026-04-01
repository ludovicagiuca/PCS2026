#pragma once

#include <concepts>
#include <iostream>
#include <numeric>

// Convenzioni:
// num != 0, den == 0  -> ±Inf
// num == 0, den == 0  -> NaN

template<typename I> requires std::integral<I>
class rational {
    I num_;
    I den_;

    void simplify() {
        if (den_ == 0) {
            if (num_ != 0) {
                if (num_ > 0) {
                    num_ = 1;
                } else {
                    num_ = -1;
                }
            }
            return;
        }

        I g = std::gcd(num_, den_);
        num_ /= g;
        den_ /= g;

        if (den_ < 0) {
            num_ = -num_;
            den_ = -den_;
        }
    }

public:
    rational() : num_(0), den_(1) {}

    rational(I n, I d) : num_(n), den_(d) {
        simplify();
    }

    I num() const { return num_; }
    I den() const { return den_; }

    bool is_nan() const {
        return num_ == 0 && den_ == 0;
    }

    bool is_inf() const {
        return den_ == 0 && num_ != 0;
    }


    // +=
    rational& operator+=(const rational& other) {

        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (is_inf() || other.is_inf()) {
            if (is_inf() && other.is_inf() && num_ != other.num_) {
                num_ = 0;
                den_ = 0; // +inf-inf = NaN
                } else {
                    // risultato = infinito
                    if (!is_inf()) {
                        num_ = other.num_;
                    }
                    den_ = 0;
                }
            return *this;
        }

        num_ = num_ * other.den_ + other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    rational operator+(const rational& other) const {
        rational tmp = *this;
        tmp += other;
        return tmp;
    }


    // -=
    rational& operator-=(const rational& other) {

        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (is_inf() || other.is_inf()) {
            if (is_inf() && other.is_inf() && num_ == other.num_) {
                num_ = 0;
                den_ = 0; // +inf-inf = NaN
            } else {
                if (!is_inf()) {
                    num_ = -other.num_;
                }
                den_ = 0;
            }
            return *this;
        }

        num_ = num_ * other.den_ - other.num_ * den_;
        den_ = den_ * other.den_;
        simplify();
        return *this;
    }

    rational operator-(const rational& other) const {
        rational tmp = *this;
        tmp -= other;
        return tmp;
    }


    // *=
    rational& operator*=(const rational& other) {

        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        if (is_inf() || other.is_inf()) {
            if (num_ == 0 || other.num_ == 0) {
            num_ = 0;
            den_ = 0; // 0*inf = NaN
            } else {
                if (num_ * other.num_ > 0) {
                    num_ = 1;
                } else {
                    num_ = -1;
                }
                den_ = 0;
            }

        return *this;
    }

        num_ *= other.num_;
        den_ *= other.den_;
        simplify();
        return *this;
    }

    rational operator*(const rational& other) const {
        rational tmp = *this;
        tmp *= other;
        return tmp;
    }


    // /=
    rational& operator/=(const rational& other) {

        if (is_nan() || other.is_nan()) {
            num_ = 0;
            den_ = 0;
            return *this;
        }

        // divisione per zero → Inf o NaN
        if (other.num_ == 0) {
            if (num_ == 0) {
                num_ = 0;
                den_ = 0; // 0/0= NaN
            } else {
                den_ = 0;
            }
            return *this;
        }

        if (is_inf() || other.is_inf()) {

            if (is_inf() && other.is_inf()) {
                num_ = 0;
                den_ = 0; // inf/inf = NaN
            } else if (is_inf()) {
                den_ = 0; // inf/x = inf
            } else {
                num_ = 0;
                den_ = 1; // x/inf = 0
            }

            return *this;
        }

        num_ *= other.den_;
        den_ *= other.num_;
        simplify();
        return *this;
    }

    rational operator/(const rational& other) const {
        rational tmp = *this;
        tmp /= other;
        return tmp;
    }
};


// operator<<
template<typename I>
std::ostream& 
operator<<(std::ostream& os, const rational<I>& r) {
    if (r.den() == 0) {
        if (r.num() == 0) {
            os << "NaN";
        } else {
            if (r.num() > 0) {
                os << "+Inf";
            } else {
                os << "-Inf";
            }
        }
    } else {
        os << r.num() << "/" << r.den();
    }
    return os;
}
