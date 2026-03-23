#include <iostream>
using namespace std;

void add() {
    int a, b;
    cout << "Enter two numbers: ";
    cin >> a >> b;
    cout << a + b << endl;
}

void hello() {
    cout << "Hello\n";
}

void multiply() {
    int x, y;
    cout << "Enter two numbers: ";
    cin >> x >> y;
    cout << x * y << endl;
}

int main() {
    int choice;

    do {
        cout << "1) Hello";
        cout << "2) Add";
        cout << "3) Multiply";
        cout << "4) Exit";
        cin >> choice;

        if (choice == 1) hello();
        else if (choice == 2) add();
        else if (choice == 3) multiply();

    } while (choice != 4);

    return 0;
}
