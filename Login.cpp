#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <windows.h> //for usleep function
using namespace std;

class Pages; // Forward declaration

class User
{
private:
    string username;
    string password;

public:
    User(const string &uname, const string &pwd)
    {
        username = uname;
        password = pwd;
    }

    string getUsername() const // Make it const
    {
        return username;
    }

    string getPassword() const // Make it const
    {
        return password;
    }

    bool checkCredentials(const string &uname, const string &pwd) const // Make it const
    {
        return (username == uname && password == pwd);
    }
};

class LoginManager
{
private:
    vector<User> users;

public:
    LoginManager(const string &filename)
    {
        ifstream fileIn(filename);
        if (!fileIn.is_open())
        {
            cerr << "Error: Unable to open file for user data." << endl;
            return;
        }
        string username, password;
        while (fileIn >> username >> password)
            users.push_back(User(username, password));

        fileIn.close();
    }

    bool authenticate(const string &uname, const string &pwd) const
    {
        for (const auto &user : users)
        {
            if (user.checkCredentials(uname, pwd))
            {
                return true;
            }
        }
        return false;
    }
};

class RegistrationManager
{
public:
    static void registerUser(const string &filename)
    {
        string username, password;
        cout << "Enter a new username: ";
        cin >> username;
        cout << "Enter a new password: ";
        cin >> password;

        ofstream fileOut(filename, ios::app);
        if (fileOut.is_open())
        {
            fileOut << username << " " << password << endl;
            fileOut.close();
            cout << "Account created successfully!\n";
        }
        else{
             cerr << "Error: Unable to open file for user data." << endl;
             return;
        }
    }
};

string getUserInput(const string &prompt)
{
    cout << prompt;
    string input;
    cin >> input;
    return input;
}

class Pages // Define Pages class before main
{
public:
    void fileLoadingPage()
    {
        ifstream in("CodeFiles/Welcome.txt"); // displaying welcome ASCII image text on output screen fn1353
        char str[1000];
        while (in)
        {
            in.getline(str, 1000); // delim defaults to '\n' cp
            if (in)   cout << str << endl;
        }
        in.close();
        Sleep(1000);
        cout << "\nStarting the program please wait....." << endl;
        Sleep(1000);
        cout << "\nloading up files....." << endl;
        Sleep(1000);
        system("cls");
    }
    // this function returns the choice of the user
    int homePage()
    {
        fileLoadingPage();
        system("color 2A");
        cout << "\n  _____________________________________________________________________\n";
        cout << "||                                                                     ||\n";
        cout << "||   \\      /\\      / |===== |      |====== /=====\\ |\\    /| |=====    ||\n";
        cout << "||    \\    /  \\    /  |_____ |      |       |     | | \\  / | |_____    ||\n";
        cout << "||     \\  /    \\  /   |      |      |       |     | |  \\/  | |         ||\n";
        cout << "||      \\/      \\/    |===== |_____ |====== \\=====/ |      | |=====    ||\n";
        cout << "||                           TO WHEEL BUDDY                            ||\n";
        cout << "||     MENU:-                                                          ||\n";
        cout << "||   1. Login                                                          ||\n";
        cout << "||   2. Create a new account                                           ||\n";
        cout << "||   3. CLOSE WHEELBUDDY                                               ||\n";
        cout << "||_____________________________________________________________________||\n";
        cout << "ENTER YOUR CHOICE: ";
        int choice;
        cin >> choice;
        cout << "\nLoading.....\n";
        Sleep(1000);
        return choice;
    }
    void thankYouPage()
    {
        cout << "\nAre you sure you want to exit? (YES/NO)---";
        string ch;
        cin >> ch;
        cin.ignore();
        if (ch == "YES" || ch == "yes" || ch == "Yes")
        {
            system("cls");
            system("color 6D");
            cout << " ________  __                            __              __      __                         __  __ \n";
            cout << "/        |/  |                          /  |            /  \\    /  |                       /  |/  |\n";
            cout << "$$$$$$$$/ $$ |____    ______   _______  $$ |   __       $$  \\  /$$/______   __    __       $$ |$$ |\n";
            cout << "   $$ |   $$      \\  /      \\ /       \\ $$ |  /  |       $$  \\/$$//      \\ /  |  /  |      $$ |$$ |\n";
            cout << "   $$ |   $$$$$$$  | $$$$$$  |$$$$$$$  |$$ |_/$$/         $$  $$//$$$$$$  |$$ |  $$ |      $$ |$$ |\n";
            cout << "   $$ |   $$ |  $$ | /    $$ |$$ |  $$ |$$   $$<           $$$$/ $$ |  $$ |$$ |  $$ |      $$/ $$/ \n";
            cout << "   $$ |   $$ |  $$ |/$$$$$$$ |$$ |  $$ |$$$$$$  \\           $$ | $$ \\__$$ |$$ \\__$$ |       __  __ \n";
            cout << "   $$ |   $$ |  $$ |$$    $$ |$$ |  $$ |$$ | $$  |          $$ | $$    $$/ $$    $$/       /  |/  |\n";
            cout << "   $$/    $$/   $$/  $$$$$$$/ $$/   $$/ $$/   $$/           $$/   $$$$$$/   $$$$$$/        $$/ $$/ \n";
            Sleep(1000);
            cout << "\n\n";
            system("color 5E");
            system("color 46");
            cout << "\nGoodbye! Have a great day!\n";
            Sleep(3000);
            system("cls");
            exit(0);
        }
    }
};

int main()
{
    string filename = "Credentials.txt";
    Pages page;
    int choice = page.homePage();
    LoginManager login(filename);
    // homePage() function returns the choice of the user
    // MENU: 1 for login and 2 for create account and 3 or any other number for exit
    string username, password;
    switch (choice)
    {
    case 1:
        cout << "Enter username: ";
        username = getUserInput("");
        cout << "Enter password: ";
        password = getUserInput("");
        if (login.authenticate(username, password))
            cout << "Login successful. Welcome, " << username << "!\n";
        else
        {
            cout << "Login failed. Incorrect username or password.\n";
            cout << "Do you want to create a new account? (yes/no): ";
            string response;
            response = getUserInput("");
            if (response == "yes")
                RegistrationManager::registerUser(filename);
        }
        break;
    case 2:
        RegistrationManager::registerUser(filename);
        cout<<"Now you will be guided to the login page.Enter your credentials there in order to LOGIN\n";
        page.homePage();
        break;
    default:
        page.thankYouPage();
    }
    return 0;
}