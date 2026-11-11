#ifndef CRYPTOHPC_CIPHERS_H
#define CRYPTOHPC_CIPHERS_H

#include <cryptohpc/cryptohpc.hpp>
#include <type_traits>

namespace CryptoHPC {

  template <CipherType Type,int bits> class Cipher {
  };

  template <int bits> class Cipher<XOR,bits> {
    assert_allowed_size(bits)
  public:
    static void encrypt() {}
    static void decrypt() {}
  };

  template <int bits> class Cipher<RSA,bits> {
    assert_allowed_size(bits)
   public:
    static void encrypt() {}
    static void decrypt() {}
  };

}


#endif //CRYPTOHPC_CIPHERS_H