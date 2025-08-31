#include <iostream>
#include <vector>
#include <limits>

using namespace std;

void printBoard(const vector<char>& board);
bool checkWin(const vector<char>& board, char player);
bool isBoardFull(const vector<char>& board);
int minimax(vector<char>& board, int depth, bool isMaximizingPlayer);
int findBestMove(vector<char>& board);

int main() {
    vector<char> board(9, ' ');
    cout << "Tic-Tac-Toe!" << endl;
    cout << "You are 'X', the computer is 'O'." << endl;

    int move;
    while (true) {
        printBoard(board);
        cout << "Enter your move (1-9): ";
        cin >> move;
        move--; 

        if (move >= 0 && move < 9 && board[move] == ' ') {
            board[move] = 'X';
        } else {
            cout << "Invalid move. Try again." << endl;
            continue;
        }

        if (checkWin(board, 'X')) {
            printBoard(board);
            cout << "You win! " << endl;
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie! " << endl;
            break;
        }

        int bestMove = findBestMove(board);
        board[bestMove] = 'O';

        if (checkWin(board, 'O')) {
            printBoard(board);
            cout << "Computer wins! " << endl;
            break;
        }

        if (isBoardFull(board)) {
            printBoard(board);
            cout << "It's a tie! " << endl;
            break;
        }
    }

    return 0;
}

void printBoard(const vector<char>& board) {
    cout << endl;
    for (int i = 0; i < 9; ++i) {
        cout << " " << board[i] << " ";
        if ((i + 1) % 3 == 0) {
            cout << endl;
            if (i < 8) {
                cout << "---|---|---" << endl;
            }
        } else {
            cout << "|";
        }
    }
    cout << endl;
}

bool checkWin(const vector<char>& board, char player) {
    const vector<vector<int>> win_combos = {
        {0, 1, 2}, {3, 4, 5}, {6, 7, 8}, 
        {0, 3, 6}, {1, 4, 7}, {2, 5, 8}, 
        {0, 4, 8}, {2, 4, 6}             
    };

    for (const auto& combo : win_combos) {
        if (board[combo[0]] == player && board[combo[1]] == player && board[combo[2]] == player) {
            return true;
        }
    }
    return false;
}

bool isBoardFull(const vector<char>& board) {
    for (char cell : board) {
        if (cell == ' ') {
            return false;
        }
    }
    return true;
}

int minimax(vector<char>& board, int depth, bool isMaximizingPlayer) {
    if (checkWin(board, 'O')) {
        return 10;
    }
    if (checkWin(board, 'X')) {
        return -10;
    }
    if (isBoardFull(board)) {
        return 0;
    }

    if (isMaximizingPlayer) {
        int best = numeric_limits<int>::min(); 
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = 'O';
                best = max(best, minimax(board, depth + 1, !isMaximizingPlayer));
                board[i] = ' '; 
            }
        }
        return best;
    } else {
        int best = numeric_limits<int>::max(); 
        for (int i = 0; i < 9; ++i) {
            if (board[i] == ' ') {
                board[i] = 'X';
                best = min(best, minimax(board, depth + 1, !isMaximizingPlayer));
                board[i] = ' '; 
            }
        }
        return best;
    }
}

int findBestMove(vector<char>& board) {
    int bestVal = numeric_limits<int>::min();
    int bestMove = -1;

    for (int i = 0; i < 9; ++i) {
        if (board[i] == ' ') {
            board[i] = 'O';
            int moveVal = minimax(board, 0, false);
            board[i] = ' '; 

            if (moveVal > bestVal) {
                bestMove = i;
                bestVal = moveVal;
            }
        }
    }
    return bestMove;
}
