#ifndef PYRAMID_TICTACTOE_H
#define PYRAMID_TICTACTOE_H

#include "BoardGame_Classes.h"
#include <iostream>
#include <algorithm>
#include <ctime>
#include <cstdlib>

using namespace std;

template <typename T>
class PyramidBoard : public Board<T> {
private:

    char board[3][5];

    bool checkHorizontal() {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < (5 - 2 * i) - 2; ++j) {
                if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] != ' ')
                    return true;
            }
        }
        return false;
    }

    bool checkVertical() {
        if (board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[2][0] != ' ')
            return true;
        return false;
    }

    bool checkDiagonal() {
        if (board[0][0] == board[1][0] && board[1][0] == board[2][0] && board[0][0] != ' ') return true;
        if (board[0][4] == board[1][2] && board[1][2] == board[2][0] && board[0][4] != ' ') return true;
        return false;
    }

public:
    PyramidBoard() {
        // Initialize the board with spaces
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < 5; ++j) {
                board[i][j] = ' ';
            }
        }
    }

    bool update_board(int x, int y, T symbol) override {
        if (x >= 0 && x <= 2 && y >= 0 && y < (5 - 2 * x) && board[x][y] == ' ') {
            board[x][y] = symbol;
            return true;
        }
        else{
            cout << "Invalid move! Try again." << endl;
            return false;
        }
    }

    void display_board() override {
        for (int i = 2; i >= 0; --i) {
            // Print leading spaces for alignment
            for (int spaces = 0; spaces < 2 * i ; ++spaces)
                cout << ' ';
            // Print cells for the current row
            for (int j = 0; j < (5 - 2 * i); ++j)
                cout << (board[i][j] != ' ' ? board[i][j] : '.') << ' ';  // Print symbol or placeholder
            cout << endl;  // Move to the next line after finishing the row
        }
    }

    bool is_win() override {
        return checkHorizontal() || checkVertical() || checkDiagonal();
    }

    bool is_draw() override {
        for (int i = 0; i < 3; ++i) {
            for (int j = 0; j < (5 - 2 * i); ++j) {
                if (board[i][j] == ' ') {
                    return false;  // There's still an empty space
                }
            }
        }
        return true;  // No empty spaces, it's a draw
    }

    bool game_is_over() override {
        return is_win() || is_draw();
    }
};

template <typename T>
class PyramidPlayer : public Player<T> {
public:
    PyramidPlayer(string name, T symbol) : Player<T>(name, symbol) {}

    void getmove(int& x, int& y) override {
        cout << this->getname() << ", ";
        cout << "Enter row for your move:\n";
        cin >> x;
        cout << "Enter column for your move:\n";
        cin >> y;
    }
};

template <typename T>
class RandomPyramidPlayer : public Player<T> {
public:
    RandomPyramidPlayer(T symbol) : Player<T>("Computer", symbol) {}

    void getmove(int& x, int& y) override {
        do {
            x = rand() % 3;
            y = rand() % (5 - 2 * x);
        } while (!(x >= 0 && x < 3 && y >= 0 && y < (5 - 2 * x)));
    }
};

#endif // PYRAMID_TICTACTOE_H
