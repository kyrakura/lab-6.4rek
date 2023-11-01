#include <iostream>
#include <iomanip>
#include <ctime>
#include <Windows.h>
using namespace std;

const int N = 25;

void Create(int a[], const int size, const int Low, const int High, int i = 0) {
    if (i < size) {
        a[i] = Low + rand() % (High - Low + 1);
        Create(a, size, Low, High, i + 1);
    }
}

void Print(int a[], const int size, int i = 0) {
    if (i < size) {
        cout << setw(4) << a[i];
        Print(a, size, i + 1);
    }
    else {
        cout << endl;
    }
}

int MaxElement(int a[], const int size, int i = 0, int max = INT_MIN) {
    if (i == size) {
        return max;
    }
    if (a[i] > max) {
        max = a[i];
    }
    return MaxElement(a, size, i + 1, max);
}

int Sum(int a[], const int size, int i = 0, int sum = 0) {
    if (i == size) {
        return sum;
    }
    if (a[i] > 0) {
        return Sum(a, size, i + 1, 0);
    }
    sum += a[i];
    return Sum(a, size, i + 1, sum);
}

void ModArray(int a[], int& size, int aval, int bval, int i = 0, int j = 0) {
    if (i == size) {
        size = j;
        while (j < N) {
            a[j] = 0;
            j++;
        }
    }
    else {
        if (abs(a[i]) < aval || abs(a[i]) > bval) {
            a[j] = a[i];
            ModArray(a, size, aval, bval, i + 1, j + 1);
        }
        else {
            ModArray(a, size, aval, bval, i + 1, j);
        }
    }
}

int main() {
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    srand((unsigned)time(NULL));

    int n;
    cout << "Введіть розмір масиву (n): ";
    cin >> n;

    int* a = new int[n];

    int Low = -11;
    int High = 13;

    Create(a, n, Low, High);

    cout << "Початковий масив: ";
    Print(a, n);

    int maxElement = MaxElement(a, n);
    cout << "Максимальний елемент масиву: " << maxElement << endl;

    int sumBefore = Sum(a, n);
    cout << "Сума елементів до останнього додатного елементу: " << sumBefore << endl;

    int aVal, bVal;
    cout << "Введіть значення a: ";
    cin >> aVal;
    cout << "Введіть значення b: ";
    cin >> bVal;

    int newSize = n;
    ModArray(a, newSize, aVal, bVal);

    cout << "Змінений масив після стиснення: ";
    Print(a, newSize);

    return 0;
}
