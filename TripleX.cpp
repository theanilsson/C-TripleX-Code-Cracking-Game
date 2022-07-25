#include <iostream>
#include <ctime>
#include <cstdio>

void PrintIntroduction (int Difficulty)
{
    // Prints welcome messages to the terminal
    std::cout << "\nYou are an antivirus program trying to block specific codes of level attacking IP adresses.\n";
    std::cout << "The hackers you are up against are at skill level " << Difficulty;
    std::cout << ".\nYou need to enter the correct codes to ward them off...\n";
    std::cout << "Enter each digit separated by a space or by pressing enter after each digit you input\n\n";
}

bool PlayGame (int Difficulty)
{
    PrintIntroduction(Difficulty);

    // Declares 3 numbered code in variables
    const int CodeX = rand() % Difficulty + Difficulty;
    const int CodeY = rand() % Difficulty + Difficulty;
    const int CodeZ = rand() % Difficulty + Difficulty;

    const int CodeSum = CodeX + CodeY + CodeZ;
    const int CodeProduct = CodeX * CodeY * CodeZ;

    // Prints sum and product to the terminal
    std::cout << "+ There are 3 numbers in the code";
    std::cout << "\n+ The codes add up to " << CodeSum;
    std::cout << "\n+ The codes multiply to give " << CodeProduct << "\n";

    // Stores player guesses
    int GuessA, GuessB, GuessC;
    std::cin >> GuessA >> GuessB >> GuessC;

    int GuessSum = GuessA + GuessB + GuessC;
    int GuessProduct = GuessA * GuessB * GuessC;

    // Checks if the player guesses are correct
    if (GuessSum == CodeSum && GuessProduct == CodeProduct)
    {
        std::cout << "\n*** You warded off the attacking IP adresses of the level " << Difficulty << " hackers. ***";
        std::cout << "\n*** You entered: " << GuessA << GuessB << GuessC << "\n\n";
        return true;
    }
    else
    {
        std::cout << "\n*** You entered the wrong code, the attacking IP adresses are one step closer to aquiring your data, try again! ***";
        std::cout << "\n*** You entered: " << GuessA << GuessB << GuessC << "\n\n";
        return false;
    }
}

int main()
{
    srand(time(NULL));
    int LevelDifficulty = 1;
    const int MaxDifficulty = 4;
    while (LevelDifficulty <= MaxDifficulty) // Loop game until all levels are completed
    {
        bool bLevelComplete = PlayGame(LevelDifficulty);
        std::cin.clear();
        std::cin.ignore();

        if (bLevelComplete)
        {
            ++LevelDifficulty;
        }

    }

    std::cout << "\n*** Congratulations on beating all of the hackers, you are a level " << LevelDifficulty << "+ antivirus program. ***";
    std::getchar();
    return 0;
}