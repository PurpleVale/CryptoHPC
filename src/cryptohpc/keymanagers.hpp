#ifndef CRYPTOHPC_KEYMANAGERS_H
#define CRYPTOHPC_KEYMANAGERS_H

#include <type_traits>

class KeyType {
  public:
  KeyType() = delete;
  virtual ~KeyType() = 0;

};

class Symmetric : public KeyType {
  public:
  Symmetric() = delete;
  ~Symmetric() override = 0;
};

class Asymmetric : public KeyType {
  public:
  Asymmetric() = delete;
  ~Asymmetric() override = 0;
};

template <typename Type,int bits> class KeyManager {
  static_assert(std::is_base_of<KeyType,Type>::value, "Type must be a KeyType");
  static_assert(
    bits ==   64 ||
    bits ==  128 ||
    bits ==  256 ||
    bits ==  512 ||
    bits == 1024 ||
    bits == 2048 ||
    bits == 4096,
    "bits must be a power of two between 64 and 4096");
};

template <int bits> class KeyManager<Symmetric,bits> {
  public:
  static void generate_key() {

  }

  static void load_key() {

  }

  static void save_key() {

  }
};

template <int bits> class KeyManager<Asymmetric,bits> {
  public:
  static void generate_key() {
    std::cout << "generate_key() (asym)" << std::endl;
  }

  static void load_key() {

  }

  static void save_key() {

  }
};

#endif //CRYPTOHPC_KEYMANAGERS_H