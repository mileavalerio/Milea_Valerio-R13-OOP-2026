#include <iostream>
#include "NumberList.h"
void QuickSort(int v[], int left, int right);

void NumberList::Init()
{
	count = 0;
}

bool NumberList::Add(int x)
{
	if (count >= 10)
		return false;
	numbers[count] = x;
	count++;
	return true;
}

void NumberList:: Sort()
{
	if (count > 1)
		QuickSort(numbers, 0, count - 1);
}

void QuickSort(int v[], int left, int right)
{
	int i = left;
	int j = right;
	int pivot = v[(left + right) / 2];

    while (i <= j)
    {
        while (v[i] < pivot) i++;
        while (v[j] > pivot) j--;

        if (i <= j)
        {
            int temp = v[i];
            v[i] = v[j];
            v[j] = temp;
            i++;
            j--;
        }
    }
    if (left < j) QuickSort(v, left, j);
    if (right > i) QuickSort(v, i, right);
}

void NumberList::Print()
{
    for (int i = 0; i < count; i++)
        std::cout << numbers[i] << " ";
}