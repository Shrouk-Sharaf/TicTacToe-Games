#include "Pyramic Tic-Tac-Toe.h"

int main() {
    srand(static_cast<unsigned int>(time(0))); // Initialize random seed

    PyramidBoard<char> board;
    Player<char>* player1;
    Player<char>* player2;

    int choice;
    cout << "Choose game mode:\n";
    cout << "1. Player vs Player\n";
    cout << "2. Player vs Computer\n";
    cout << "Enter your choice (1 or 2):\n";
    cin >> choice;

    string name1, name2;
    cout << "Enter name for Player 1:\n";
    cin >> name1;
    player1 = new PyramidPlayer<char>(name1, 'X');

    if (choice == 1) {
        cout << "Enter name for Player 2:\n";
        cin >> name2;
        player2 = new PyramidPlayer<char>(name2, 'O');
    }
    else {
        player2 = new RandomPyramidPlayer<char>('O');
    }

    Player<char>* players[2] = {player1, player2};
    GameManager<char> manager(&board, players);
    manager.run();
}