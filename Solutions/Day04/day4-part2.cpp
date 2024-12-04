#include <bits/stdc++.h>
using namespace std;

vector<string> input;
int n, m;

int countMAS(int i, int j) {
    int count = 0;
    if (i-1 >= 0 && j-1 >= 0 && i+1 < n && j+1 < m) {
        if (input[i+1][j+1] == 'M' && input[i-1][j-1] == 'S' && input[i-1][j+1] == 'M' && input[i+1][j-1] == 'S') count++;
        if (input[i+1][j+1] == 'M' && input[i-1][j-1] == 'S' && input[i+1][j-1] == 'M' && input[i-1][j+1] == 'S') count++;
        if (input[i+1][j+1] == 'S' && input[i-1][j-1] == 'M' && input[i-1][j+1] == 'M' && input[i+1][j-1] == 'S') count++;
        if (input[i+1][j+1] == 'S' && input[i-1][j-1] == 'M' && input[i+1][j-1] == 'M' && input[i-1][j+1] == 'S') count++;
    }
    return count;
}

int main() {

    string line;
    while (cin >> line) {
        input.push_back(line);
    }

    n = (int) input.size();
    m = (int) input[0].size();

    int total = 0;

    for (int i=1; i<n-1; i++) {
        for (int j=1; j<m-1; j++) {
            if (input[i][j] == 'A') {
                total += countMAS(i, j);
            }
        }
    }

    cout << total;
}