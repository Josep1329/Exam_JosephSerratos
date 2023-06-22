#include <iostream>

int main() {
    
    int diceRoll = rand() % 6 + 1;
    std::string playerChoice;

    std::cout << "Choose even or odd: ";
    std::cin >> playerChoice;

    
    char playerSymbol = (diceRoll % 2 == 0 && playerChoice == "even") || (diceRoll % 2 != 0 && playerChoice == "odd") ? 'X' : 'O';

    std::cout << "You got " << diceRoll << ". You are assigned " << playerSymbol << ".\n";

   
    int matrix[3][4];
    int evenSum = 0;
    int positionSum = 0;

    std::cout << "Enter the elements of the matrix (3x4):\n";
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            std::cin >> matrix[i][j];

            if (matrix[i][j] % 2 == 0) {
                evenSum += matrix[i][j];
                positionSum += ((i * 10) + j);
            }
        }
    }

    int total = evenSum - positionSum;
    std::cout << "The sum of even numbers is " << evenSum << ".\n";
    std::cout << "The sum of positions is " << positionSum << ".\n";
    std::cout << "The total is " << total << ".\n";

    return 0;
}
