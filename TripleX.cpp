#include <iostream>
#include <ctime>

void PrintIntroduction(int LevelDifficulty) {
    std::cout << "\n\nYou are a secret agent breaking into a level " << LevelDifficulty;
    std::cout << " secure server room\nYou need to enter the correct codes to continue...\n\n";
}

bool PlayGame(int Difficulty) {
    PrintIntroduction(Difficulty);

    // Declare 3 number code
    int CodeA = rand() % Difficulty + Difficulty;
    int CodeB = rand() % Difficulty + Difficulty;
    int CodeC = rand() % Difficulty + Difficulty;
    int CodeSum = CodeA + CodeB + CodeC;
    int CodeProduct = CodeA * CodeB * CodeC;

    // Print sum and product to the terminal
    std::cout << "There are 3 numbers in the code\n";
    std::cout << "The sum of the code is " << CodeSum << std::endl;
    std::cout << "The product of the code is " << CodeProduct << std::endl;

    // Store the players guess of the code
    int GuessA, GuessB, GuessC;
    std::cout << "Take a guess! (enter 3 numbers below): ";
    std::cin >> GuessA >> GuessB >> GuessC;
    std::cout << std::endl;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Check if player's guess is correct or not
    if (GuessSum && CodeSum && GuessProduct == CodeProduct) {
        std::cout << "Nice! On to the next one.\n";
        return true;
    } else {
        std::cout << "Aw darn, try this level again..\n";
        return false;
    }
}

int main() {
    srand(time(NULL)); // Create
    const int MaxDifficulty = 10;
    int Difficulty = 1;
    while (Difficulty <= MaxDifficulty) {
        bool bLevelComplete = PlayGame(Difficulty);
        std::cin.clear();  // Clears any errors
        std::cin.ignore(); // Discards the buffer

        if (bLevelComplete) {
            // increase the level difficulty
            ++Difficulty;
        }
    }
    std::cout << "Wow! you beat all " << MaxDifficulty << " levels!";
    return 0;
}