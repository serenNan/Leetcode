#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int> &arr, int left, int mid,int right)
{
    int i = left, j = mid + 1,k = 0;
    vector<int> temp(right - left + 1);
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
        {
            temp[k++] = arr[i++];
        }
        else
        {
            temp[k++] = arr[j++];
        }
    }
    while (i <= mid)
    {
        temp[k++] = arr[i++];
    }
    while (j <= right)
    {
        temp[k++] = arr[j++];
    }
    for (k = 0;k < temp.size();k++)
    {
        arr[left+k] = temp[k];
    }
}

void mergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
    {
        return;
    }
    int mid = left + (right - left) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid,right);
}

int main()
{
    vector<int> arr = {1, 3, 2, 4, 5, 6, 7, 8, 9, 10};
    mergeSort(arr, 0, arr.size() - 1);
    for (const int &num : arr)
    {
        cout << num << " ";
    }
    cout << endl;
    return 0;
}