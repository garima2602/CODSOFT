#include <iostream>
int main() 
{
    double n1, n2, result;
    char op;
    std::cout << "Enter the first number: ";
    std::cin >> n1;
    std::cout << "Enter the second number: ";
    std::cin >> n2;
    std::cout << "Choose an operation out of the following(+, -, *, /): ";
    std::cin >> op;
    switch(op) 
    {
        case '+':
            result = n1 + n2;
            std::cout << n1 << " + " << n2 << " = " << result << std::endl;
            break;
        case '-':
            result = n1 - n2;
            std::cout << n1 << " - " << n2 << " = " << result << std::endl;
            break;
        case '*':
            result = n1 * n2;
            std::cout << n1 << " * " << n2 << " = " << result << std::endl;
            break;
        case '/':
            if(n2 != 0) 
            {
                result = n1 / n2;
                std::cout << n1 << " / " << n2 << " = " << result << std::endl;
            } 
            else 
            {
                std::cout << "Error: Division by zero is not allowed." << std::endl;
            }
            break;
        default:
            std::cout << "Error: Invalid operation." << std::endl;
    }
    return 0;
}