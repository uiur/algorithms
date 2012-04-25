#include <stdio.h>

void bubblesort(int array[], int n);
void swap(int *a, int *b);
// Test
int sorted(int array[], int n);
void assert(int t);
void showArray(int array[], int n);

int main(void) {
  int a[] = {6,3,8,3,2};

  bubblesort(a, 5);
  
  showArray(a, 5);
  assert(sorted(a, 5));

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void bubblesort(int array[], int n) {
  int i, j;

  for (i = 0; i < n - 1; i++)
    for (j = 0; j < n - 1; j++) 
      if (array[j] > array[j+1])
        swap(&array[j], &array[j+1]);

}

// Test
void assert(int t) {
  if (!t) {
    printf("Test Failed!\n");
  }
}

int sorted(int array[], int n) {
  int i;
  for (i = 0; i < n - 1; i++)
    if (array[i] > array[i+1])
      return 0;

  return 1;
}

void showArray(int array[], int n) {
  int i;

  for (i = 0; i < n - 1; i++) 
    printf("%d ", array[i]);

  printf("%d\n", array[n-1]);
}


