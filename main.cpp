// C++ Code
#include <algorithm>
#include <bits/stdc++.h>
#include <map>
#include <vector>

using namespace std;

// Input matrix

void helper(int r,
            int c,
            vector<vector<char>> &sudoku,
            map<pair<int,int>,map<int,int>> &mp,
            vector<map<int,int>> &row,
            vector<map<int,int>> &col) {
    if (r == 9) {
        for (auto it : sudoku) {
            for (auto i : it) {
                cout << i << " ";
            }
            cout << "\n";
        }
        cout << "\n";
        return;
    }

    if (c == 9) {
        helper(r+1, 0, sudoku, mp, row, col);
        return;
    }

    if (sudoku[r][c] != '.') {
        helper (r, c+1, sudoku, mp, row, col);
        return;
    }

    for (int i = 1; i <= 9; i++) {
        int rw = r/3;
        int cl = c/3;
        if (!mp[{rw, cl}][i] and !row[r][i] and !col[c][i]) {
            mp[{rw, cl}][i] = 1;
            row[r][i] = 1;
            col[c][i] = 1;
            sudoku[r][c] = i+'0';
            helper(r, c+1, sudoku, mp, row, col);
            mp[{rw, cl}][i] = 0;
            row[r][i] = 0;
            col[c][i] = 0;
            sudoku[r][c] = '.';
        }
    }
}

void solve(vector<vector<char>> &sudoku) {
    map<pair<int,int>, map<int,int>> mp;
    vector<map<int,int>> row(9);
    vector<map<int,int>> col(9);
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (sudoku[i][j] != '.') {
                mp[{i/3, j/3}][sudoku[i][j]-'0'] = 1;
                row[i][sudoku[i][j]-'0'] = 1;
                col[j][sudoku[i][j]-'0'] = 1;
            }
        }
    }
    helper(0, 0, sudoku, mp, row, col);
}

int main() {
    vector<vector<char>>sudoku = {
            {'5','3','.','.','7','.','.','.','.'},
            {'6','.','.','1','9','5','.','.','.'},
            {'.','9','8','.','.','.','.','6','.'},
            {'8','.','.','.','6','.','.','.','3'},
            {'4','.','.','8','.','3','.','.','1'},
            {'7','.','.','.','2','.','.','.','6'},
            {'.','6','.','.','.','.','2','8','.'},
            {'.','.','.','4','1','9','.','.','5'},
            {'.','.','.','.','8','.','.','7','9'},
    };
    solve(sudoku);
}

