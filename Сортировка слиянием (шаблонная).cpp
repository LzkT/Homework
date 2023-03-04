#include <iostream>
#include<vector>
using namespace std;

template <typename T>
void Merge(T arr[], int start, int end)
{
    int z, x, y, mid;
    vector<T> temp(end - start + 1);
    mid = (start + end) / 2;
    z = 0;
    x = start;
    y = mid + 1;

    while (x <= mid && y <= end)
    {
        if (arr[x] < arr[y])
        {
            temp[z] = arr[x];
            ++x, ++z;
        }
        else
        {
            temp[z] = arr[y];
            ++y, ++z;
        }
    }

    while (x <= mid)
    {
        temp[z] = arr[x];
        ++x, ++z;
    }

    while (y <= end)
    {
        temp[z] = arr[y];
        ++y, ++z;
    }

    for (int i = start; i <= end; ++i)
    {
        arr[i] = temp[i - start];
    }

}

template<typename T>
void MergeSort(T arr[], int start, int end)
{

    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSort(arr, start, mid); 
        MergeSort(arr, mid + 1, end); 
        Merge(arr, start, end);   
    }

}

template<typename T>
void PrintArray(T arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n\n";
}

int main()
{

    int arr[] = { 1, 10, 10, 90, -32, 100, -1, 11, 9, 14, 3, 2, 20, 19 };
    int n = sizeof(arr) / sizeof(int);

    cout << "Array Before Sorting: " << endl;
    PrintArray(arr, n);

    MergeSort(arr, 0, n - 1);

    cout << "Array After Sorting: " << endl;
    PrintArray(arr, n);

};

