#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
  int arr1[] = { 1,2,3 };
  int arr2[] = { 4,5,6,7 };
  int arr3[] = { 8,9,10 };
  int* arr = malloc((sizeof(arr1)+sizeof(arr2)+sizeof(arr3))/sizeof(int));
//  printf("\nsize:%d\n", (sizeof(arr1)+sizeof(arr2)+sizeof(arr3))/sizeof(int));
  int i, pos=0;
  const int LEN1 = sizeof(arr1) / sizeof(arr1[0]);
  const int LEN2 = sizeof(arr2) / sizeof(arr2[0]);
  const int LEN3 = sizeof(arr3) / sizeof(arr3[0]);
  const int LEN = (sizeof(arr1)+sizeof(arr2)+sizeof(arr3))/sizeof(int);

  memcpy(arr, arr1, sizeof(arr1));
  memcpy(arr + LEN1, arr2, sizeof(arr2));
  memcpy(arr + LEN1 + LEN2, arr3, sizeof(arr3));

  for(i=0;i<LEN;i++) {
    printf("arr[%d]=%d\n", i, *arr);
    arr++;
  }
  free(arr);
  return 0;
}