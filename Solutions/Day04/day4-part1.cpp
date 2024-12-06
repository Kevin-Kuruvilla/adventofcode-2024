#include <bits/stdc++.h>
using namespace std;

vector<string> input;
int n, m;

int countXMAS(int i, int j) {
    int count = 0;
    if (j+3 < m && input[i][j+1] == 'M' && input[i][j+2] == 'A' && input[i][j+3] == 'S') count++;
    if (j-3 >= 0 && input[i][j-1] == 'M' && input[i][j-2] == 'A' && input[i][j-3] == 'S') count++;
    if (i+3 < n && input[i+1][j] == 'M' && input[i+2][j] == 'A' && input[i+3][j] == 'S') count++;
    if (i-3 >= 0 && input[i-1][j] == 'M' && input[i-2][j] == 'A' && input[i-3][j] == 'S') count++;
    if (j+3 < m && i+3 < n && input[i+1][j+1] == 'M' && input[i+2][j+2] == 'A' && input[i+3][j+3] == 'S') count++;
    if (j+3 < m && i-3 >= 0 && input[i-1][j+1] == 'M' && input[i-2][j+2] == 'A' && input[i-3][j+3] == 'S') count++;
    if (j-3 >= 0 && i+3 < n && input[i+1][j-1] == 'M' && input[i+2][j-2] == 'A' && input[i+3][j-3] == 'S') count++;
    if (j-3 >= 0 && i-3 >= 0 && input[i-1][j-1] == 'M' && input[i-2][j-2] == 'A' && input[i-3][j-3] == 'S') count++;
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

    for (int i=0; i<n; i++) {
        for (int j=0; j<m; j++) {
            if (input[i][j] == 'X') {
                total += countXMAS(i, j);
            }
        }
    }

    cout << total;
}