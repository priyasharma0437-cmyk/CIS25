#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Item {
public:
    string name;
    double price;
    int quantity;

    double getTotalPrice() {
        return price * quantity;
    }
};

void addItem() {
    Item item;

    cout << "Enter item name: ";
    cin >> item.name;

    cout << "Enter item price: ";
    cin >> item.price;

    cout << "Enter item quantity: ";
    cin >> item.quantity;

    ofstream file("cart.txt");
    file << item.name << " " << item.price << " " << item.quantity << endl;
    file.close();

    cout << "Item added\n";
}

void viewCart() {
    ifstream file("cart.txt");

    string name;
    double price;
    int quantity;

    double total = 0;

    while (file >> name >> price >> quantity) {
        cout << name << " " << price << " x " << quantity << endl;
        total += price * quantity;
    }

    cout << "Total: " << total << endl;

    file.close();
}

int main() {
    int choice;

    do {
        cout << "1. Add item\n";
        cout << "2. View checkout\n";
        cout << "3. Exit\n";
        cin >> choice;

        if (choice == 1) addItem();
        if (choice == 2) viewCart();

    } while (choice != 3);

    cout << "Thank you for shopping!\n";

    return 0;
}
