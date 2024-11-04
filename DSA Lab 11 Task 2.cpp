#include<iostream>
using namespace std;
int main() {
    int arr[] = {2, 3, 4, 10, 40};
    int n = sizeof(arr) / sizeof(arr[0]);
    int low = 0, high = n - 1, result = -1;
    int num;
    cout << "Enter number: ";
    cin >> num;
    
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == num) {
            result = mid;
            break;
        }
        if (arr[mid] > num) 
		    high = mid - 1;
        else 
	        low = mid + 1;
    }
    if (result == -1) 
	    cout << "Element found";
    else 
        cout << "Element not found " << result;
    
    return 0;
}