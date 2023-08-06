#include <iostream>
#include <string>

int simple_string_hash(std::string string)
{
    int hash_sum = 0;
    for (int i = 0; i < string.length(); i++)
    {
        hash_sum += static_cast<char>(string[i]);
    }
    return hash_sum;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Наивная хэш-функция для строки.\n";

    std::string string;
    do
    {
        std::cout << "\nВведите строку (exit - для завершения): ";
        std::cin >> string;
        std::cout << "Наивный хэш строки \"" << string << "\" = " << simple_string_hash(string)<<"\n";
    } while (string != "exit");

}