#include <iostream>

long int Fib_dyn(int number)
{
    long int *Fib = new long int[number + 1];
    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    return Fib[number];
    delete[] Fib;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Ускоряем Фибоначчи.\n";
    int answer;
    std::cout << "\nВведите число: ";
    std::cin >> answer;
    std::cout << "\nЧисло Фибоначчи числа " << answer << " равно " << Fib_dyn(answer) << ".\n";
}