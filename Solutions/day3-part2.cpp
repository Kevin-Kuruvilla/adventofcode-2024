#include <bits/stdc++.h>
using namespace std;

regex mul_pattern(R"(mul\(([1-9][0-9]{0,2}|0),([1-9][0-9]{0,2}|0)\))");
regex do_pattern(R"(do\(\))");
regex dont_pattern(R"(don't\(\))");

bool isMul(const string& str) {
    return regex_match(str, mul_pattern);
}

bool isDo(const string& str) {
    return regex_match(str, do_pattern);
}

bool isDont(const string& str) {
    return regex_match(str, dont_pattern);
}
int mul(const string& str) {
    smatch matches;
    regex_match(str, matches, mul_pattern);
    return stoi(matches[1].str()) * stoi(matches[2].str());
}

int main() {
    ifstream inFile("in");
    string input((istreambuf_iterator<char>(inFile)), istreambuf_iterator<char>());

    int total = 0;
    bool canMul = true;

    for (int i = 0; i <= input.length() - 4; i++) {
        for (int length : {4, 7, 8, 9, 10, 11, 12}) {
            if (i + length > input.length()) break;

            string consider = input.substr(i, length);

            if (length == 4 && isDo(consider)) {
                canMul = true;
            } else if (length == 7 && isDont(consider)) {
                canMul = false;
            } else if (length >= 8 && canMul && isMul(consider)) {
                total += mul(consider);
            }
        }
    }

    cout << total;
}