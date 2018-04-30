//
//  md5.hpp
//  md5
//
//  Created by Graham Eger on 4/29/18.
//  Copyright © 2018 Graham Eger. All rights reserved.
//  Based off of RFC 1321
//

/*
RFC 1321              MD5 Message-Digest Algorithm            April 1992


3. MD5 Algorithm Description

We begin by supposing that we have a b-bit message as input, and that
we wish to find its message digest. Here b is an arbitrary
nonnegative integer; b may be zero, it need not be a multiple of
eight, and it may be arbitrarily large. We imagine the bits of the
message written down as follows:

m_0 m_1 ... m_{b-1}

The following five steps are performed to compute the message digest
of the message.

3.1 Step 1. Append Padding Bits

The message is "padded" (extended) so that its length (in bits) is
congruent to 448, modulo 512. That is, the message is extended so
that it is just 64 bits shy of being a multiple of 512 bits long.
Padding is always performed, even if the length of the message is
already congruent to 448, modulo 512.

Padding is performed as follows: a single "1" bit is appended to the
message, and then "0" bits are appended so that the length in bits of
the padded message becomes congruent to 448, modulo 512. In all, at
least one bit and at most 512 bits are appended.

3.2 Step 2. Append Length

A 64-bit representation of b (the length of the message before the
                              padding bits were added) is appended to the result of the previous
step. In the unlikely event that b is greater than 2^64, then only
the low-order 64 bits of b are used. (These bits are appended as two
                                      32-bit words and appended low-order word first in accordance with the
                                      previous conventions.)

At this point the resulting message (after padding with bits and with
                                     b) has a length that is an exact multiple of 512 bits. Equivalently,
this message has a length that is an exact multiple of 16 (32-bit)
words. Let M[0 ... N-1] denote the words of the resulting message,
where N is a multiple of 16.

3.3 Step 3. Initialize MD Buffer

A four-word buffer (A,B,C,D) is used to compute the message digest.
Here each of A, B, C, D is a 32-bit register. These registers are
initialized to the following values in hexadecimal, low-order bytes
first):
*/


#ifndef md5_grahameger
#define md5_grahameger

#include <array>
#include <cmath>
#include <cstdlib>
#include <cstring>

static const uint8_t INPUT_BUFFER_SIZE = 64;
static const uint8_t BITS_BUFFER_SIZE  = 4;
static const uint8_t BUFFER_SIZE = 4;
static const uint8_t DIGEST_SIZE = 16;
static const uint16_t PAD_MODULO = 448;

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
    void update(unsigned char const * buffer_in, size_t length_in) {
        // compute the size of the new buffer based on length in and declare a buffer
        size_t padded_len = length_in + PAD_MODULO - (length_in % PAD_MODULO);
        const unsigned char * new_buf = new unsigned char[padded_len];
        // copy the buffer in
        memcpy((void*)new_buf, (void*)buffer_in, length_in);
        // do the padding
        
    }
    void finalize(unsigned char digest[DIGEST_SIZE]);
private:
    // Data structures
    uint32_t buf[4];
    uint32_t bits[4];
    unsigned char input[64];
    uint32_t a0, b0, c0, d0;
    static md5_init constant;
    
    // helpers
    size_t round_up(size_t to_round, size_t multiple = 448) {
        return to_round + multiple - (to_round % multiple);
    }
    void pad(unsigned char * to_pad, size_t pad_len) {
        to_pad[0] = 1;
    }
    
};

#endif
