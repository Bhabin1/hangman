#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

void drawHangman(int lives) {
    if (lives == 6) {
        cout << " +---+ \n";
        cout << " |     \n";
        cout << " |     \n";
        cout << " |     \n";
        cout << " |     \n";
        cout << " |     \n";
    } else if (lives == 5) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |     \n";
        cout << " |     \n";
        cout << " |     \n";
    } else if (lives == 4) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |   | \n";
        cout << " |   |  \n";
        cout << " |     \n";
    } else if (lives == 3) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |   |\ \n";
        cout << " |   |  \n";
        cout << " |     \n";
    } else if (lives == 2) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |  /|\ \n";
        cout << " |   |  \n";
        cout << " |     \n";
    } else if (lives == 1) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |  /|\ \n";
        cout << " |   | \n";
        cout << " |    \ \n";
    } else if (lives == 0) {
        cout << " +---+ \n";
        cout << " |   | \n";
        cout << " |   O \n";
        cout << " |  /|\    \n";
        cout << " |   |     \n";
        cout << " |  / \ \n";
    }
}

int main() {
    srand(time(0));
    string words[]={"bhabin","hangman","program","project","science","computer","intelligence","instruct"};
    int numwords=sizeof(words) / sizeof(words[0]);
    int randomIndex= rand() % numwords;
    string word = words[randomIndex];
    int lives = 6;
    string guessedWord = string(word.length(), ' _ ');

    while (lives > 0) {
        drawHangman(lives);
        cout << "Word: " << guessedWord << endl;

        char guess;
        cout << "Guess a letter: ";
        cin >> guess;

        bool correctGuess = false;
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == guess) {
                guessedWord[i] = guess;
                correctGuess = true;
            }
        }

        if (!correctGuess) {
            lives--;
        }

        if (guessedWord == word) {
            cout << "Congratulations, you won!" << endl;
            return 0;
        }
    }

    cout << "Sorry, you lost. The word was " << word << endl;
    return 0;
}