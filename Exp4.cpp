#include <iostream>
#include <fstream>
using namespace std;

class student
{

    int roll_no;
    char name[30];
    float precentage;

public:
    void setdata()
    {
        cout << "Enter the roll no: ";
        cin >> roll_no;

        cout << "Enter the Name: " << endl;
        cin >> name;

        cout << "Enter the Precentage: " << endl;
        cin >> precentage;
    }

    void show_data()
    {
        cout << "The Entered name is: " << name << endl;
        cout << "The Entered roll_no is: " << roll_no << endl;
        cout << "The Entered percentage is: " << precentage << endl;
    }
};

int main()
{
    int i, n;
    student s;
    fstream f;
    f.open("abc.txt", ios::out);
    cout << "how many students data you want to enter: ";
    cin >> n;
    for (i = 0; i < n; i++)
    {
        s.setdata();
        f.write((char *)&s, sizeof s);
    }
    f.close();
    f.open("abc.txt", ios::out);
    for (i = 0; i < n; i++)
    {
        f.read((char *)&s, sizeof s);
        s.show_data();
    }
    return 0;
}