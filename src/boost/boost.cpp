// Created by tonypizzicato on 11/08/2017.

#include <stdio.h>

#include "boost.h"


#include <boost/filesystem/path.hpp>
#include <event2/http.h>
#include <openssl/crypto.h>
#include <openssl/rand.h>


#include <secp256k1/include/secp256k1.h>

static secp256k1_context* secp256k1_context_sign = NULL;

void memory_cleanse(void *ptr, size_t len) {
    OPENSSL_cleanse(ptr, len);
}

static inline int64_t GetPerformanceCounter() {
    int64_t nCounter = 0;

    timeval t;
    gettimeofday(&t, NULL);
    nCounter = (int64_t) (t.tv_sec * 1000000 + t.tv_usec);


    return nCounter;
}

int64_t setupRand() {
    //! Setup openssl PRNG
    int64_t nCounter = GetPerformanceCounter();
    RAND_add(&nCounter, sizeof(nCounter), 1.5);
    printf("nCounter: %d, %d\n", nCounter, sizeof(nCounter));

    return nCounter;
}

void GetRandBytes(unsigned char* buf, int num)
{
    if (RAND_bytes(buf, num) != 1) {
        assert(false);
    }
}

bool Check(const unsigned char *vch) {
    return secp256k1_ec_seckey_verify(secp256k1_context_sign, vch);
}

std::string getPath() {

    struct evhttp* eventHTTP = evhttp_new(nullptr); // XXX RAII

    return (boost::filesystem::path("/Users/tonypizzicato") / "dev").native();
}