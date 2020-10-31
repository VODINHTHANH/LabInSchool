#include <iostream>

using namespace std;


 
 template <class T>
void swap(T* &a, T* &b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
 
 template <class T>
T* Partition (T* start, T* end)
{
    int pivot = *start;    // pivot
    T* left = start+1;
    T* right = end-1;
    while(true){
        while(left <= right && *left < pivot) left++;
        while(right >= left && *right > pivot) right--;
        if (left >= right) break;
        swap(left, right);
        left++;
        right--;
    }
    swap(start, right);
    return right;
}
template <class T>
/* Hàm thực hiện giải thuật quick sort */
void QuickSort(T* start, T* end)
{ static bool x = true;
    if (start < end)
    {
        /* pi là chỉ số nơi phần tử này đã đứng đúng vị trí
         và là phần tử chia mảng làm 2 mảng con trái & phải */
        T* pi  = Partition(start, end);
       if(x==false) cout << "x";
        cout << pi - start;
        x = false;
        
        
        // Gọi đệ quy sắp xếp 2 mảng con trái và phải
        QuickSort(start, pi - 1);
        QuickSort(pi + 1, end);
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
    int array[] = { 3, 5, 7, 10 ,12, 14, 15, 13, 1, 2, 9, 6, 4, 8, 11, 16, 17, 18, 20, 19 };
    QuickSort(&array[0], &array[20]);
     int n = sizeof(array)/sizeof(array[0]);
    printArray(array, n);
    return 0;
}
