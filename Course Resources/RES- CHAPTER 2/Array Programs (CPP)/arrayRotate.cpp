#include <iostream>
using namespace std;
void leftRotateByOne(int arr[],int n);
void leftRotate(int arr[],int d,int n);
void
leftRotate (int arr[], int d, int n)
{
  for (int i = 0; i < d; ++i)
    {
      leftRotateByOne (arr, n);
    }
}

void
leftRotateByOne (int arr[], int n)
{
  int temp = arr[0];
  int i;
  for (i = 0; i < n - 1; ++i)
    {
      arr[i] = arr[i + 1];

    }
  arr[i] = temp;
}

int
main ()
{
  int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
  int n = sizeof (arr) / sizeof (arr[0]);
  leftRotate (arr, 2, n);
  for (int i = 0; i < n; ++i)
    {
      cout << arr[i];
      
    }
}