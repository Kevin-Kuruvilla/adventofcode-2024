#include <bits/stdc++.h>
using namespace std;

static const int grid_size = 130;

struct Dir {
    int dx, dy;
};

inline Dir getDir(char c) {
    switch (c) {
        case '^': return {-1, 0};
        case '>': return {0, 1};
        case 'v': return {1, 0};
        default: return {0, -1};
    }
}

inline char turnRight(char c) {
    switch (c) {
        case '^': return '>';
        case '>': return 'v';
        case 'v': return '<';
        default: return '^';
    }
}

inline bool inside(int x, int y) {
    return x >= 0 && y >= 0 && x < grid_size && y < grid_size;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    static char grid[grid_size][grid_size];
    pair<int, int> current;
    int answer = 0;

    for (int i = 0; i < grid_size; i++) {
        for (int j = 0; j < grid_size; j++) {
            char c; cin >> c;
            grid[i][j] = c;
            if (c == '^') {
                current = {i, j};
            }
        }
    }

    while (true) {
        int x = current.first;
        int y = current.second;
        if (!inside(x, y)) break;
        char arrow = grid[x][y];
        Dir d = getDir(arrow);

        int nx = x + d.dx;
        int ny = y + d.dy;

        while (inside(nx, ny) && grid[nx][ny] == '#') {
            arrow = turnRight(arrow);
            d = getDir(arrow);
            nx = x + d.dx;
            ny = y + d.dy;
        }

        grid[x][y] = 'X';
        current = {nx, ny};

        if (grid[nx][ny] != 'X') answer++;
        grid[nx][ny] = arrow;
    }

    cout << answer;
}