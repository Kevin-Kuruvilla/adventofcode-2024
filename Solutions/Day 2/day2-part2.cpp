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
        if ((diff < 1) || (diff > 3)) {
            return 0;
        }
    }

    return isIncreasing || isDecreasing;
}

int consider(vector<int> report, int index) {
    vector<int> copy = report;
    copy.erase(copy.begin() + index);
    return isSafe(copy);
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

        if (isSafe(report)) {
            total++;
            continue;
        }

        int n = report.size();
        int isSafe = false;
        for (int i=1; i<n; i++) {
            int diff = report[i] - report[i-1];
            if ((abs(diff) < 1) || (abs(diff) > 3)) {
                isSafe |= consider(report, i-1);
                isSafe |= consider(report, i);
                break;
            }

            if (i+1 < n) {
                int diff2 = report[i+1] - report[i];

                if ((diff > 0) != (diff2 > 0)) {
                    isSafe |= consider(report, i-1);
                    isSafe |= consider(report, i);
                    isSafe |= consider(report, i+1);
                    break;
                }
            }
        }

        total += isSafe;
    }

    cout << total;
}