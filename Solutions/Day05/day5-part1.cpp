#include <bits/stdc++.h>
using namespace std;

unordered_map<int, unordered_set<int>> rules;

vector<int> getVec(string& pages) {
    vector<int> order;
    for (int i=0; i<pages.size(); i+=3) {
        int number = stoi(pages.substr(i, 2));
        order.push_back(number);
    }
    return order;
}

bool isValid(vector<int>& order) {
    for (int i=0; i<order.size(); i++) {
        unordered_set<int> i_rules = rules[order[i]];
        for (int j=i-1; j>=0; j--) {
            if (i_rules.count(order[j])) return false;
        }
    }
    return true;
}

int main() {
    string rule;
    while (cin >> rule && rule != "#") {
        int number = stoi(rule.substr(0, 2));
        int before = stoi(rule.substr(3, 2));
        rules[number].insert(before);
    }

    int total = 0;

    string pages;
    getline(cin, pages);
    while (getline(cin, pages)) {
        vector<int> order = getVec(pages);
        if (isValid(order)) total += order[order.size()/2];
    }

    cout << total;
}