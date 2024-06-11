// created by wahyu abdil afif_23343085
#include <stdio.h>

void shellSort(int arr[], int n) 
{
  int gap = n / 2;
  while (gap > 0) 
  {
    for (int i = gap; i < n; i++) 
	{
      int temp = arr[i];
      int j = i;
      while (j >= gap && arr[j - gap] > temp) 
	  {
        arr[j] = arr[j - gap];
        j -= gap;
      }
      arr[j] = temp;
    }
    gap /= 2;
  }
}
int main() 
{
  int arr[] = {15, 21, 4, 17, 30};
  int n = sizeof(arr) / sizeof(arr[0]);
  printf("Array sebelum diurutkan: ");
  for (int i = 0; i < n; i++) 
  {
    printf("%d ", arr[i]);
  }
  shellSort(arr, n);
  printf("\nArray setelah diurutkan: ");
  for (int i = 0; i < n; i++) 
  {
    printf("%d ", arr[i]);
  }
  return 0;
}



