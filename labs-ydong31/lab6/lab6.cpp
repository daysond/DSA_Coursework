#include <cstdlib>
#include <iostream>
#include <fstream>

using namespace std;

void make_heap(int arr[], int size) {
   for (int i = 1; i < size; i++) {
   int curr = arr[i];
   int j = i;
   while (j > 0 && arr[(j-1)/2] < curr) {
      arr[j] = arr[(j-1)/2];
      j = (j-1)/2;
   }
   arr[j] = curr;
   }
}

void insertSort(int arr[],int size){
   int curr;
   int i, j;
   for(i=1;i<size;i++){
      curr=arr[i];
      for(j=i;j>0 && arr[j-1] > curr;j--){
         arr[j]=arr[j-1];
      }
      arr[j]=curr;
   }
}

/*Only modify this function*/
void insertionSortModified(int arr[],int size){
   if(size < 3){
      insertSort(arr, size);
      return;
   }
   make_heap(arr, size);
   insertSort(arr, size);
}


/*performs the insertion sort algorithm on array from index
left to index right inclusive.  You don't need to change this function*/
void insertionSortStandard(int arr[], int size){
   int curr;
   int i, j;
   for(i=1;i<size;i++){
      curr=arr[i];
      for(j=i;j>0 && arr[j-1] > curr;j--){
         arr[j]=arr[j-1];
      }
      arr[j]=curr;
   }
}

