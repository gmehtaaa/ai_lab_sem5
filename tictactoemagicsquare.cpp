#include <iostream>
#include <vector>
#include <map>
using namespace std;

map<int, int> magicSquare = {
    {1, 8}, {2, 3}, {3, 4},
    {4, 1}, {5, 5}, {6, 9},
    {7, 6}, {8, 7}, {9, 2}
};

vector<char> board(9, ' ');
vector<int> movesX, movesO; 

void printBoard() {
    cout << "\n";
    for (int i = 0; i < 9; i += 3) {
        cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
        if (i < 6) cout << "---+---+---\n";
    }
    cout << "\n";
}

bool checkWin(const vector<int>& moves) {
    if (moves.size() < 3) return false;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = i + 1; j < moves.size(); j++) {
            int needed = 15 - (moves[i] + moves[j]);
            for (int k = 0; k < moves.size(); k++) {
                if (moves[k] == needed) return true;
            }
        }
    }
    return false;
}

bool canWinNow(const vector<int>& moves, int &winningPos) {
    if (moves.size() < 2) return false;
    for (int i = 0; i < moves.size(); i++) {
        for (int j = i + 1; j < moves.size(); j++) {
            int neededVal = 15 - (moves[i] + moves[j]);
            if (neededVal <= 0 || neededVal > 9) continue;
            for (auto &entry : magicSquare) {
                if (entry.second == neededVal && board[entry.first - 1] == ' ') {
                    winningPos = entry.first;
                    return true;
                }
            }
        }
    }
    return false;
}

int computerMove() {
    int pos;
    if (canWinNow(movesO, pos)) return pos;
    if (canWinNow(movesX, pos)) return pos;
    for (int i = 1; i <= 9; i++) {
        if (board[i-1] == ' ') return i;
    }
    return -1;
}

int main() {
    cout << "=== Tic Tac Toe (Magic Square Approach) ===\n";
    cout << "You are X, Computer is O\n";
    char currentPlayer = 'X';

    for (int turn = 0; turn < 9; turn++) {
        printBoard();
        int pos;
        if (currentPlayer == 'X') {
            cout << "Enter your move (1-9): ";
            cin >> pos;
            if (pos < 1 || pos > 9 || board[pos-1] != ' ') {
                cout << "Invalid move. Try again.\n";
                turn--;
                continue;
            }
        } else {
            pos = computerMove();
            cout << "Computer chooses: " << pos << "\n";
        }

        board[pos-1] = currentPlayer;
        if (currentPlayer == 'X')
            movesX.push_back(magicSquare[pos]);
        else
            movesO.push_back(magicSquare[pos]);

        if ((currentPlayer == 'X' && checkWin(movesX)) ||
            (currentPlayer == 'O' && checkWin(movesO))) {
            printBoard();
            cout << ((currentPlayer == 'X') ? "You win!" : "Computer wins!") << "\n";
            return 0;
        }

        currentPlayer = (currentPlayer == 'X') ? 'O' : 'X';
    }

    printBoard();
    cout << "It's a draw!\n";
    return 0;
}
