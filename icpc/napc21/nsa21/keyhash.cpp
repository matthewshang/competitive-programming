#include <bits/stdc++.h>
using namespace std;

constexpr size_t KeySize = 16;
using Key = array<uint8_t, KeySize>;

uint8_t base16_to_base10(char d) {
    if ('0' <= d && d <= '9') {
        return d - '0';
    } else {
        return 10 + (d - 'a');
    }
}

char base10_to_base16(uint8_t v) {
    if (0 <= v && v <= 9) {
        return '0' + v;
    } else {
        return 'a' + (v - 10);
    }
}

uint32_t get_four(const Key& K, const size_t i) {
    uint32_t res = 0;
    for (size_t j = 4 * i; j < 4 * (i + 1); j++) {
        res = (res << 8) | K[j];
    }
    return res;
}

uint32_t rotr32(uint32_t v, size_t shift) {
    uint32_t lo = v & ((1 << shift) - 1);
    lo = lo << (32 - shift);
    return (v >> shift) | lo;
}

uint32_t rotl32(uint32_t v, size_t shift) {
    return rotr32(v, 32 - shift);
}

string key_hash(const Key& K) {
    uint32_t v1 = get_four(K, 0);
    uint32_t v2 = get_four(K, 1);
    uint32_t v3 = get_four(K, 2);
    uint32_t v4 = get_four(K, 3);
    uint32_t a = rotr32(v4, 14),
             b = rotl32(~v2, 12),
             c = rotl32(v2, 3),
             d = rotr32(v3, 6),
             e = rotl32(v1, 12) & rotr32(v2, 3),
             f = rotr32(c ^ d, 20),
             g = rotl32(d, 6),
             O = v1 & f,
             i = (v1 & ~v2) ^ v3,
             j = rotr32(O, 13),
             u = ~(g ^ ~e),
             l = rotl32(d, 18) ^ rotr32(j, 12),
             p = ~(rotl32(l, 30)) & b,
             T = b & rotr32(l, 2),
             U = v1 & ~(rotr32(rotl32(c, 13) ^ rotr32(d, 19), 1)),
             t = a ^ ~i;
    return to_string(O) + ":" + to_string(U) + ":" + to_string(T) + ":"
         + to_string(p) + ":" + to_string(u) + ":" + to_string(t);
}

int main() {
    string object;
    while (getline(cin, object) && object.length() != 0) {
        Key K{};
        for (size_t i = 0; i < KeySize; i++) {
            uint8_t hi = base16_to_base10(object[i * 2]);
            uint8_t lo = base16_to_base10(object[i * 2 + 1]);
            K[i] = (hi << 4) | lo;
        }
        cout << key_hash(K) << '\n';
    }

    return 0;
}