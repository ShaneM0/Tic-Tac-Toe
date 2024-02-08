// Code made by _sm0
#include <iostream>
#include <vector>

using namespace std;

// Function to initialize the Tic-Tac-Toe board
vector<vector<char>> initializeBoard() {
    vector<vector<char>> board(3, vector<char>(3, ' '));
    return board;
}

// Function to display the Tic-Tac-Toe board
void displayBoard(const vector<vector<char>>& board) {
    cout << "-------------" << endl;
    for (int i = 0; i < 3; ++i) {
        cout << "| ";
        for (int j = 0; j < 3; ++j) {
            cout << board[i][j] << " | ";
        }
        cout << endl << "-------------" << endl;
    }
}

// Function to check if a player has won
bool checkWin(const vector<vector<char>>& board, char player) {
    // Check rows and columns
    for (int i = 0; i < 3; ++i) {
        if (board[i][0] == player && board[i][1] == player && board[i][2] == player) return true; // Check rows
        if (board[0][i] == player && board[1][i] == player && board[2][i] == player) return true; // Check columns
    }
    // Check diagonals
    if (board[0][0] == player && board[1][1] == player && board[2][2] == player) return true; // Check diagonal
    if (board[0][2] == player && board[1][1] == player && board[2][0] == player) return true; // Check anti-diagonal
    return false;
}

// Function to check if the board is full (tie)
bool checkTie(const vector<vector<char>>& board) {
    for (const auto& row : board) {
        for (char cell : row) {
            if (cell == ' ') return false; // There is an empty cell, game is not tied
        }
    }
    return true; // All cells are filled, game is tied
}

// Function to get player's move
void getPlayerMove(vector<vector<char>>& board, char player) {
    int row, col;
    cout << "Player " << player << "'s turn. Enter row (1-3) and column (1-3) separated by space: ";
    cin >> row >> col;
    --row; // Adjust to 0-based indexing
    --col; // Adjust to 0-based indexing
    if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
        cout << "Invalid move! Try again." << endl;
        getPlayerMove(board, player); // Retry move
    } else {
        board[row][col] = player; // Update board with player's move
    }
}

int main() {
    vector<vector<char>> board = initializeBoard();
    char currentPlayer = 'X';

    cout << "Welcome to Tic-Tac-Toe!" << endl;
    cout << "Player X starts the game." << endl;

    while (true) {
        displayBoard(board);
        getPlayerMove(board, currentPlayer);

        if (checkWin(board, currentPlayer)) {
            displayBoard(board);
            cout << "Player " << currentPlayer << " wins!" << endl;
            break;
        } else if (checkTie(board)) {
            displayBoard(board);
            cout << "It's a tie!" << endl;
            break;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X'; // Switch players
    }

    return 0;
}
