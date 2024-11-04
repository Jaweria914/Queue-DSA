#include <iostream>
using namespace std;
int main() {
    int tickets[10] = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
    int winningNumber;
    cout << "Enter winning number: ";
    cin >> winningNumber;
    bool isWinner = false;
    for (int i = 0; i < 10; i++) {
        if (tickets[i] == winningNumber) {
            isWinner = true;
            break;
        }
    }
    if (isWinner) {
        cout << "Congratulations! You won: " << winningNumber << endl;
    } else {
        cout << "Invalid Number." << endl;
    }
    return 0;
}