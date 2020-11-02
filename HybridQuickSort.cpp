#include <iostream>
using namespace std;

template <class T>
class Sorting
{
private:
    static T *Partition(T *start, T *end);

public:
    static void printArray(T *start, T *end)
    {
        int size = end - start;
        for (int i = 0; i < size - 1; i++)
            cout << start[i] << ", ";
        cout << start[size - 1];
        cout << endl;
    }

    static void insertionSort(T *start, T *end);

    static void hybridQuickSort(T *start, T *end, int min_size);
};
template <class T>
T *Sorting<T>::Partition(T *start, T *end)
{
}

template <class T>
void Sorting<T>::insertionSort(T *start, T *end)
{
     for(T* i=start+1;i<end;i++) 
    { 
      T* val = i ; 
      T* j = i ; 
    while (j>start && *(j-1)>*val) 
      { 
        *j= *(j-1) ; 
      j-= 1; 
    } 
    *j= *val ; 
    }  
}
template <class T>
void Sorting<T>::hybridQuickSort(T *start, T *end, int min_size)
{
     while (start < end-1)  
    { 
  
    // If the size of the array is less  
    // than threshold apply insertion sort  
    // and stop recursion  
  
    if (end-start < min_size) 
      { 
        insertionSort(start,end); 
      break; 
    } 
  
    else 
        
        { 
          T* pivot = Partition(start,end) ; 
  
      // Optimised quicksort which works on  
      // the smaller arrays first  
  
      // If the left side of the pivot  
      // is less than right, sort left part  
      // and move to the right part of the array  
  
      if (pivot-start<end-1-pivot) 
        { 
          hybridQuickSort(start,end);  
        start = pivot + 1; 
      } 
      else
        { 
  
        // If the right side of pivot is less  
        // than left, sort right side and  
        // move to the left side  
            
        hybridQuickSort(pivot + 1, end); 
        end = pivot; 
        } 
  
     } 
  
   } 
}
int main()
{
    int array[] = {1, 2, 6, 4, 7, 8, 5, 3};
    Sorting<int>::insertionSort(&array[0],&array[8]);
}
