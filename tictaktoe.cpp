#include <iostream>
#include <vector>

class TicTacToe {
private:
    char board[3][3];
    char currentPlayer;

public:
    TicTacToe() {
        // Initialize the board and set the starting player to 'X'
        currentPlayer = 'X';
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    void displayBoard() {
        std::cout << "   1   2   3\n";
        for (int i = 0; i < 3; ++i) {
            std::cout << i + 1 << " ";
            for (int j = 0; j < 3; ++j) {
                std::cout << " " << board[i][j] << " ";
                if (j < 2) std::cout << "|";
            }
            std::cout << "\n";
            if (i < 2) std::cout << "  ---|---|---\n";
        }
        std::cout << "\n";
    }

    bool makeMove(int row, int col) {
        if (row < 0 || row >= 3 || col < 0 || col >= 3 || board[row][col] != ' ') {
            return false;  // Invalid move
        }
        board[row][col] = currentPlayer;
        return true;
    }

    bool checkWin() {
        // Check rows, columns, and diagonals for a win
        for (int i = 0; i < 3; ++i) {
            if (board[i][0] == currentPlayer && board[i][1] == currentPlayer && board[i][2] == currentPlayer)
                return true;
            if (board[0][i] == currentPlayer && board[1][i] == currentPlayer && board[2][i] == currentPlayer)
                return true;
        }
        if (board[0][0] == currentPlayer && board[1][1] == currentPlayer && board[2][2] == currentPlayer)
            return true;
        if (board[0][2] == currentPlayer && board[1][1] == currentPlayer && board[2][0] == currentPlayer)
            return true;
        return false;
    }

    bool checkDraw() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 3; ++j) {
                if (board[i][j] == ' ') {
                    return false;  // If there's an empty space, the game is not a draw
                }
            }
        }
        return true;  // All spaces are filled, indicating a draw
    }

    void switchPlayers() {
        if (currentPlayer == 'X') {
            currentPlayer = 'O';
        } else {
            currentPlayer = 'X';
        }
    }

    void play() {
        int row, col;
        bool validMove;

        std::cout << "TIC-TAC-TOE GAME\n";

        do {
            displayBoard();
            validMove = false;
            while (!validMove) {
                std::cout << "Player " << currentPlayer << ", enter your move (row column): ";
                std::cin >> row >> col;
                validMove = makeMove(row - 1, col - 1);
                if (!validMove) {
                    std::cout << "Invalid move. Try again.\n";
                }
            }

            if (checkWin()) {
                displayBoard();
                std::cout << "Player " << currentPlayer << " wins!\n";
                break;
            }

            if (checkDraw()) {
                displayBoard();
                std::cout << "It's a draw!\n";
                break;
            }

            switchPlayers();
        } while (true);
    }
};

int main() {
    char playAgain;

    do {
        TicTacToe game;
        game.play();

        std::cout << "Play again? (y/n): ";
        std::cin >> playAgain;
    } while (playAgain == 'y' || playAgain == 'Y');

    return 0;
}
