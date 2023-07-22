#include <iostream>

unsigned int Fib_dyn(unsigned int* arr, int number)
{
    auto Fib = arr;
    Fib[0] = 0;
    Fib[1] = 1;
    for (int i = 2; i <= number; i++)
    {
        Fib[i] = Fib[i - 1] + Fib[i - 2];
    }
    return Fib[number];
    
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Ускоряем Фибоначчи.\n";
    int answer;
    std::cout << "\nВведите число: ";
    std::cin >> answer;
    unsigned int* Fib = new unsigned int[answer + 1];
    std::cout << "\nЧисло Фибоначчи числа " << answer << " равно " << Fib_dyn(Fib, answer) << ".\n";
    delete[] Fib;
}