#include <iostream>
#include <set>
#include <boost/filesystem/path.hpp>

#include "boost/boost.h"


int main(int argc, char **argv) {

    //! Setting key pool
    std::set<int64_t> setKeyPool;

    // Top up key pool
    auto nTargetSize = 9;


    while (setKeyPool.size() < (nTargetSize + 1)) {
        int64_t nEnd = 1;
        if (!setKeyPool.empty())
            nEnd = *(--setKeyPool.end()) + 1;
        setKeyPool.insert(nEnd);

        printf("keypool added key %d, size=%u\n", nEnd, setKeyPool.size());

        double dProgress = 100.f * nEnd / (nTargetSize + 1);

        printf("Loading wallet... (%3.2f %%)\n", dProgress);
    }

    //! Setup openssl PRNG
    int64_t nCounter = setupRand();

    memory_cleanse((void *) &nCounter, sizeof(nCounter));

    //! generate random private key
    unsigned char vch[32];
    GetRandBytes(vch, sizeof(vch));

    std::cout << vch << std::endl;

    printf("Path is: %s", (boost::filesystem::path("/Users/tonypizzicato") / "dev").c_str());

    return 0;
}