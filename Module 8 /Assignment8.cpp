#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Patient
{
    int id;
    string name;
    int age;
    string gender;
    string diagnosis;
};

void sortPatients(Patient* patients, int count)
{
    for (int i = 0; i < count - 1; i++)
    {
        for (int j = 0; j < count - 1 - i; j++)
        {
            if (patients[j].id > patients[j + 1].id)
            {
                Patient temp = patients[j];
                patients[j] = patients[j + 1];
                patients[j + 1] = temp;
            }
        }
    }
}

int binarySearch(Patient patients[], int size, int searchID)
{
    int left = 0;
    int right = size - 1;

    while (left <= right)
    {
        int mid = (left + right) / 2;

        if (patients[mid].id == searchID)
            return mid;

        if (patients[mid].id < searchID)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return -1;
}

void addPatient(Patient* patients, int& count)
{
    cout << "Enter patient ID: ";
    cin >> patients[count].id;

    cout << "Enter patient name: ";
    cin >> patients[count].name;

    cout << "Enter patient age: ";
    cin >> patients[count].age;

    cout << "Enter patient gender: ";
    cin >> patients[count].gender;

    cout << "Enter diagnosis: ";
    cin >> patients[count].diagnosis;

    count++;

    sortPatients(patients, count);

    cout << "Patient added.\n";
}

void displayPatients(Patient* patients, int count)
{
    if (count == 0)
    {
        cout << "No patients found.\n";
        return;
    }

    for (int i = 0; i < count; i++)
    {
        cout << "\nPatient " << i + 1 << endl;
        cout << "ID: " << patients[i].id << endl;
        cout << "Name: " << patients[i].name << endl;
        cout << "Age: " << patients[i].age << endl;
        cout << "Gender: " << patients[i].gender << endl;
        cout << "Diagnosis: " << patients[i].diagnosis << endl;
    }
}

void searchPatient(Patient* patients, int count)
{
    if (count == 0)
    {
        cout << "No patients found.\n";
        return;
    }

    int searchID;
    cout << "Enter patient ID to search: ";
    cin >> searchID;

    int result = binarySearch(patients, count, searchID);

    if (result != -1)
    {
        cout << "\nPatient Found\n";
        cout << "ID: " << patients[result].id << endl;
        cout << "Name: " << patients[result].name << endl;
        cout << "Age: " << patients[result].age << endl;
        cout << "Gender: " << patients[result].gender << endl;
        cout << "Diagnosis: " << patients[result].diagnosis << endl;
    }
    else
    {
        cout << "Patient not found.\n";
    }
}

void updatePatient(Patient* patients, int count)
{
    if (count == 0)
    {
        cout << "No patients found.\n";
        return;
    }

    int updateID;
    cout << "Enter patient ID to update: ";
    cin >> updateID;

    int result = binarySearch(patients, count, updateID);

    if (result != -1)
    {
        cout << "Enter new name: ";
        cin >> patients[result].name;

        cout << "Enter new age: ";
        cin >> patients[result].age;

        cout << "Enter new gender: ";
        cin >> patients[result].gender;

        cout << "Enter new diagnosis: ";
        cin >> patients[result].diagnosis;

        cout << "Patient updated.\n";
    }
    else
    {
        cout << "Patient not found.\n";
    }
}

void savePatients(Patient* patients, int count)
{
    ofstream file("patients.txt");

    for (int i = 0; i < count; i++)
    {
        file << patients[i].id << " "
             << patients[i].name << " "
             << patients[i].age << " "
             << patients[i].gender << " "
             << patients[i].diagnosis << endl;
    }

    file.close();
    cout << "Patients saved to file.\n";
}

void loadPatients(Patient* patients, int& count)
{
    ifstream file("patients.txt");

    if (!file)
    {
        return;
    }

    while (file >> patients[count].id
                >> patients[count].name
                >> patients[count].age
                >> patients[count].gender
                >> patients[count].diagnosis)
    {
        count++;
    }

    file.close();
    sortPatients(patients, count);
}

int main()
{
    Patient* patients = new Patient[100];
    int count = 0;
    int choice;

    loadPatients(patients, count);

    do
    {
        cout << "\nHospital Patient System\n";
        cout << "1. Add Patient\n";
        cout << "2. Display Patients\n";
        cout << "3. Search Patient\n";
        cout << "4. Update Patient\n";
        cout << "5. Save Patients\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1)
            addPatient(patients, count);
        else if (choice == 2)
            displayPatients(patients, count);
        else if (choice == 3)
            searchPatient(patients, count);
        else if (choice == 4)
            updatePatient(patients, count);
        else if (choice == 5)
            savePatients(patients, count);
        else if (choice == 6)
            cout << "Good Bye!\n";
        else
            cout << "Invalid choice.\n";

    } while (choice != 6);

    delete[] patients;
    return 0;
}
