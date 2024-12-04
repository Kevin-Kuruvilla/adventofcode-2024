#include <bits/stdc++.h>
using namespace std;

regex mul_pattern(R"(mul\(([1-9][0-9]{0,2}|0),([1-9][0-9]{0,2}|0)\))");

bool isMul(const string& str) {
    return regex_match(str, mul_pattern);
}

int mul(const string& str) {
    smatch matches;
    regex_match(str, matches, mul_pattern);
    return stoi(matches[1].str()) * stoi(matches[2].str());
}

int main() {
    string input;
    char c;
    while (scanf("%c", &c) != EOF) {
        input += c;
    }

    int total = 0;
    bool canMul = true;

    for (int i = 0; i <= input.size() - 4; i++) {
        for (int length : {4, 7, 8, 9, 10, 11, 12}) {
            if (i + length > input.size()) break;

            string consider = input.substr(i, length);

            if (length == 4 && consider == "do()") {
                canMul = true;
            } else if (length == 7 && consider == "don\'t()") {
                canMul = false;
            } else if (length >= 8 && canMul && isMul(consider)) {
                total += mul(consider);
            }
        }
    }

    cout << total;
}