#include <iostream>

int founder(int* arr, int size, int ref_point)
{
    std::cout << "\nИсходный массив:\n";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }


    int midle, left = 0, right = size - 1;
    int point=0, count = 0;
    do
    {
        midle = (left + right) / 2;
        
        if (arr[midle] > ref_point)
        {
            right = midle - 1;
        }
        else if (arr[midle] < ref_point)
        {
            left = midle + 1;
        }
        if (arr[midle] = (arr[midle - 1] < ref_point < arr[midle + 1]))
        {
            point = midle;
            continue;
        }
    } while (left < right);


    for (int i = point; i < size; i++)
    {
        count++;
    }
    return count;
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Поиск в массиве.";

    int ref_point, size;
    int arr[] { 14,16,19,32,32,32,56,69,72 };
    size = sizeof(arr) / sizeof(int);

    
    std::cout << "\n\nВведите точку отсчёта: ";
    std::cin >> ref_point;
    std::cout << "\n\nКоличество элементов в массиве больших, чем " << ref_point << ": " << founder(arr, size, ref_point)<<"\n";

}


