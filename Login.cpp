#include<iostream>
#include <fstream> 
#include <string>

using namespace std;
int main()
{
    homePage();
    return 0;
}

void homepage(){
    int choice;

    cout << endl;
    cout << "Main Menu: " << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Register" << endl;
    cout << "2. Login" << endl;
    cout << endl;
    cout << "Your choice: ";
    cin >> choice; 
}