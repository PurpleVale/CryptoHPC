#include <iostream>
#include <cryptohpc/keymanagers.hpp>

int main() {
    KeyManager<Symmetric,12>::generate_key();
    std::cout << "Hello, World!" << std::endl;
    // tring things
    return 0;
}