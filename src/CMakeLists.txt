file(GLOB src *.cpp)

add_executable(sandbox ${src})

add_subdirectory(boost)
add_subdirectory(secp256k1)

# Search OpenSSL
set(OPENSSL_ROOT_DIR /usr/local/opt/openssl/)


#setup boost
set(Boost_USE_STATIC_LIBS on)
set(Boost_USE_MULTITHREADED ON)
unset(Boost_INCLUDE_DIR CACHE)
unset(Boost_LIBRARY_DIRS CACHE)

find_package(Boost COMPONENTS system filesystem thread REQUIRED)
find_package(OpenSSL REQUIRED)
find_package(Event REQUIRED)

link_directories(${Boost_LIBRARY_DIRS})

message("${Event_LIBRARIES}")

include_directories(
        ${Boost_INCLUDE_DIRS}
        ${OPENSSL_INCLUDE_DIR}
)

target_link_libraries(
        sandbox
        boost
        secp256k1
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        ${Event_LIBRARIES}
)

add_dependencies(
        sandbox
        boost
)

install(TARGETS sandbox DESTINATION bin)

