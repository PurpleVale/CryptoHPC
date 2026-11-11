#ifndef CRYPTOHPC_KEYMANAGERS_H
#define CRYPTOHPC_KEYMANAGERS_H

template <int b> class KeyManager {
public:
    KeyManager() = delete;
    virtual ~KeyManager() = 0;
    virtual void generate_key() = 0;
};

template <int b> class SymmetricKeyManager : public KeyManager<b> {
};

template <int b> class AsymmetricKeyManager : public KeyManager<b> {
};

#endif //CRYPTOHPC_KEYMANAGERS_H