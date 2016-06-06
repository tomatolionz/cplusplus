#include <iostream>

using std::cout;
using std::endl;

// 冒泡排序
void BubbleSort(int a[], int n)
{
    int lastSwap = n - 1;
    while (lastSwap)
    {
        int lastTmp = lastSwap;
        lastSwap = 0;
        for (int i = 0; i < lastTmp; ++i)
        {
            if (a[i] > a[i+1])
            {
                lastSwap = i;
                std::swap(a[i], a[i+1]);
            }
        }
    }
}

// 插入排序
void InsertSort(int *a, int n)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j > 0 && a[j-1] > a[j]; --j)
        {
            std::swap(a[j-1], a[j]);
        }
    }
}

// 选择排序
void SelectSort(int *a, int n)
{
    for (int i = 0; i < n; ++i)
    {
        int k = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[k])
            {
                k = j;
            }
        }
        std::swap(a[i], a[k]);
    }
}

// 快速排序
void QuickSort(int *a, const int start, const int end)
{
    if (start >= end)
        return;

    int front = start, rear = end;
    while (front < rear)
    {
        while (a[rear] >= a[front] && front < rear)
            --rear;
        if (front < rear)
            std::swap(a[front++], a[rear]);

        while (a[front] <= a[rear] && front < rear)
            ++front;
        if (front < rear)
            std::swap(a[front], a[rear--]);
    }

    QuickSort(a, start, front - 1);
    QuickSort(a, front + 1, end);
}

void PrintArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
}

int main ()
{
    int a[] = {3, 1, 4, 6, 1, 5, 2, 9, 2,  8, 4, 7, 5, 0};
    //int a[] = {3, 1, 6, 2, 9, 8, 4, 7, 5, 0};
    // int a[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    int n = sizeof a/sizeof(int);

    PrintArray(a, n);

    cout << endl;

    // BubbleSort(a, n);
    // InsertSort(a, n);
    // SelectSort(a, n);
    QuickSort(a, 0, n-1);

    PrintArray(a, n);

    cout << endl;

    return 0;
}