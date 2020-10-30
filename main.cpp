/******************************************************************************

                              Online C++ Compiler.
              Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>

using namespace std;


 
 
void swap(int &a, int &b)
{
    int t = a;
    a = b;
    b = t;
}
 
 
int partition (int arr[], int low, int high)
{
    int pivot = arr[low];    // pivot
    int left = low+1;
    int right = high;
    while(true){
        while(left <= right && arr[left] < pivot) left++;
        while(right >= left && arr[right] > pivot) right--;
        if (left >= right) break;
        swap(arr[left], arr[right]);
        left++;
        right--;
    }
    swap(arr[low], arr[right]);
    return right-low;
}
 
/* Hàm thực hiện giải thuật quick sort */
void quickSort(int arr[], int low, int high)
{
    if (low <= high)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        int pi  = partition(arr, low, high) + low;
        cout << pi-low;
        if(low < high) cout << " ";
        
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
 
/* Hàm xuất mảng */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
 
int main()
{
    int arr[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19};
   // 1, 2, 3, 5 ,8, 4, 6, 9, 7, 10, 13, 15, 14, 12, 11, 16, 17, 18, 20, 19
     // 1, 2, 3, 4 ,5, 8, 6, 9, 7, 10, 13, 15, 14, 12, 11, 16, 17, 18, 20, 19
    //    0  0  2     1               6
    int n = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr, 0, n-1);
    cout <<endl;
    printf("Sorted array: \n");
    printArray(arr, n);
    return 0;
}
