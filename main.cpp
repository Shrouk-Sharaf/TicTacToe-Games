#include "Pyramid Tic-Tac-Toe.h"
#include "Word Tic-Tac-Toe.h"
using namespace std;

void showMenu() {
    cout << "Welcome to Tic Tac Toe!\n";
    cout << "Please select an option:\n";
    cout << "1. Play Pyramid Tic Tac Toe\n";
    cout << "2. Play Word Tic Tac Toe\n";
    cout << "3. Exit\n";
    cout << "Your choice:\n";
}

int main() {
    int choice;

    while (true) {
        showMenu();
        cin >> choice;

        if (choice == 3) {
            cout << "Thank you for using our program!\n";
            break;
        }

        // Declare pointers for the board and player array
        Board<char> *board = nullptr;
        Player<char>* players[2];
        int mode;

        cout << "Select game mode:\n";
        cout << "1. Player vs Player\n";
        cout << "2. Player vs Computer\n";
        cout << "Your choice:\n";
        cin >> mode;
        if (mode != 1 && mode != 2) {
            cout << "Invalid game mode, returning to main menu.\n";
            continue;
        }

        switch (choice) {
            case 1: { // Pyramid Game
                cout << "Pyramid Tic Tac Toe selected.\n";
                board = new PyramidBoard<char>();

                // Player setup
                for (int i = 0; i < 2; ++i) {
                    cout << "Player " << (i + 1) << (i == 0 ? " (X): " : " (O): ");
                    if (mode == 2 && i == 1) {
                        cout << "Computer player will be used.\n";
                        players[i] = new RandomPyramidPlayer<char>('O');
                    } else {
                        cout << "Enter the name of player:\n";
                        string name;
                        cin >> name;
                        players[i] = new PyramidPlayer<char>(name, i == 0 ? 'X' : 'O');
                    }
                }
                break;
            }
            case 2: {
                cout << "Word Tic Tac Toe selected.\n";
                board = new WordBoard();

                // Player setup
                for (int i = 0; i < 2; ++i) {
                    if (mode == 2 && i == 1) {
                        cout << "Computer player will be used.\n";
                        players[i] = new WordRandomPlayer('O');
                    } else {
                        cout << "Enter the name of player:\n";
                        string name;
                        cin >> name;
                        players[i] = new WordPlayer(name, i == 0 ? 'X' : 'O');
                    }
                }
                break;
            }
            default:
                cout << "Invalid choice, please try again.\n";
                continue;
        }

        // Use the GameManager to run the game
        GameManager<char> manager(board, players);
        manager.run();
        
        // Clean up memory
        delete board;
        delete players[0];
        delete players[1];
    }

    return 0;
}
