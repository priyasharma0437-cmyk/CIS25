#include <iostream>
using namespace std;

int main() {
// Missing commas 
    float n1, n2, n3;

    cout << "Enter three numbers: ";
    cin >> n1 >> n2 >> n3;
// replace == with >= 
    if (n1 >= n2 && n1 >= n3) {
        cout << "Largest number: " << n1;
    }
//Need to get if n2 is the largest not n1, we already checked that  
    if (n2 >= n1 && n2 >= n3) {
        cout << "Largest number: " << n2;
    }
// Need to get if n3 is the largest not n2, we already checked that  
    if (n3 >= n1 && n3 >= n2) {
        cout << "Largest number: " << n3;
    }

    return 0;
}
