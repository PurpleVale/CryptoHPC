#include <iostream>
#include <cryptohpc/keymanagers.hpp>

#include <cryptohpc/ciphers.hpp>

int main() {
  using namespace CryptoHPC;

  KeyManager<Symmetric,1024>::generate_key();
  KeyManager<Asymmetric,1024>::generate_key();

  Cipher<RSA,1024>::encrypt();
  Cipher<XOR,2048>::decrypt();

  std::cout << "Hello, World!" << std::endl;
  return 0;
}
