#include <iostream>

int append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int value)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = value;
        logical_size += 1;
       
        return *arr;
    }
    else if (logical_size == actual_size)
    {        
        actual_size *= 2;
        int* new_arr = new int[actual_size];
                
        for (int i = 0; i < logical_size; i++)
        {
            new_arr[i] = arr[i];
            
        }
        arr[logical_size] = value;//Если данное выражение поставить в это место, то программа отрабатывает как и ожидается, но после 
        //нажатия "0" для завершения, программа записывает 0 последним элементом и "падает"...
        arr = new_arr;
        delete[] new_arr;

        //arr[logical_size] = value; //Если данное выражение поставить в это место, то программа отрабатывает без "падения", но прис-
        //ваивания элементу arr[logical_size] значения value не происходит.
        logical_size += 1;
        
        return *arr;        
    }
    return *arr;
}

void print_dynamic_array(int* arr, int logical_size, int actual_size)
{ 
    for (int i = 0; i < actual_size; i++)
    {
        if (i >= logical_size)
        {
            std::cout << "_ ";
        }
        else
        {
            std::cout << arr[i] << " ";
        }
    }
    std::cout << "\n";
}

int main()
{
    setlocale(0, "");
    std::cout << "\n\t\tЗадача №2. Добавление в изменяемый динамический массив.\n";

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

    int* arr = new int[actual_size];

    for (int i = 0; i < logical_size; i++)
    {
        std::cout << "\nВведите arr[" << i << "]: ";
        std::cin >> value;
        arr[i] = value;
    }

    std::cout << "\nДинамический массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    do
    {
        std::cout << "\nВведите элемент для добавления: (0 - для завершения) ";
        std::cin >> value;
        append_to_dynamic_array(arr, logical_size, actual_size, value);
        std::cout << "\nДинамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);

    } while (value != 0);

    std::cout << "\nСпасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
}