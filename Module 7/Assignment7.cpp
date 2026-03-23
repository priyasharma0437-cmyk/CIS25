// link to file: https://www.kaggle.com/datasets/lucalullo/global-employment-unemployment-rates-1991-2025

#include <iostream>
#include <fstream>
#include <string>
using namespace std;
// The rows 
class Record {
public:
    string iso_code;
    string country;
    string sex;
    string age;
    string year;
    string obs_value;
};

int main() {
  //reads code 
    ifstream file("disoccupazione.csv");

    string line;
    getline(file, line);
//stores the data 
    Record records[10];
// Read data from the file
    for (int i = 0; i < 10; i++) {
        getline(file, records[i].iso_code, ',');
        getline(file, records[i].country, ',');
        getline(file, records[i].sex, ',');
        getline(file, records[i].age, ',');
        getline(file, records[i].year, ',');
        getline(file, records[i].obs_value);
    }
  //Display the data 
    for (int i = 0; i < 10; i++) {
        cout << "Record " << i + 1 << endl;
        cout << "ISO Code: " << records[i].iso_code << endl;
        cout << "Country: " << records[i].country << endl;
        cout << "Sex: " << records[i].sex << endl;
        cout << "Age: " << records[i].age << endl;
        cout << "Year: " << records[i].year << endl;
        cout << "Unemployment Rate: " << records[i].obs_value << endl;
        cout << endl;
    }
// closes file
    file.close();

    return 0;
}
