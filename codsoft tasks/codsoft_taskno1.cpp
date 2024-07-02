#include <iostream>
#include <cstdlib>
#include <ctime>
int main() 
{
    srand(time(0));
    int random = rand()%1000+1;
    int guess;
    int trials = 0;
    std::cout << "I've thought of a number between 1 and 1000.\n";
    do 
    {
        std::cout << "Enter your guess: ";
        std::cin >> guess;
        trials++;
        if (guess > random) 
        {
            std::cout << "Too high! Please try again.\n";
        } 
        else if (guess < random) 
        {
            std::cout << "Too low! Please try again.\n";
        } 
        else 
        {
            std::cout << "You have succcessfully guessed the correct number in " << trials << " attempts!\n";
        }
    } 
    while (guess != random);
    return 0;
}