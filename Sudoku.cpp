#include <bits/stdc++.h>
using namespace std;

vector<pair<int, int>> faka;
vector<vector<int>> grid;

bool is_valid(int x, int y, int val) {
    for (int i = 0; i < 9; i++)
        if(grid[i][y] == val or grid[x][i] == val) return false;

    for (int i = x/3; i < x/3 + 3; i++) {
        for (int j = y/3; j < y/3 + 3; j++)
            if(grid[i][j] == val) return false;
    }

    return true;
}

bool sudoku(int id) {
    if(id >= grid.size()) return true;

    auto[i1, j1] = faka[id];

    for (int i = 1; i <= 9; ++i) {
        if(is_valid( i1, j1, i)) {
            grid[i1][j1] = i;
            if(sudoku(id+1)) return true;
        }
    }
    return false;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

                grid = {{ 0, 0, 8, 0, 5, 0, 0, 0, 0},
                       { 1, 0, 0, 9, 2, 0, 0, 0, 6},
                       { 0, 6, 0, 0, 0, 0, 0, 7, 0},
                       { 0, 0, 4, 0, 0, 0, 8, 0, 0},
                       { 0, 0, 0, 0, 0, 3, 0, 0, 0},
                       { 2, 0, 0, 1, 6, 0, 0, 0, 7},
                       { 0, 0, 2, 3, 9, 0, 0, 4, 0},
                       { 0, 0, 0, 0, 0, 5, 0, 0, 9},
                       { 3, 0, 0, 0, 0, 7, 0, 0, 0}};


    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            if(grid[i][j] == 0) faka.push_back({i, j});


    sort(faka.begin(), faka.end());

    if(sudoku(0)) {
        cout << "Sudoku solved" << endl;
        for (auto v : grid) {
            for (auto i : v) cout << i << ' ';
                cout << endl;
        }
    }

    return 0;
}