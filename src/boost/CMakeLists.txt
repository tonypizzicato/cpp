file(GLOB src *.c*)
add_library(boost STATIC ${src})

set_target_properties(boost PROPERTIES LINKER_LANGUAGE CXX)

include_directories(${Boost_INCLUDE_DIRS} ${OPENSSL_INCLUDE_DIR})

target_link_libraries(
        boost
        ${Boost_LIBRARIES}
        ${OPENSSL_LIBRARIES}
        event-2.0.5
)

install(TARGETS boost DESTINATION lib)
