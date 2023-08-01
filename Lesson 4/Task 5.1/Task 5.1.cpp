#include <iostream>

void print_array(int* arr, int size)
{
    std::cout << "\nИсходный массив: ";
    for (int i = 0; i < size; i++)
    {
        std::cout << arr[i] << " ";
    }
}

void print_pyramid(int* arr, int size)
{   

    int parent, left_child, right_child, level=0;
    std::cout << "\nПирамида:\n";

    

    for (int i = 0; i < size/2; i++)
    {
        if (i == 0)
        {
            std::cout << level << " root " << arr[0] << "\n";
            level++;
        }
        parent = arr[i];
        left_child = arr[(i * 2) + 1];
        std::cout << level << " left (" << parent << ") " << left_child << "\n";

        
        if ((i * 2 + 2) >= size) { continue; }
        else
        {
            right_child = arr[(i * 2) + 2];
            std::cout << level << " right (" << parent << ") " << right_child << "\n";
        }
                  
        level++;
        
    }
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №1. Вывод пирамиды на массиве.\n";

    int arr1[] = { 1, 3, 6, 5, 9, 8 };
    print_array(arr1, sizeof(arr1) / sizeof(arr1[0]));
    print_pyramid(arr1, sizeof(arr1) / sizeof(arr1[0]));

    int arr2[] = { 94, 67, 18, 44, 55, 12, 6, 42 };
    print_array(arr2, sizeof(arr2) / sizeof(arr2[0]));
    print_pyramid(arr2, sizeof(arr2) / sizeof(arr2[0]));

    int arr3[] = { 16, 11, 9, 10, 5, 6, 8, 1, 2, 4 };
    print_array(arr3, sizeof(arr3) / sizeof(arr3[0]));
    print_pyramid(arr3, sizeof(arr3) / sizeof(arr3[0]));

    return 0;
}

