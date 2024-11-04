#include <iostream>
using namespace std;
int sum(int arr[], int n) {
    if (n <= 0) 
	   return 0;
    return arr[n - 1] + sum(arr, n - 1);
}
int main() {
    int arr[] = {1, 2, 3, 4, 5};
    int n = 5;
    
    cout << "Sum of elements in array: " << sum(arr, n);
    
    return 0;
}