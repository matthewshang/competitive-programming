/*
ID: mshang41
LANG: C++11
TASK: namenum
*/

#include "bits/stdc++.h"

using namespace std;

vector<string> get_names() {
    ifstream dict("dict.txt");
    vector<string> names;
    string line;
    while (dict >> line) {
        names.push_back(line);
    }
    
    return names;
}

bool match(const string &serial, const string &name, vector<int> &keypad) {
    if (serial.length() != name.length()) return false;

    for (int i = 0; i < serial.length(); i++) {
        int convert = keypad[name[i] - 'A'] + 2;
        if (convert != serial[i] - '0') {
            return false;
        }
    }
    return true;
}

int main() {
    ifstream input("namenum.in");
    string line;
    input >> line;

    vector<string> dict = get_names();
    vector<string> possible;

    vector<int> keypad;
    int accum = 0;
    for (char c = 'A'; c <= 'Z'; c++) {
        if (c == 'Q' || c == 'Z') {
            keypad.push_back(-1);
        } else {
            keypad.push_back(accum / 3);
            accum++;
        }
    }

    // match("5747867437", "KRISTOPHER", keypad);

    for (string name : dict) {
        if (match(line, name, keypad)) {
            possible.push_back(name);
        }
    }

    ofstream output("namenum.out");
    for (string name : possible) {
        output << name << endl;
    }

    if (possible.size() == 0) {
        output << "NONE" << endl;
    }

    return 0;
}