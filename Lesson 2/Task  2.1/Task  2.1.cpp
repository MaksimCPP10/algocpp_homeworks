#include <iostream>

long int Fib(long int number)
{
    if (number < 1) { return 0; }
    if (number == 1) { return 1; }
    return Fib(number - 1) + Fib(number - 2);
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Снова числа Фибоначчи.\n";
    long int answer;
    std::cout << "\nВведите число: ";
    std::cin >> answer;
    std::cout << "\nЧисло Фибоначчи числа " << answer << " равно " << Fib(answer) << ".\n";

}