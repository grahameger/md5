//
//  md5.hpp
//  md5
//
//  Created by Graham Eger on 4/29/18.
//  Copyright © 2018 Graham Eger. All rights reserved.
//

#ifndef md5_grahameger
#define md5_grahameger

#include <array>
#include <cmath>

static const uint8_t INPUT_BUFFER_SIZE = 64;
static const uint8_t BITS_BUFFER_SIZE  = 4;
static const uint8_t BUFFER_SIZE = 4;
static const uint8_t DIGEST_SIZE = 16;

class md5_init {
public:
    md5_init() {
        for (size_t i = 0; i < INPUT_BUFFER_SIZE; i++) {
            K[i] = floor(pow(2, 32) * abs(sin(i + 1)));
        }
    }
    uint32_t K[INPUT_BUFFER_SIZE];
};

class md5 {
public:
    md5() {
        a0 = 0x67452301;
        b0 = 0xefcdab89;
        c0 = 0x98badcfe;
        d0 = 0x10325476;
    }
    void update(unsigned char const * buffer_in, size_t length_in);
    void finalize(unsigned char digest[DIGEST_SIZE]);
private:
    // Data structures
    uint32_t buf[4];
    uint32_t bits[4];
    unsigned char input[64];
    uint32_t a0, b0, c0, d0;
    
    static md5_init constant;
    
};

#endif
