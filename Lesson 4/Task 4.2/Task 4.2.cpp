#include <iostream>

int* append_to_dynamic_array(int* arr, int& logical_size, int& actual_size, int value)
{
    if (logical_size < actual_size)
    {
        arr[logical_size] = value;
    }
    else if (logical_size == actual_size)
    {        
        actual_size *= 2;
        int* new_arr = new int[actual_size];

        new_arr[logical_size] = value;
                     
        for (int i = 0; i < logical_size; ++i)
        {
            new_arr[i] = arr[i];           
        } 

        /*new_arr[logical_size] = value; */

        //Остался только один вопрос : почему при размещении данного выражения в этом месте кода, всё равно
        //появляется предупреждение о переполнении буфера при записи в "new_arr"? Ведь new_arr имеет размер [actual_size] и
        //new_arr[logical_size] не выходит за "границы" [actual_size].
  
        delete[] arr;
        arr = new_arr;
        
    }
    logical_size += 1;

    return arr;
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
        arr=append_to_dynamic_array(arr, logical_size, actual_size, value);
        std::cout << "\nДинамический массив: ";
        print_dynamic_array(arr, logical_size, actual_size);

    } while (value != 0);

    std::cout << "\nСпасибо! Ваш массив: ";
    print_dynamic_array(arr, logical_size, actual_size);

    delete[] arr;
}