#include <iostream>
#include<string>

long long int real_string_hash(int p, int n, std::string string)
{
    long long int hash_sum = 0, mult=1;
    for (int i = 0; i < string.length(); i++)
    {
        if (i == 0)
        {
            hash_sum += static_cast<char>(string[i]);
        }
        else
        {
            mult = mult * p;
            hash_sum += static_cast<char>(string[i]) * mult;
        }
    }
    hash_sum %= n;
    return hash_sum;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Настоящая хэш-функция для строки.\n";

    std::string string;
    int p, n;

    std::cout << "\nВведите p: ";
    std::cin >> p;
    std::cout << "Введите n: ";
    std::cin >> n;
    do
    {
        std::cout << "\nВведите строку (exit - для завершения): ";
        std::cin >> string;
        std::cout << "Хэш строки \"" << string << "\" = " << real_string_hash(p, n, string)<<"\n";
    } while (string != "exit");

}