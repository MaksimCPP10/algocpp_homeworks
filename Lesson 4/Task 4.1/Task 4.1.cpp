#include <iostream>

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{
    int* dyn_arr = new int[actual_size];
    
    dyn_arr=arr;
    
    for (int i = 0; i < actual_size; i++)
    {
        if (i >= logical_size)
        {
            std::cout << "_ ";
        }
        else
        {
            std::cout << dyn_arr[i] << " ";
        }
    }
    std::cout << "\n";

    delete[] dyn_arr;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Вывод изменяемого динамического массива.\n";

    int logical_size, actual_size, value;
    do
    {
        std::cout << "\nВведите фактичеcкий размер массива: ";
        std::cin >> actual_size;
        std::cout << "\nВведите логический размер массива: ";
        std::cin >> logical_size;
        if (logical_size > actual_size)
        {
            std::cout << "\a\nОшибка! Логический размер массива не может превышать фактический!\n";
        }
    } while (logical_size > actual_size);

    int* arr = new int[logical_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "\nВведите arr[" << i << "]: ";
        std::cin >> value;
        arr[i] = value;
    }
    std::cout << "\nДинамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
}