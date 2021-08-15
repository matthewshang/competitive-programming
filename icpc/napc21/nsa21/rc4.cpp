#include <bits/stdc++.h>
using namespace std;

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

vector<uint8_t> uint64_to_key(uint64_t v) {
    vector<uint8_t> key;
    for (int i = 0; i < 8; i++) {
        key.push_back(v & 0xFF);
        v >>= 8;
    }
    reverse(key.begin(), key.end());
    return key;
}

vector<uint8_t> xor_key(const vector<uint8_t>& k, const uint8_t x) {
    auto res = k;
    for (uint8_t& e : res) {
        e ^= x;
    }
    return res;
}

struct RC4 {
    constexpr static int Size = 256;

    array<uint8_t, Size> S;
    int var;
    int i, j;

    RC4() = default;

    RC4(const vector<uint8_t>& K, const int offset, const int var_) {
        var = var_;
        iota(S.begin(), S.end(), 0);
        j = 0;
        for (i = 0; i < Size; i++) {
            if (var == 2) {
                j = (j + S[i] + K[j % K.size()]) % Size;
            } else if (var == 3) {
                j = (j + S[j] + K[i % K.size()]) % Size;
            } else {
                j = (j + S[i] + K[i % K.size()]) % Size;
            }
            swap(S[i], S[j]);
        }
        i = j = 0;

        for (int k = 0; k < offset; k++) {
            gen();
        }
    }

    uint8_t gen() {
        i = (i + 1) % Size;
        j = (j + S[i]) % Size;
        swap(S[i], S[j]);
        if (var == 1) {
            return S[S[(S[i] + S[j]) % Size]];
        } else {
            return S[(S[i] + S[j]) % Size];
        }
    }
};

struct Stream {
    RC4 R1, R2, R3, R4;
    Stream(const vector<uint8_t>& k, const int v1, const int v2, const int v3, const int v4) {
        R1 = RC4(k, 256, v1);
        R2 = RC4(xor_key(k, 0x55), 1437, v2);
        R3 = RC4(xor_key(k, 0xaa), 512, v3);
        R4 = RC4(xor_key(k, 0x01), 1352, v4);
    }

    uint8_t gen() {
        return R1.gen() ^ R2.gen() ^ R3.gen() ^ R4.gen();
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // string key_str;
    // cin >> key_str;
    // vector<uint8_t> key(key_str.size() / 2);
    // for (int i = 0; i < int(key.size()); i++) {
    //     uint8_t hi = base16_to_base10(key_str[i * 2]);
    //     uint8_t lo = base16_to_base10(key_str[i * 2 + 1]);
    //     key[i] = (hi << 4) | lo;
    // }
    // int offset;
    // cin >> offset;
    // RC4 R(key, offset, 0);
    // for (int i = 0; i < 10; i++) {
    //     uint8_t v = R.gen();
    //     cout << base10_to_base16(v >> 4);
    //     cout << base10_to_base16(v & 0xF);
    // }
    // cout << endl;

    string key_str;
    cin >> key_str;
    vector<uint8_t> key(key_str.size() / 2);
    for (int i = 0; i < int(key.size()); i++) {
        uint8_t hi = base16_to_base10(key_str[i * 2]);
        uint8_t lo = base16_to_base10(key_str[i * 2 + 1]);
        key[i] = (hi << 4) | lo;
    }

    // const string want = "ead8d509bb";
    // for (int v1 = 0; v1 < 4; v1++) {
    //     for (int v2 = 0; v2 < 4; v2++) {
    //         for (int v3 = 0; v3 < 4; v3++) {
    //             for (int v4 = 0; v4 < 4; v4++) {
    //                 Stream stream(key, v1, v2, v3, v4);
    //                 string res;
    //                 for (int i = 0; i < 5; i++) {
    //                     uint8_t v = stream.gen();
    //                     res += base10_to_base16(v >> 4);
    //                     res += base10_to_base16(v & 0xF);
    //                 }
    //                 // cout << res << endl;

    //                 if (res == want) {
    //                     cout << v1 << ", " << v2 << ", " << v3 << ", " << v4 << endl;
    //                 }
    //             }
    //         }
    //     }
    // }
    Stream stream(key, 2, 3, 0, 1);
    string res;
    for (int i = 0; i < 128; i++) {
        uint8_t v = stream.gen();
        res += base10_to_base16(v >> 4);
        res += base10_to_base16(v & 0xF);
    }
    cout << res << endl;

    return 0;
}