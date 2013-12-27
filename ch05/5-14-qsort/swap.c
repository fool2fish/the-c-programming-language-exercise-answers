void swap(char *arr[], int i, int j) {
  char *temp = arr[i];
  arr[i] = arr[j];
  arr[j] = temp;
}
