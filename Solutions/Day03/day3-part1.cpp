#include <bits/stdc++.h>
using namespace std;

regex pattern(R"(mul\(([1-9][0-9]{0,2}|0),([1-9][0-9]{0,2}|0)\))");

int mul(const string& str) {
    if (regex_match(str, pattern)) {
        smatch matches;
        regex_match(str, matches, pattern);
        return stoi(matches[1].str()) * stoi(matches[2].str());
    }

    return 0;
}

int main() {
    string input;
    char c;
    while (scanf("%c", &c) != EOF) {
        input += c;
    }

    int total = 0;

    for (int length = 8; length <= 12; length++) {
        for (int i = 0; i + length <= input.size(); i++) {
            string consider = input.substr(i, length);
            total += mul(consider);
        }
    }

    cout << total;
}