//
// Created by vale on 11/11/26.
//

#ifndef CRYPTOHPC_CRYPTOHPC_HPP
#define CRYPTOHPC_CRYPTOHPC_HPP

#define assert_allowed_size(bits) static_assert( \
bits ==   32 || bits ==   64 || bits ==  128 || bits ==  256 || \
bits ==  512 || bits == 1024 || bits == 2048 || bits == 4096, \
"bits must be a power of two between 64 and 4096" \
);

namespace CryptoHPC {

  enum CipherType {
    RSA,
    XOR,
  };

  enum KeyType {
    Symmetric,
    Asymmetric,
  };

}
#endif //CRYPTOHPC_CRYPTOHPC_HPP