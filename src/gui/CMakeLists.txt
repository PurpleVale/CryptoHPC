link_directories(
        ${GTKMM_LIBRARY_DIRS}  )

include_directories(
        ${GTKMM_INCLUDE_DIRS}  )

add_executable(gui_test
        gui.cpp
        ../cryptohpc/cryptoint.hpp
        ../cryptohpc/keymanagers.hpp
        ../cryptohpc/ciphers.hpp
)

target_link_libraries(gui_test
        ${GTKMM_LIBRARIES}  )