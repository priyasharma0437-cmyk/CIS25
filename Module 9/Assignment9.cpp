#include <iostream>
using namespace std;

class User {
public:
    string username;


    User(string name) {
        username = name;
    }


    virtual void accessLevel() {
        cout << "General Access" << endl;
    }
};


class Employee : public User {
public:
    Employee(string name) : User(name) {}

    void accessLevel() override {
        cout << "Employee Access: View inventory" << endl;
    }
};

class Manager : public User {
public:
    Manager(string name) : User(name) {}

    void accessLevel() override {
        cout << "Manager Access: View and update inventory" << endl;
    }
};

class Admin : public User {
public:
    Admin(string name) : User(name) {}

    void accessLevel() override {
        cout << "Admin Access: Full access (add, update, delete)" << endl;
    }
};

int main() {
    User u("User1");
    Employee e("Emp1");
    Manager m("Mgr1");
    Admin a("Admin1");

    cout << "User: ";
    u.accessLevel();

    cout << "Employee: ";
    e.accessLevel();

    cout << "Manager: ";
    m.accessLevel();

    cout << "Admin: ";
    a.accessLevel();

    return 0;
}
