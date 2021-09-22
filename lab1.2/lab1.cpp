#include <iostream>
#include <fstream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std;

const int max_rand = 10;
void menu();
void menu2();
void file_arr_read(int*, int);
void file_rand_ins(int);
void file_hend_ins(int);
void arr_print(int*, int);
void push_back_arr(int*&, int&);
void push_front_arr(int*&, int&);
void delete_back_arr(int*&, int&);
void delete_front_arr(int*&, int&);
void push_k_arr(int*&, int&);
void delete_k_arr(int*&, int&);
void push_value_arr(int*&, int&);
void delete_value_arr(int*&, int&);
void get_variant(int*& arr, int& size_arr);

int main()
{
    //srand(time(NULL));
    setlocale(0, "");
    int size_arr;
    cout << "Введите первоначальный размер массива: ";
    cin >> size_arr;
    int* arr = new int[size_arr];
    get_variant(arr, size_arr);
    return 0;
}

void get_variant(int*& arr, int& size_arr)
{
    int variant, variant2;
    do
    {
        menu();
        cin >> variant;
        switch (variant)
        {
        case 1:
        {
            arr_print(arr, size_arr);
            break;
        }
        case 2:
        {
            file_rand_ins(size_arr);
            break;
        }
        case 3:
        {
            file_hend_ins(size_arr);
            break;
        }
        case 4:
        {
            file_arr_read(arr, size_arr);
            break;
        }
        case 5:
        {
            do
            {
                menu2();
                cin >> variant2;
                switch (variant2)
                {
                    case 1:
                    {
                        push_back_arr(arr, size_arr);
                        break;
                    }
                    case 2:
                    {
                        push_front_arr(arr, size_arr);
                        break;
                    }
                    case 3:
                    {
                        delete_back_arr(arr, size_arr);
                        break;
                    }
                    case 4:
                    {
                        delete_front_arr(arr, size_arr);
                        break;
                    }
                    case 5:
                    {
                        push_k_arr(arr, size_arr);
                        break;
                    }
                    case 6:
                    {
                        delete_k_arr(arr, size_arr);
                        break;
                    }
                    case 7:
                    {
                        push_value_arr(arr, size_arr);
                        break;
                    }
                    case 8:
                    {
                        delete_value_arr(arr, size_arr);
                        break;
                    }
                }
            } while (variant2 != 0);
            break;
        }
        }
    } while (variant != 0);
}

void menu()
{
    cout << "1.\tВывести массив на экран\n";
    cout << "2.\tЗаполнить файл arr.txt рандомными элементами\n";
    cout << "3.\tВручную заполнить файл arr.txt элементами\n";
    cout << "4.\tСчитать массив из файла arr.txt (файл лежит в папке с программой)\n";
    cout << "5.\tСписок заданий\n";
    cout << "0.\tВыход\n>";
}

void menu2()
{
    cout << "1.\tЗадание 1: Добавить элементы в конец массива\n";
    cout << "2.\tЗадание 2: Добавить элементы в начало массива\n";
    cout << "3.\tЗадание 3: Удалить элементы с конца массива\n";
    cout << "4.\tЗадание 4: Удалить элементы с начала массива\n";
    cout << "5.\tЗадание 5: Добавить элмемент на k индекс массива\n";
    cout << "6.\tЗадание 6: Удалить элемент с k индекса массива\n";
    cout << "7.\tЗадание 7: Добавить элемент после первого встреченого элемента со значением k\n";
    cout << "8.\tЗадание 8: Удалить все элементы массива со значением k\n";
    cout << "0.\tВыход\n>";
}

void file_rand_ins(int n) {
    fstream f_out("arr.txt", ios::out);
    if (f_out)
    {
        for (int i = 0; i < n; i++) {
            f_out << rand() % max_rand << " ";
        }
        f_out.close();
    }
    else cout << "Ошибка, файловый поток не был открыт";

}

void file_hend_ins(int n)
{
    int variant, error = 0;
    do
    {
        cout << "Ручной ввод элементов в файл (всего " << n << " штук)\nХотите продолжить (1. Да    /   2. Нет)\n>";
        cin >> variant;
        if (variant == 1)
        {
            error = 0;
            int a;
            fstream f_out("arr.txt", ios::out);
            if (f_out)
            {
                for (int i = 0; i < n; i++) {
                    cin >> a;
                    f_out << a << " ";
                }
                f_out.close();
            }
            else cout << "Ошибка, файловый поток не был открыт";
        }
        else
        {
            if (variant == 2)
            {
                error = 0;
                break;
            }
            else
            {
                error = 1;
                cout << "Выбран несуществующий вариант\nПопробуйте еще раз\n";
            }
        }
    } while (error != 0);

}

void file_arr_read(int* arr, int n) {
    fstream f_in("arr.txt", ios::in);
    if (f_in) {
        for (int i = 0; i < n; i++) {
            f_in >> arr[i];
        }
        f_in.close();
    }
    else cout << "Ошибка, файловый поток не был открыт";
}

void arr_print(int* arr, int n) {
    for (int i = 0; i < n; i++) {
        cout << "[" << setw(3) << left <<  i << "]: "; cout << setw(5) << arr[i]; /*cout << setw(6) << "\t" << arr + i;*/ cout << endl;
    }

}

void push_back_arr(int*& arr, int& n) {
    int k, error = 0;
    do
    {
        cout << "Сколько элементов массива добавить в конец массива (Указать их значение придется вручную): ";
        cin >> k;
        if (k < 0)
        {
            cout << "Ошибка, кол-во элементов не может быть отрицательным\nПопробуйте еще раз.\n";
            error = 1;
        }
        else
        {
            if (k == 0)
            {
                break;
            }
            else
            {
                error = 0;
            }
        }
    } while (error != 0);

    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i] = arr[i];
    }

    for (int i = n; i < (n + k); i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}

void push_front_arr(int*& arr, int& n)
{
    int k, error = 0;
    do
    {
        cout << "Сколько элементов массива добавить в начало массива (Указать их значение придется вручную): ";
        cin >> k;
        if (k < 0)
        {
            cout << "Ошибка, кол-во элементов не может быть отрицательным\nПопробуйте еще раз.\n";
            error = 1;
        }
        else
        {
            if (k == 0)
            {
                break;
            }
            else
            {
                error = 0;
            }
        }
    } while (error != 0);

    int* newArray = new int[n + k];
    for (int i = 0; i < n; i++)
    {
        newArray[i + k] = arr[i];
    }

    if (k > 0)
    {
        cout << "Введите добавляемые элементы, " << k << " штук: " << endl;
    }

    for (int i = 0; i < k; i++)
    {
        cin >> newArray[i];
    }
    delete[]arr;
    arr = newArray;
    n += k;
}

void delete_back_arr(int*& arr, int& n)
{
    int k, error = 0;
    do
    {
        cout << "Сколько элементов массива удалить в конце массива: ";
        cin >> k;
        if (k < 0)
        {
            cout << "Ошибка, кол-во элементов не может быть отрицательным\nПопробуйте еще раз\n";
            error = 1;
        }
        else
        {
            if (k == 0)
            {
                break;
            }
            else
            {
                if (k > n)
                {
                    cout << "Ощибка, кол-во удаляемых элементов не должно быть больше кол-ва элементов в массиве\nПопробуйте еще раз\n";
                    error = 1;
                }
                else
                {
                    error = 0;
                }

            }
        }
    } while (error != 0);

    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}

void delete_front_arr(int*& arr, int& n)
{
    int k, error = 0;
    do
    {
        cout << "Сколько элементов массива удалить в начале массива: ";
        cin >> k;
        if (k < 0)
        {
            cout << "Ошибка, кол-во элементов не может быть отрицательным\nПопробуйте еще раз\n";
            error = 1;
        }
        else
        {
            if (k == 0)
            {
                break;
            }
            else
            {
                if (k > n)
                {
                    cout << "Ощибка, кол-во удаляемых элементов не должно быть больше кол-ва элементов в массиве\nПопробуйте еще раз\n";
                    error = 1;
                }
                else
                {
                    error = 0;
                }

            }
        }
    } while (error != 0);

    int* newArray = new int[n - k];
    for (int i = 0; i < (n - k); i++)
    {
        newArray[i] = arr[i + k];
    }
    delete[]arr;
    arr = newArray;
    n -= k;

}

void push_k_arr(int*& arr, int& n)
{
    int k, error = 0;
    do
    {
        cout << "На какой индекс (от 0, до " << n - 1 << ") массива добавить элемент: ";
        cin >> k;
        if (k < 0)
        {
            cout << "Ошибка, индекс элемента массива не может быть отрицательным.\nПопробуйте еще раз.\n";
            error = 1;
        }
        else
        {
            if (k > n)
            {
                cout << "Ошибка, индекс добавляемого элемента не должен выходить за рамки массива.\nПопробуйте еще раз.\n";
                error = 1;
            }
            else
            {
                error = 0;
            }
        }
    } while (error != 0);

    k++;
    int* newArray = new int[n + 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    cout << "Введите добавляемый элемент: ";
    cin >> newArray[k - 1];
    for (int i = k; i < (n + 1); i++)
    {
        newArray[i] = arr[i - 1];
    }
    delete[]arr;
    arr = newArray;
    n++;
}

void delete_k_arr(int*& arr, int& n)
{
    int k, error = 1;
    do {
        cout << "Какой элемент (всего элементов " << n << " штук) массива удалить (введите индекс от 0, до " << n - 1 << "): ";
        cin >> k;
        if (k < 0 || k > n - 1)
        {
            cout << "Ошибка, неправильно введен индекс (от 0, до " << n - 1 << "), попробуйте еще раз" << endl; error = 1;
        }
        else
        {
            error = 0;
        }
    } while (error != 0);
    int* newArray = new int[n - 1];
    for (int i = 0; i < k; i++)
    {
        newArray[i] = arr[i];
    }
    for (int i = k; i < (n - 1); i++)
    {
        newArray[i] = arr[i + 1];
    }
    delete[]arr;
    arr = newArray;
    n--;
}

void push_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf;
    cout << "После какого какого встреченного в массиве значения добавить элемент: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf = i; break; }
    }
    if (result == 1) {
        int* newArray = new int[n + 1];
        for (int i = 0; i < (buf + 1); i++)
        {
            newArray[i] = arr[i];
        }
        cout << "Введите добавляемый элемент: ";
        cin >> newArray[buf + 1];
        for (int i = buf + 2; i < (n + 1); i++)
        {
            newArray[i] = arr[i - 1];
        }
        delete[]arr;
        arr = newArray;
        n++;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }

}

void delete_value_arr(int*& arr, int& n)
{
    int k, result = 0, buf = 0, buf2 = 0;
    cout << "Элементы с каким значением удалить: ";
    cin >> k;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k) { result = 1; buf++; }
    }
    if (result == 1)
    {
        int* newArray = new int[n - buf];
        for (int i = 0; i < n; i++)
        {
            if (arr[i] != k)
            {
                newArray[i - buf2] = arr[i];
            }
            else
            {
                buf2++;
                continue;
            }
        }
        delete[]arr;
        arr = newArray;
        n -= buf;
    }
    else
    {
        cout << "Произошла ошибка (Элемент с таким значением не найден)" << endl;
    }
}
