// mas.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
/*4)	Дано дві послідовності, елементами яких є цілі числа.
Знайти максимальну спільну підпослідовність цих послідовностей
(елементи не обов’язково мають бути розташовані підряд).*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
int main()
{

	int max = 0; int d = 0;
	cout << "Enter amount of numbers for massive 1: " << endl;
	int n;
	cin >> n; '\n';
	int* a = new int[n];
    for (size_t i = 0; i < n; i++)
    {
        a[i] = rand() % 20;
        cout << a[i] << ' ';
    }
    cout << endl;
	cout << "Enter amount of numbers for massive 2: " << '\n';
	int m;
	cin >> m; '\n';
	int* b = new int[m];
    for (size_t i = 0; i < m; i++)
    {
        b[i] = rand() % 20;
        cout << b[i] << ' ';
    }

    size_t l = 0;

    for (size_t i = 0; i < n; i++)
    {
        size_t count = 1;

        for (size_t j = 0; j < i; j++)
        {
            if (a[j] == a[i]) ++count;
        }

        for (size_t j = 0; count != 0 && j < m; j++)
        {
            if (b[j] == a[i]) --count;
        }

        if (count == 0) ++l;
    }

    int* ab = new int[l];

    size_t s = 0;

    for (size_t i = 0; i < n; i++)
    {
        size_t count = 1;

        for (size_t j = 0; j < i; j++)
        {
            if (a[j] == a[i]) ++count;
        }

        for (size_t j = 0; count != 0 && j < m; j++)
        {
            if (b[j] == a[i]) --count;
        }

        if (count == 0) ab[s++] = a[i];
    }
    cout << endl;
    cout << "The common elements: ";

    for (size_t i = 0; i < l; i++)
    {
        cout << ab[i] << ' ';
    }
    cout << endl;

    delete[] ab;
	delete[] a;
	delete[] b;
	return 0;
}




