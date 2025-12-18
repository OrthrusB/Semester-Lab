#include <iostream>
using namespace std;

#define N 4

// Function to print the solution
void printSolution(int board[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cout << (board[i][j] ? "Q " : ". ");
        }
        cout << endl;
    }
    cout << endl;
}

// Function to check if a queen can be placed on board[row][col]
bool isSafe(int board[N][N], int row, int col) {
    int i, j;

    // Check row on left side
    for (i = 0; i < col; i++)
        if (board[row][i])
            return false;

    // Check upper diagonal on left side
    for (i = row, j = col; i >= 0 && j >= 0; i--, j--)
        if (board[i][j])
            return false;

    // Check lower diagonal on left side
    for (i = row, j = col; j >= 0 && i < N; i++, j--)
        if (board[i][j])
            return false;

    return true;
}

// Recursive function to solve N-Queens problem
bool solveNQueensUtil(int board[N][N], int col) {
    // Base case: If all queens are placed, return true
    if (col >= N) {
        printSolution(board);
        return true;
    }

    bool res = false;
    // Consider this column and try placing this queen in all rows one by one
    for (int i = 0; i < N; i++) {
        if (isSafe(board, i, col)) {
            // Place this queen in board[i][col]
            board[i][col] = 1;

            // Recur to place rest of the queens
            res = solveNQueensUtil(board, col + 1) || res;

            // If placing queen in board[i][col] doesn't lead to a solution,
            // then remove queen from board[i][col]
            board[i][col] = 0; // Backtrack
        }
    }

    return res;
}

// Function to solve the N-Queens problem
void solveNQueens() {
    int board[N][N] = { {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0},
                       {0, 0, 0, 0} };

    if (!solveNQueensUtil(board, 0)) {
        cout << "Solution does not exist";
        return;
    }
}

// Main function
int main() {
    cout << "Solutions to the 4-Queens Problem:\n\n";
    solveNQueens();
    return 0;
}