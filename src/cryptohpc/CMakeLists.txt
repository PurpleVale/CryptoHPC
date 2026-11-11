add_library(keymanager STATIC keymanagers.hpp)
set_target_properties(keymanager PROPERTIES LINKER_LANGUAGE CXX)

add_library(cipher STATIC ciphers.hpp)
set_target_properties(cipher PROPERTIES LINKER_LANGUAGE CXX)