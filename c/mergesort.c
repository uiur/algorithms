#include <stdio.h>

void msort(int array[], int left, int right);
void merge(int array[], int left, int right);
void swap(int *a, int *b);
// Test
int sorted(int array[], int n);
void assert(int t);
void showArray(int array[], int n);

int main(void) {
  int a[] = {6,3,8,3,2,1,7};

  msort(a, 0, 6);
  
  showArray(a, 7);
  assert(sorted(a, 7));

  return 0;
}

void swap(int *a, int *b) {
  int temp = *a;
  *a = *b;
  *b = temp;
}

void msort(int array[], int left, int right) {
  if (left + 1 == right) {
    if (array[left] > array[right])
      swap(&array[left], &array[right]);
    return;
  } else if (left == right) {
    return;
  }
  msort(array, left, (left + right) / 2);
  msort(array, (left + right) / 2 + 1, right);
  merge(array, left, right);
}

void merge(int array[], int left, int right) {
  int tempArray[right - left + 1];
  int i, m = (left + right) / 2, l = left, r = m + 1;

  for (i = 0; i < right - left + 1; i++) {
    if (l > m) {
      while (r <= right) {
        tempArray[i] = array[r++];
      }
      break;
    }

    if (r > right) {
      while (l <= m) {
        tempArray[i] = array[l++];
      }
      break;
    }

    if (array[l] < array[r]) {
      tempArray[i] = array[l++];
    } else {
      tempArray[i] = array[r++];
    }
  }

  for (i = 0; i < right - left + 1; i++) {
    array[left + i] = tempArray[i];
  }
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


