#include <iostream>
#define MAX_SIZE 1000000
using namespace std;

int sorted[MAX_SIZE];

void merge(int* origin, int left, int mid, int right) {
  int i = left, j = mid + 1, idx = left;

  while (i <= mid && j <= right) {
    if (origin[i] <= origin[j]) {
      sorted[idx++] = origin[i++];
    } else {
      sorted[idx++] = origin[j++];
    }
  }

  while (i <= mid) {
    sorted[idx++] = origin[i++];
  }
  while (j <= right) {
    sorted[idx++] = origin[j++];
  }
  for (int k = left; k <= right; k++) {
    origin[k] = sorted[k];
  }
}

void mergeSort(int* arr, int left, int right) {
  int mid;
  if (left < right) {
    mid = (left + right) / 2;
    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
  }
  if (left == right) {
    mid = (left + right) / 2;
    merge(arr, left, mid, right);
  }
}

int main() {
  int len = 0, i;
  cin >> len;
  int* array = new int[len];
  for (i = 0; i < len; i ++) {
    cin >> array[i];
  }

  mergeSort(array, 0, len - 1);

  for (i = 0; i < len; i ++) {
    cout << array[i] << '\n';
  }

  delete[] array;

  return 0;
}