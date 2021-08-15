#include <bits/stdc++.h>
using namespace std;

struct Buffer {
    vector<uint8_t> bytes;
    size_t pos = 0;

    bool end() const {
        return pos >= bytes.size();
    }

    uint8_t next() {
        return bytes[pos++];
    }
};

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

size_t parse_length(Buffer& B) {
    size_t length = 0;
    while (true) {
        uint8_t cur = B.next();
        length = (length << 7) | (cur & 0x7F);
        if (!(cur & 0x80)) {
            break;
        }
    }
    return length;
}

void parse_header(Buffer& B) {
    constexpr int HeaderSize = 12;
    for (int i = 0; i < HeaderSize; i++) {
        B.next();
    }
}

uint8_t parse_tag(Buffer& B) {
    return B.next();
}

void parse(Buffer& B, const string& tag_name, const bool is_ascii) {
    const size_t length = parse_length(B);
    cout << tag_name << ":";
    for (size_t i = 0; i < length; i++) {
        uint8_t byte = B.next();
        if (is_ascii) {
            cout << static_cast<char>(byte);
        } else {
            cout << base10_to_base16(byte >> 4);
            cout << base10_to_base16(byte & 0xF);
        }
    }
    cout << '\n';
}

int main() {
    string data;
    cin >> data;
    assert(data.size() % 2 == 0);

    Buffer B;
    for (size_t i = 0; i < data.size(); i += 2) {
        uint8_t a = base16_to_base10(data[i]);
        uint8_t b = base16_to_base10(data[i + 1]);
        uint8_t c = (a << 4) | b;
        B.bytes.push_back(c);
    }

    parse_header(B);
    while (!B.end()) {
        uint8_t tag = parse_tag(B);
        string tag_name;
        bool is_ascii;
        switch (tag) {
            case 0x01:
                tag_name = "VICTIM_ID";
                is_ascii = true;
                break;
            case 0x02:
                tag_name = "VERSION";
                is_ascii = true;
                break;
            case 0x06:
                tag_name = "FILENAME";
                is_ascii = true;
                break;
            case 0x08:
                tag_name = "IV";
                is_ascii = false;
                break;
            case 0x09:
                tag_name = "NONCE";
                is_ascii = false;
                break;
            case 0x13:
                tag_name = "KEY_HASH";
                is_ascii = true;
                break;
            case 0x27:
                tag_name = "ENC_DATA";
                is_ascii = false;
                break;
            default:
                tag_name = "UNKNOWN";
                is_ascii = false;
        }
        parse(B, tag_name, is_ascii);
    }

    return 0;
}