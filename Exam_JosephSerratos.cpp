
#include <iostream>
#include <cstdlib> 
#include <vector>

using namespace std;

class Critter
{
public:
    Critter(int hunger = 10, int boredom = 20, int tiredness = 50); 
    void Talk();
    void Eat(int food = 4);
    void Play(int fun = 4);
    void Rest(int sleep = 4);
    void ShowNecessities();
    bool IsHappy();
    bool IsUnwell();
    bool IsDying();

private:
    int m_Hunger;
    int m_Boredom;
    int m_Tiredness;
    void PassTime(int time = 1);
};

Critter::Critter(int hunger, int boredom, int tiredness) :
    m_Hunger(hunger),
    m_Boredom(boredom),
    m_Tiredness(tiredness)
{}

void Critter::PassTime(int time)
{
    m_Hunger -= time;
    m_Boredom -= time;
    m_Tiredness -= time;

    if (m_Hunger < 0)
    {
        m_Hunger = 0;
    }
    if (m_Boredom < 0)
    {
        m_Boredom = 0;
    }
    if (m_Tiredness < 0)
    {
        m_Tiredness = 0;
    }
}

void Critter::Talk()
{
    ShowNecessities();
    if (IsDying())
    {
        cout << "\nI'm dying, do something! I need ";
        if (m_Hunger <= 0)
            cout << "food";
        else if (m_Boredom <= 0)
            cout << "to play";
        else if (m_Tiredness <= 0)
            cout << "rest";
        cout << ".\n";

        
        if (m_Hunger <= 0 || m_Boredom <= 0 || m_Tiredness <= 0)
        {
            cout << "\nYour mascot has died. Game Over.\n";
            exit(0);
        }
    }
    else if (IsUnwell())
    {
        cout << "\nI'm not feeling well. I need ";
        if (m_Hunger <= 10)
            cout << "food";
        else if (m_Boredom <= 10)
            cout << "to play";
        else if (m_Tiredness <= 10)
            cout << "rest";
        cout << ".\n";
    }
    else if (IsHappy())
    {
        cout << "\nI'm happy!\n";
    }
}

void Critter::Eat(int food)
{
    cout << "\nBrrupp. \n";
    m_Hunger += food;
    PassTime();
}

void Critter::Play(int fun)
{
    cout << "\nWheee!\n";
    m_Boredom += fun;
    PassTime();
}

void Critter::Rest(int sleep)
{
    cout << "\nZzzzzz...\n";
    m_Tiredness += sleep;
    PassTime();
}

void Critter::ShowNecessities()
{
    cout << "\nList of necessities:\n";
    cout << "Hunger: " << m_Hunger << endl;
    cout << "Boredom: " << m_Boredom << endl;
    cout << "Tiredness: " << m_Tiredness << endl;
}

bool Critter::IsHappy()
{
    return m_Hunger >= 40 && m_Boredom >= 40 && m_Tiredness >= 40;
}

bool Critter::IsUnwell()
{
    return (m_Hunger <= 20 || m_Boredom <= 20 || m_Tiredness <= 20) && !IsDying();
}

bool Critter::IsDying()
{
    return m_Hunger <= 0 || m_Boredom <= 0 || m_Tiredness <= 0;
}

int main()
{
    Critter crit;
    int choice;
    do
    {
        cout << "\n Mascotas Virtuales\n\n";
        cout << "0 - Salir.\n";
        cout << "1 - Escucha a tu mascota.\n";
        cout << "2 - Alimentar.\n";
        cout << "3 - Jugar con tu mascota.\n";
        cout << "4 - Descansar.\n";
        cout << "Elige una opción: ";
        cin >> choice;

        switch (choice)
        {
        case 0:
            cout << "Vuelve pronto!.\n";
            break;
        case 1:
            crit.Talk();
            break;
        case 2:
            crit.Eat();
            break;
        case 3:
            crit.Play();
            break;
        case 4:
            crit.Rest();
            break;
        default:
            cout << "\n Tu elección es inválida. \n";
        }
    } while (choice != 0);

    if (crit.IsDying())
    {
        cout << "\nYour mascot has died. Game Over.\n";
    }
}




void readNumbers(std::vector<int>& numbers) 
{
    std::cout << "Enter 8 numbers:\n";
    for (int i = 0; i < 8; ++i) {
        std::cin >> numbers[i];
    }
}


int countEvenDigits(int number) {
    int count = 0;
    while (number != 0) {
        int digit = number % 10;
        if (digit % 2 == 0) {
            ++count;
        }
        number /= 10;
    }
    return count;
}


int findLargestEvenDigitsIndex(const std::vector<int>& numbers) {
    int maxEvenDigits = -1;
    int index = -1;

    for (size_t i = 0; i < numbers.size(); ++i) {
        int evenDigitsCount = countEvenDigits(numbers[i]);
        if (evenDigitsCount > maxEvenDigits) {
            maxEvenDigits = evenDigitsCount;
            index = i;
        }
    }

    return index;
}

int main() {
    std::vector<int> numbers(8);
    readNumbers(numbers);

    int* largestEvenDigitsNumberPtr = &numbers[findLargestEvenDigitsIndex(numbers)];

    std::cout << "The number with the largest number of even digits is: " << *largestEvenDigitsNumberPtr << std::endl;
    std::cout << "Memory address of the number: " << largestEvenDigitsNumberPtr << std::endl;
    std::cout << "Position of the number in the vector: " << largestEvenDigitsNumberPtr - &numbers[0] << std::endl;

    return 0;
}



