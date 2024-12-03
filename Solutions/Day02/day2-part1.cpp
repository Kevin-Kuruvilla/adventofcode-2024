#include <bits/stdc++.h>
using namespace std;

int isSafe(vector<int> report) {
    int n = report.size();

    int isIncreasing = 1;
    int isDecreasing = 1;

    for (int i=1; i<n; i++) {
        if (report[i-1] < report[i]) {
            isDecreasing = 0;
        } else {
            isIncreasing = 0;
        }

        int diff = abs(report[i - 1] - report[i]);
        if (diff < 1 || diff > 3) {
            return 0;
        }
    }

    return isIncreasing || isDecreasing;
}

int main() {
    string line;

    int total = 0;
    while (getline(cin, line)) {
        if (line.empty()) break;

        istringstream stream(line);
        vector<int> report;
        int level;
        while (stream >> level) {
            report.push_back(level);
        }

        total += isSafe(report);
    }

    cout << total;
}