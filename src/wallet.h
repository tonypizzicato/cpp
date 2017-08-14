// Created by tonypizzicato on 09/08/2017.

#pragma once

#include <cstdint>

class Wallet {
public:
    Wallet();
private:
    unsigned char address[60];
    uint64_t amount;
};