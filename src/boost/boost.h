// Created by tonypizzicato on 11/08/2017.

#ifndef SANDBOX_BOOST_H
#define SANDBOX_BOOST_H

#include <string>

int64_t setupRand();
void memory_cleanse(void *ptr, size_t len);
static inline int64_t GetPerformanceCounter();
void GetRandBytes(unsigned char* buf, int num);
std::string getPath();

#endif //SANDBOX_BOOST_H
