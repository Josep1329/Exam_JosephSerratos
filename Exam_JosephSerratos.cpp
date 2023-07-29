#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;


int factorial(int n) {
    if (n == 0) {
        return 1;
    }
    else {
        return n * factorial(n - 1);
    }
}

int main() {
    int choice;

    do {
             cout << "\nChoose a task:\n";
             cout << "1. Generate triples of numbers\n";
             cout << "2. Find the largest number\n";
             cout << "3. Display the first 10 Fibonacci numbers\n";
             cout << "4. Count how many times the largest number is repeated\n";
             cout << "5. Find positions of numbers ending in 4\n";
             cout << "6. Find positions of the number with the most digits\n";
             cout << "7. Calculate factorials of 10 numbers\n";
             cout << "8. Guess my number \n";
             cout << "0. Exit\n";
             cout << "Enter your choice: ";
             cin >> choice;

        switch (choice) {
        case 1: {
            
            for (int i = 1; i <= 3; ++i) {
                for (int j = 1; j <= 3; ++j) {
                    for (int k = 1; k <= 3; ++k) {
                        std::cout << i << "\t" << j << "\t" << k << "\n";
                    }
                }
            }
            break;
        }
        case 2: {
            
                vector<int> numbers;
            int num;

            for (int i = 0; i < 12; ++i) {
                    cout << "Enter an integer: ";
                    cin >> num;
                numbers.push_back(num);
            }

            int largest_number = *max_element(numbers.begin(), numbers.end());
                cout << "The largest number is: " << largest_number << "\n";
            break;
        }
        case 3: {
            
                vector<int> fibonacci{0, 1};

            while (fibonacci.size() < 10) {
                int next_num = fibonacci[fibonacci.size() - 1] + fibonacci[fibonacci.size() - 2];
                fibonacci.push_back(next_num);
            }

               cout << "The first 10 Fibonacci numbers are:";
            for (int num : fibonacci) {
                  cout << " " << num;
            }
            std::cout << "\n";
            break;
        }
        case 4: {
            
               vector<int> numbers;
            int num;

            for (int i = 0; i < 8; ++i) {
                     cout << "Enter an integer: ";
                     cin >> num;
                numbers.push_back(num);
            }

            int largest_number = *max_element(numbers.begin(), numbers.end());
            int count_largest = count(numbers.begin(), numbers.end(), largest_number);

                cout << "The largest number " << largest_number << " is repeated " << count_largest << " times.\n";
            break;
        }
        case 5: {
            
               vector<int> numbers;
            int num;

            for (int i = 0; i < 10; ++i) {
                     cout << "Enter an integer: ";
                     cin >> num;
                numbers.push_back(num);
            }

                 vector<int> positions_ending_in_4;
            for (int i = 0; i < numbers.size(); ++i) {
                if (numbers[i] % 10 == 4) {
                    positions_ending_in_4.push_back(i);
                }
            }

                cout << "Positions of numbers ending in 4:";
            for (int pos : positions_ending_in_4) {
                   cout << " " << pos;
            }
                 cout << "\n";
            break;
        }
        case 6: {
            
                vector<int> numbers;
            int num;

            for (int i = 0; i < 7; ++i) {
                     cout << "Enter an integer: ";
                     cin >> num;
                numbers.push_back(num);
            }

            int max_digits = 0;
                vector<int> positions_with_max_digits;
            for (int i = 0; i < numbers.size(); ++i) {
                int digits = 0;
                int temp_num = numbers[i];
                while (temp_num != 0) {
                    temp_num /= 10;
                    ++digits;
                }
                if (digits > max_digits) {
                    max_digits = digits;
                    positions_with_max_digits.clear();
                    positions_with_max_digits.push_back(i);
                }
                else if (digits == max_digits) {
                    positions_with_max_digits.push_back(i);
                }
            }

                cout << "Position(s) with the most digits:";
            for (int pos : positions_with_max_digits) {
                    cout << " " << pos;
            }
              cout << "\n";
            break;
        }
        case 7: {
            
                vector<int> numbers;
            int num;

            for (int i = 0; i < 10; ++i) {
                   cout << "Enter an integer: ";
                   cin >> num;
                numbers.push_back(num);
            }

                 vector<int> factorials;
            for (int num : numbers) {
                factorials.push_back(factorial(num));
            }

                 cout << "Factorials of the numbers:";
            for (int fact : factorials) {
                 cout << " " << fact;
            }
                cout << "\n";
            break;
        }
        case 8: {
            srand(time(0)); 
            int lowerBound = 1;
            int upperBound = 100;
            int guess;
            char clue;

            cout << "Think of a number between " << lowerBound << " and " << upperBound << "." << endl;
            cout << "Press 'c' if the guess is correct, 'h' if it's higher, 'l' if it's lower, 'v' if it's very close, 'f' if it's far." << endl;

            do {
                guess = lowerBound + (rand() % (upperBound - lowerBound + 1));

                cout << "Is the number " << guess << "? (c/h/l/v/f): ";
                cin >> clue;

                if (clue == 'h') {
                    lowerBound = guess + 1;
                }
                else if (clue == 'l') {
                    upperBound = guess - 1;
                }
                else if (clue == 'v') {
                    lowerBound = max(lowerBound, guess - 10);
                    upperBound = min(upperBound, guess + 10);
                }
                else if (clue == 'f') {
                    lowerBound = max(lowerBound, guess + 11);
                    upperBound = min(upperBound, guess - 11);
                }

            } while (clue != 'c');

            cout << "Great! The number was " << guess << "." << endl;
            return 0;
        }
              break;

        case 0:
               cout << "Exiting.\n";
            break;
            default:
               cout << "Invalid choice. Try again.\n";
            break;
        }
    } while (choice != 0);

    return 0;
}

