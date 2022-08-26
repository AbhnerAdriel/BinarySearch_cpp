/*
  Iterative and recursive Binary Search algorithm in C++:
*/

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

// Functions Overloading:
int binarySearch(int[], int, int);  // I
int binarySearch(int[], int, int, int); // R

int main () {

  int array[] = {3, 6, 8, 13, 15, 17, 24, 27, 33, 39, 45, 49, 51, 67, 83, 99, 100};
  int size = sizeof(array) / sizeof(array[0]); 
  
  int value, pos;

  // Iterative:
  cout << "Value (iterative approach): ";
  cin >> value;

  pos = binarySearch(array, size, value);
  if (pos!= -1)
    cout << "The value was found at position " << pos << "\n";
  else
    cout << "Value not found\n";

  // Recursive:
  cout << "Value (recursive approach): ";
  cin >> value;

  pos = binarySearch(array, 0, size - 1, value);
  if (pos!= -1)
    cout << "The value was found at position " << pos << "\n";
  else
    cout << "Value not found\n";
  

  return 0;
}

// An iterative Binary Search approach:
int binarySearch(int arr[], int n, int key) {

  int left = 0;
  int right = n - 1;

  while (left <= right) {
    int middle = (left + right) / 2;
    if (key == arr[middle])
      return middle;
    else if (key > arr[middle])
      left = middle + 1;
    else
      right = middle - 1;
  }
  return -1;
}

// A recursive Binary Search approach:
int binarySearch(int arr[], int left, int right, int key) {

  if (left <= right) {
    int middle = (left +right) / 2;  
    if (key == arr[middle])
      return middle;
    else if (key > arr[middle])
      return binarySearch(arr, middle + 1, right, key);
    else
      return binarySearch(arr, left, middle - 1, key);
  }
  return -1;
}