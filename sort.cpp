#include <iostream>
using namespace std;

void swap(int& a, int& b) {  // Функция для обмена значениями двух элементов
    int temp = a;
    a = b;
    b = temp;
}

// Функция для разбиения массива и возврата индекса опорного элемента
int partition(int arr[], int low, int high) {
    int pivot = arr[high];   // выбор последнего элемента в качестве опорного
    int i = (low - 1);   // индекс наименьшего элемента
    for (int j = low; j <= high - 1; j++) {  // перебираем элементы от low до high-1
        if (arr[j] < pivot) {  // если текущий элемент меньше опорного
            i++;
            swap(arr[i], arr[j]);   // меняем элементы местами
        }
    }
    swap(arr[i + 1], arr[high]);  // меняем опорный элемент с наибольшим элементом
    return (i + 1);  // возвращаем индекс опорного элемента
}

// Функция быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);  // pi - индекс опорного элемента
        quickSort(arr, low, pi - 1);  // Рекурсивно сортируем элементы перед и после опорного элемента
        quickSort(arr, pi + 1, high);
    }
}

int main() {
    int arr[] = { 10, 7, 8, 9, 1, 5 };
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << "Unsorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    quickSort(arr, 0, n - 1);   // сортировка

    cout << endl << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    return 0;
}
