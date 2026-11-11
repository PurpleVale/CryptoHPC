#ifndef CRYPTOHPC_KEYMANAGERS_H
#define CRYPTOHPC_KEYMANAGERS_H

#include <type_traits>
#include <cryptohpc/cryptohpc.hpp>

namespace CryptoHPC {

  template <KeyType Type,int bits> class KeyManager {
  };

  template <int bits> class KeyManager<Symmetric,bits> {
    assert_allowed_size(bits)
  public:
    static void generate_key() {

    }

    static void load_key() {

    }

    static void save_key() {

    }
  };

  template <int bits> class KeyManager<Asymmetric,bits> {
    assert_allowed_size(bits)
  public:
    static void generate_key() {
      std::cout << "generate_key() (asym)" << std::endl;
    }

    static void load_key() {

    }

    static void save_key() {

    }
  };
}

#endif //CRYPTOHPC_KEYMANAGERS_H