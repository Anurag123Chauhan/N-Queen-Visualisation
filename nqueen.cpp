#include <bits/stdc++.h>
#include <windows.h>
using namespace std;

void printboard(vector<string> &board){
    system("cls"); // Clear the console
    for(int i = 0; i < board.size(); i++){
        for(int j = 0; j < board[i].size(); j++){
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    Sleep(500); // Wait for 500 milliseconds to visualize the backtracking
}

void backtrack(int r, int n, unordered_set<int>& col, unordered_set<int>& posdiag, unordered_set<int>& negdiag, vector<string>& board, vector<vector<string>>& res) {
    if (r == n) {
        res.push_back(board);
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (col.count(c) || posdiag.count(r + c) || negdiag.count(r - c)) {
            continue;
        }

        col.insert(c);
        posdiag.insert(r + c);
        negdiag.insert(r - c);
        board[r][c] = 'Q';
        printboard(board); // Print the current board state
        backtrack(r + 1, n, col, posdiag, negdiag, board, res);
        col.erase(c);
        posdiag.erase(r + c);
        negdiag.erase(r - c);
        board[r][c] = '.';
        printboard(board); // Print the board state after backtracking
    }
}

vector<vector<string>> solveNQueens(int n) {
    unordered_set<int> col;
    unordered_set<int> posdiag; // (r + c)
    unordered_set<int> negdiag; // (r - c)

    vector<vector<string>> res;
    vector<string> board(n, string(n, '.'));
    printboard(board); // Print the initial empty board
    backtrack(0, n, col, posdiag, negdiag, board, res);
    return res;
}

int main() {
    int n;
    cout << "Enter the number of queens: ";
    cin >> n;

    vector<vector<string>> ans = solveNQueens(n);
    for(int i = 0; i < ans.size(); i++){
        for(int j = 0; j < ans[i].size(); j++){
            cout << ans[i][j] << "\n";
        }
        cout << "\n";
    }
    return 0;
}