#include <bits/stdc++.h>
using namespace std;

int main() {
    int left, right;
    vector<pair<int, int>> pairs;

    while (cin >> left >> right) {
        pairs.emplace_back(left, right);
    }

    map<int, int> freq;
    for (pair<int, int> pair : pairs) {
        freq[pair.second]++;
    }

    int total = 0;
    for (pair<int, int> pair : pairs) {
        total += pair.first * freq[pair.first];
    }

    cout << total;
}