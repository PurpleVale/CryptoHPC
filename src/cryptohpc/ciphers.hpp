#ifndef CRYPTOHPC_CIPHERS_H
#define CRYPTOHPC_CIPHERS_H


template<int b> class Cipher {
};

template<int b> class XOR : public Cipher<b> {
};

template<int b> class RSA : public Cipher<b> {
};

#endif //CRYPTOHPC_CIPHERS_H