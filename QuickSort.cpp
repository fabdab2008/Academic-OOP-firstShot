#include <bits/stdc++.h>
using namespace std;

void swap(int *a, int *b) {
  int t = *a;
  *a = *b;
  *b = t;
}

void printArray(int array[], int size) {
  int i;
  for (i = 0; i < size; i++)
    cout << array[i] << " ";
  cout << endl;
}


int partition(int array[], int low, int high)
{
  int pivot = array[low];
  int i = low;
  int j= high;

  while(i<j) {
    while(array[i]<=pivot)
    {
        i++;
    }
    while(array[j]>pivot)
    {
        j--;
    }
    if(i<j)
        swap(&array[i],&array[j]);

  }
  swap(&array[low], &array[j]);
  return j;
}

void quickSort(int array[], int low, int high) {
  if (low < high) {
    int loc = partition(array, low, high);
    cout<<loc<<endl;
    quickSort(array, low, loc - 1);
    quickSort(array, loc +1, high);
  }
}

int main() {
  int n;
  cout<<"Enter size of array"<<endl;
  cin>>n;
  int a[n];
  for(int i=0;i<n;i++)
  {
      cin>>a[i];
  }

  cout << "Unsorted Array: \n";
  printArray(a, n);

  quickSort(a, 0, n-1);

  cout << "Sorted array in ascending order: \n";
  printArray(a, n);
}
