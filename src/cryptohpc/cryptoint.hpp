#ifndef CRYPTOHPC_CRYPTOBIT_H
#define CRYPTOHPC_CRYPTOBIT_H

#include <cstdint>
#include <cryptohpc/cryptohpc.hpp>

namespace CryptoHPC {
  template<int bits> class CryptoInt {
    assert_allowed_size(bits)

    public:

    CryptoInt() = default;
    ~CryptoInt() = default;

    // TODO: remember how pointer stuff is done

    uint8_t top;
    bool negative;
    bool flag;

    // TODO: check <=> operator
    bool operator==(const CryptoInt &) const;
    bool operator!=(const CryptoInt &) const;

    // TODO: fix bits
    CryptoInt<bits*2> operator+(const CryptoInt &) const;
    CryptoInt<> operator+(const CryptoInt &) const;
    CryptoInt operator-(const CryptoInt &) const;
    CryptoInt operator*(const CryptoInt &) const;
    CryptoInt operator/(const CryptoInt &) const;
    CryptoInt operator%(const CryptoInt &) const;

    // TODO: maybe these?
    CryptoInt operator+=(const CryptoInt &) const;
    CryptoInt operator-=(const CryptoInt &) const;
    CryptoInt operator*=(const CryptoInt &) const;
    CryptoInt operator/=(const CryptoInt &) const;
    CryptoInt operator%=(const CryptoInt &) const;

    private:
    CryptoInt<bits*2> square() const;
    CryptoInt<bits/2> low() const;
    CryptoInt<bits/2> high() const;

    void sub_one_if_odd();

    bool is_prime() const;
    bool is_odd() const;
    bool is_zero() const;
    bool is_negative() const;
    bool is_one() const;

    void makeodd();
  };
}

#endif //CRYPTOHPC_CRYPTOBIT_H