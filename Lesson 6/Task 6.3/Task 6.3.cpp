#include <iostream>
#include <string>

int string_hash(std::string string)
{
    int hash_sum = 0;
    for (int i = 0; i < string.length(); i++)
    {
        hash_sum += static_cast<char>(string[i]);
    }
    return hash_sum;
}

int find_substring_light_rabin_karp(std::string source, std::string substring)
{
    int sub_hash = string_hash(substring);
    int source_hash=0;

    for (int i = 0; i < (source.length()- substring.length()); i++)
    {
        if (i == 0)
        {
            for(int j = 0; j < substring.length(); j++)
            source_hash+= static_cast<char>(source[j]);
        }
        else
        {
            source_hash -= static_cast<char>(source[i - 1]);
            source_hash += static_cast<char>(source[i + (substring.length() - 1)]);          
        }
        if (sub_hash == source_hash)
        {
            for (int j = 0; j < substring.length(); j++)
            {
                if (substring[j] == source[i + j]){ return i; }                
            }
        }
    }
    return -1;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача 3. Упрощённый алгоритм Рабина-Карпа.\n";

    std::string source, substring;
    int result;
    
    std::cout << "\nВведите строку, в которой будет осуществляться поиск: ";
    std::cin >> source;
    do
    {
        std::cout << "\nВведите подстроку, которую нужно найти: ";
        std::cin >> substring;

        result=find_substring_light_rabin_karp(source, substring);

        if (result == -1)
        {
            std::cout << "\nПодстрока \"" << substring << "\" не найдена.\n";
        }
        else
        {
            std::cout << "\nПодстрока \"" << substring << "\" найдена по индексу " << result << ".\n";
        }

    } while (substring != "exit");

}