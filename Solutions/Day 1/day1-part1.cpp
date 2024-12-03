#include <bits/stdc++.h>
using namespace std;

int main() {
    int left, right;
    vector<int> left_list, right_list;

    while (cin >> left >> right) {
        left_list.push_back(left);
        right_list.push_back(right);
    }

    sort(left_list.begin(), left_list.end());
    sort(right_list.begin(), right_list.end());

    int total = 0;
    for (int i=0; i<left_list.size(); i++) {
        total += abs(left_list[i]-right_list[i]);
    }

    cout << total;
}