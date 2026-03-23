#include <iostream> 

using namespace std;

int main() 
{
    double balance = 0;
    double amount = 0; 
    int choice = 0; 
    bool quit = false; 

    do 
    {
        cout << "1) Deposit" << endl; 
        cout << "2) Withdraw" << endl;
        cout << "3) Print Balance" << endl;
        cout << "4) Print Balance and Quit" << endl; 
        cout << "5) Quit" << endl; 
        cout << "Enter Choice: "; 
        cin >> choice; 
        
        switch (choice)
        { 
            case 1: 
                cout << "Enter Amount:" ; 
                cin >> amount; 
                balance += amount; 
                break;
            case 2: 
                cout << "Enter Amount:"; 
                cin >> amount;
                balance -= amount; 
                break; 
            case 3: 
                cout << "Balance: " << balance << endl;
                break; 

            case 4: 
                cout << "Balance: " << balance << endl; 
                cout << "Goodbye!" << endl;
                quit = true;
                break;
            case 5: 
                cout << "Goodbye!" << endl; 
                quit = true;
                break; 
            default: 
                cout << "Invalid option entered!" << endl; 
        }

    } while (!quit);


    return 0;
}
