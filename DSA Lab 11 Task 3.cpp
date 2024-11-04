#include<iostream>
using namespace std;
int main(){
	int arr[]={21,32,13,44,25,96,47,18,29,30};
	int num;
    cout << "Enter number: ";
    cin >> num;
	bool found=false;
	for (int i = 0; i < 10; i++) {
        if (arr[i] == num) {
             found = true;
            break;
        }
    }
    if (found==false){
    	cout<<"Number Not Found"<<endl;
	}
	else
	cout<<"Number "<<num<<" Found"<<endl;
	
	return 0;
}